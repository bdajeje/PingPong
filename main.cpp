#include <iostream>
#include <functional>
#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

#include "ball.hpp"
#include "constants.hpp"
#include "fonts.hpp"
#include "header.hpp"
#include "player.hpp"
#include "sounds.hpp"
#include "textures.hpp"
#include "jukebox.hpp"

Sound randomEndSound()
{
  static const std::map<short, Sound> end_sounds = {
    {0, Sound::Ends_1},
    {1, Sound::Ends_2},
    {2, Sound::Ends_3}
  };

  return end_sounds.at( rand(0, end_sounds.size() - 1) );
}

int main()
{
  sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Ping Pong Extra");
  window.setFramerateLimit(60);

  srand (static_cast <unsigned> (time(0)));

  Sounds::init("resources/sounds/");
  Textures::init("resources/textures/");
  Fonts::init("resources");

  auto player_1 = std::make_shared<Player>("Nani", Position::Left);
  auto player_2 = std::make_shared<Player>("Nana", Position::Right);
  std::vector<PlayerPtr> players = {player_1, player_2};

  Header header {player_1, player_2};
  Ball ball;

  std::map<sf::Keyboard::Key, std::function<void(bool, float)>> key_bindings = {
    {sf::Keyboard::W, std::bind( &Player::goUp, player_1.get(), std::placeholders::_1, std::placeholders::_2 )},
    {sf::Keyboard::S, std::bind( &Player::goDown, player_1.get(), std::placeholders::_1, std::placeholders::_2 )},
    {sf::Keyboard::Up, std::bind( &Player::goUp, player_2.get(), std::placeholders::_1, std::placeholders::_2 )},
    {sf::Keyboard::Down, std::bind( &Player::goDown, player_2.get(), std::placeholders::_1, std::placeholders::_2 )}
  };

  State game_state { State::Wait };
  sf::Clock clock;
  Jukebox::start("resources/musics/");

  while(window.isOpen())
  {
    // User events management
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
            if( game_state == State::Run )
            {
              game_state = State::Pause;
            }
            else if( game_state == State::Winner )
            {
              ball.reset();
              for( const auto& player : players )
                player->reset();
              game_state = State::Wait;
            }
            else if( game_state == State::Wait ||
                     game_state == State::Pause )
            {
              Sounds::instance()->play(Sound::Begin);
              game_state = State::Run;
              clock.restart();
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

    if( game_state == State::Run )
    {
      const auto elapsed_time = clock.restart().asMilliseconds();

      // Players key movements
      for( const auto& key_binding : key_bindings )
         key_binding.second( sf::Keyboard::isKeyPressed(key_binding.first), elapsed_time );

      // Update the ball
      auto winner = ball.updatePosition(elapsed_time, player_1, player_2);
      if(winner)
      {
        Sounds::instance()->play( randomEndSound() );
        winner->raiseScore();
        game_state = State::Winner;
        header.setWinner(winner);
      }
    }

    // Clear entire screen
    window.clear();

    // Draw header
    header.draw(window, game_state);

    // Draw players
    for( const auto& player : players )
      player->draw(window);

    // Draw ball
    ball.draw(window);

    // Render screen
    window.display();
  }

  return 0;
}

