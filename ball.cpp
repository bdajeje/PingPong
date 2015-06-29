#include "ball.hpp"

#include <iostream>

#include "constants.hpp"
#include "sounds.hpp"

Ball::Ball()
  : _sprite { BALL_RADIUS }
{
  reset();
}

void Ball::draw(sf::RenderWindow& window)
{
  window.draw( _sprite );
}

void Ball::initSpeed()
{
  _speeds.x = rand(-BALL_DEFAULT_SPEED, BALL_DEFAULT_SPEED) + rand(-BALL_RANDOM_START_SPEED, BALL_RANDOM_START_SPEED);
  _speeds.y = rand(-BALL_DEFAULT_SPEED, BALL_DEFAULT_SPEED) + rand(-BALL_RANDOM_START_SPEED, BALL_RANDOM_START_SPEED);
}

std::pair<PlayerPtr,PlayerPtr> Ball::updatePosition(float elapsed_time, const PlayerPtr& player_1, const PlayerPtr& player_2)
{
  auto distance_x = _speeds.x * elapsed_time;
  auto distance_y = _speeds.y * elapsed_time;
  auto future_x = position().x + distance_x;
  auto future_y = position().y + distance_y;

  // Check collision with vertical borders
  PlayerPtr winner;
  if( future_x < radius() )
    winner = player_2;
  else if( future_x + radius() > WINDOW_WIDTH )
    winner = player_1;

  PlayerPtr touched_player;
  if(!winner)
  {
    // Check collision with horizontal borders
    if( future_y < HEADER_HEIGHT + radius() )
    {
      _speeds.y = -_speeds.y;
      future_y = HEADER_HEIGHT + radius();
    }
    else if( future_y + radius() > WINDOW_HEIGHT )
    {
      _speeds.y = -_speeds.y;
      future_y = WINDOW_HEIGHT - radius();
    }

    // Set new position
    _sprite.setPosition(future_x, future_y);

    // Check collision with players
    if( playerCollide( player_1, player_1->rightLimit() + radius() ) )
      touched_player = player_1;
    else if(playerCollide( player_2, player_2->leftLimit() - radius() ))
      touched_player = player_2;
  }

  return std::make_pair(winner, touched_player);
}

bool Ball::playerCollide(const PlayerPtr& player, float reset_x)
{
  if( collide(position(), enlarge(player->sprite(), radius())) )
  {
    float new_x = position().x;
    float new_y = position().y;

    // \todo Collision with upper or lower edge
//    if( std::abs(player->upperLimit() - position().y) < radius() )
//    {
//      _speeds.y = -_speeds.y;
//      new_y = player->upperLimit() - radius();
//    }
//    // Check if ONLY lower edge have been touched
//    else if( std::abs(player->lowerLimit() - position().y) < radius() )
//    {
//      _speeds.y = -_speeds.y;
//      new_y = player->lowerLimit() + radius();
//    }
//    else // Invert X speed
    {
      _speeds.x = -_speeds.x;
      new_x = reset_x;
    }

    _sprite.setPosition( new_x, new_y );
    Sounds::instance()->play(Sound::PlayerHit);
    return true;
  }

  return false;
}

void Ball::reset()
{
  _sprite.setFillColor( sf::Color{BALL_COLOR_R, BALL_COLOR_G, BALL_COLOR_B} );
  _sprite.setPosition( WINDOW_WIDTH / 2, HEADER_HEIGHT + (WINDOW_HEIGHT - HEADER_HEIGHT) / 2 );
  _sprite.setOrigin(sf::Vector2f{ BALL_RADIUS, BALL_RADIUS });

  initSpeed();
}
