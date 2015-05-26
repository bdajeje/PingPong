#include "ball.hpp"

#include "constants.hpp"
#include "utils.hpp"

Ball::Ball()
  : _sprite { BALL_RADIUS }
{
  _sprite.setFillColor( sf::Color{BALL_COLOR_R, BALL_COLOR_G, BALL_COLOR_B} );
  _sprite.setPosition( WINDOW_WIDTH / 2, HEADER_HEIGHT + (WINDOW_HEIGHT - HEADER_HEIGHT) / 2 );
  _sprite.setOrigin(sf::Vector2f{ BALL_RADIUS, BALL_RADIUS });

  initSpeed();
}

void Ball::draw(sf::RenderWindow& window)
{
  updatePosition();
  window.draw( _sprite );
}

void Ball::initSpeed()
{
  _speeds.x = rand(-BALL_DEFAULT_SPEED, BALL_DEFAULT_SPEED) + rand(-BALL_RANDOM_START_SPEED, BALL_RANDOM_START_SPEED);
  _speeds.y = rand(-BALL_DEFAULT_SPEED, BALL_DEFAULT_SPEED) + rand(-BALL_RANDOM_START_SPEED, BALL_RANDOM_START_SPEED);
}

void Ball::updatePosition()
{
  const auto& position = _sprite.getPosition();
  const auto elapsed_time = _last_move.restart().asMilliseconds();
  auto distance_x = _speeds.x * elapsed_time;
  auto distance_y = _speeds.y * elapsed_time;
  auto future_x = position.x + distance_x;
  auto future_y = position.y + distance_y;

  if( future_x < radius() )
  {
    _speeds.x = -_speeds.x;
    future_x = radius();
  }
  else if( future_x + radius() > WINDOW_WIDTH )
  {
    _speeds.x = -_speeds.x;
    future_x = WINDOW_WIDTH - radius();
  }

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

  _sprite.setPosition(future_x, future_y);
}
