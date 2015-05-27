#include "player.hpp"

#include <iostream>

#include "constants.hpp"

Player::Player(const std::string& name, Position side)
  : _name {name}
  , _sprite {sf::Vector2f(PLAYER_DEFAULT_WIDTH, PLAYER_DEFAULT_HEIGHT)}
  , _side {side}
{
  reset();
}

void Player::reset()
{
  resetPosition();
  resetSpeed();
}

void Player::resetPosition()
{
  static const float honrizontal_padding = 40;
  _sprite.setPosition( ( _side == Position::Left ) ? honrizontal_padding : WINDOW_WIDTH - honrizontal_padding - _sprite.getSize().x,
                       HEADER_HEIGHT + ((WINDOW_HEIGHT - HEADER_HEIGHT) - _sprite.getSize().y) / 2 );
}

void Player::resetSpeed()
{
  _speed = PLAYER_DEFAULT_SPEED;
}

void Player::draw(sf::RenderWindow& window)
{
  window.draw(_sprite);
}

void Player::goUp(bool moving, float elapsed_time)
{
  setMove(Movement::Up, moving, elapsed_time);
}

void Player::goDown(bool moving, float elapsed_time)
{
  setMove(Movement::Down, moving, elapsed_time);
}

void Player::setMove(Movement direction, bool moving, float elapsed_time)
{
  if( !moving )
  {
    if(_direction == direction)
      _direction = Movement::None;
    return;
  }
  else if( _direction != direction )
  {
    _direction = direction;
    return;
  }

  // Get current position
  const auto& position = _sprite.getPosition();

  // Calcule distance done since last move
  auto distance = _speed * elapsed_time;
  if(direction == Movement::Up)
    distance = -distance;

  // Check bounds to get future position
  const float boundary = (direction == Movement::Up) ? HEADER_HEIGHT : WINDOW_HEIGHT - height();
  float future_position = position.y + distance;
  if( (direction == Movement::Up && future_position < boundary) ||
      (direction == Movement::Down && future_position > boundary) )
    future_position = boundary;

  // Set new position
  _sprite.setPosition(position.x, future_position);
}

