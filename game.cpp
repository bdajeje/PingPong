#include "game.hpp"

#include <iostream>

#include "constants.hpp"

Game::Game(const std::string& player_1_name, const std::string& player_2_name)
  : _player_1 { std::make_shared<Player>(player_1_name, Position::Left) }
  , _player_2 { std::make_shared<Player>(player_2_name, Position::Right) }
  , _header {_player_1, _player_2}
{
  _key_bindings[sf::Keyboard::W]    = std::bind( &Player::goUp,   _player_1.get(), std::placeholders::_1, std::placeholders::_2 );
  _key_bindings[sf::Keyboard::S]    = std::bind( &Player::goDown, _player_1.get(), std::placeholders::_1, std::placeholders::_2 );
  _key_bindings[sf::Keyboard::Up]   = std::bind( &Player::goUp,   _player_2.get(), std::placeholders::_1, std::placeholders::_2 );
  _key_bindings[sf::Keyboard::Down] = std::bind( &Player::goDown, _player_2.get(), std::placeholders::_1, std::placeholders::_2 );
}

void Game::userEvent(sf::RenderWindow& window)
{
  sf::Event event;
  while(window.pollEvent(event))
  {
    switch(event.type)
    {
      case sf::Event::Closed: window.close(); break;
      case sf::Event::KeyPressed:
      {
        if( event.key.code == sf::Keyboard::Space )
        {
          if( _game_state == State::Run )
          {
            _game_state = State::Pause;
          }
          else if( _game_state == State::Winner )
          {
            _ball.reset();
            _player_1->reset();
            _player_2->reset();
            _player_last_ball_touched.reset();
            _game_state = State::Wait;
          }
          else if( _game_state == State::Wait ||
                   _game_state == State::Pause )
          {
            Sounds::instance()->play(Sound::Begin);
            _game_state = State::Run;
            _clock.restart();
          }
        }
        else if( event.key.code == sf::Keyboard::N )
          Sounds::instance()->toggleSound();
        else if( event.key.code == sf::Keyboard::M )
          Sounds::instance()->toggleMusic();
        break;
      }
      default: break;
    }
  }
}

void Game::gameUpdate()
{
  const auto elapsed_time = _clock.restart().asMilliseconds();

  // Update power block
  if( _power_block )
  {
    // Is there collision between ball and power block
    if( doesCircleCollideRectangle( _ball.sprite(), _power_block->sprite() ) )
    {
      if(_player_last_ball_touched)
      {
        _player_last_ball_touched->gainPower(_power_block);
        _power_block.reset();
        _block_next_spawn_time = rand(POWER_BLOCK_SPAWNING_TIME_MIN, POWER_BLOCK_SPAWNING_TIME_MAX);
      }
      else std::cout << "No last thrower" << std::endl;
    }
  }
  // Take care of power block only if the ball has been touched at least once
  else if( _player_last_ball_touched )
  {
    // Decrease time to get a new power block
    _block_next_spawn_time -= elapsed_time;

    // Spawn a new block
    if( _block_next_spawn_time <= 0 )
      _power_block.reset( new PowerBlock );
  }

  // Players key movements
  for( const auto& key_binding : _key_bindings )
     key_binding.second( sf::Keyboard::isKeyPressed(key_binding.first), elapsed_time );

  // Update the ball
  auto ball_interactions = _ball.updatePosition(elapsed_time, _player_1, _player_2);
  const auto& winner = std::get<0>(ball_interactions);
  if(winner)
  {
    Sounds::instance()->play( randomEndSound() );
    winner->raiseScore();
    _game_state = State::Winner;
    _header.setWinner(winner);
  }

  const auto& touched_player = std::get<1>(ball_interactions);
  if(touched_player)
    _player_last_ball_touched = touched_player;
}

Sound Game::randomEndSound()
{
  static const std::map<short, Sound> end_sounds = {
    {0, Sound::Ends_1},
    {1, Sound::Ends_2},
    {2, Sound::Ends_3}
  };

  return end_sounds.at( rand<size_t>(0, end_sounds.size() - 1) );
}

void Game::run(sf::RenderWindow& window)
{
  while(window.isOpen())
  {
    // User events management
    userEvent(window);

    // If game is running update it
    if( _game_state == State::Run )
      gameUpdate();

    // Draw everything
    draw(window);
  }
}

void Game::draw(sf::RenderWindow& window)
{
  // Clear entire screen
  window.clear();

  // Draw header
  _header.draw(window, _game_state);

  // Power block
  if(_power_block)
    _power_block->draw(window);

  // Draw players
  _player_1->draw(window);
  _player_2->draw(window);

  // Draw ball
  _ball.draw(window);

  // Render screen
  window.display();
}

