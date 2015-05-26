#include "player.hpp"

#include <iostream>

#include "constants.hpp"

Player::Player(const std::string& name, Position position)
  : _name {name}
  , _sprite {sf::Vector2f(PLAYER_DEFAULT_WIDTH, PLAYER_DEFAULT_HEIGHT)}
{
  resetPosition(position);
  resetSpeed();
}

void Player::resetPosition(Position position)
{
  static const float honrizontal_padding = 40;
  _sprite.setPosition( ( position == Position::Left ) ? honrizontal_padding : WINDOW_WIDTH - honrizontal_padding - _sprite.getSize().x,
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

void Player::goUp(bool moving)
{
  setMove(Movement::Up, moving);
}

void Player::goDown(bool moving)
{
  setMove(Movement::Down, moving);
}

void Player::setMove(Movement direction, bool moving)
{
  if( !moving )
  {
    if(_direction == direction)
      _direction = Movement::None;
    return;
  }
  else if( _direction != direction )
  {
    _last_move.restart();
    _direction = direction;
    return;
  }

  // Get current position
  const auto& position = _sprite.getPosition();

  // Calcule distance done since last move
  auto distance = _speed * _last_move.restart().asMilliseconds();
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

