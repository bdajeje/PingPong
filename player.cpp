#include "player.hpp"

#include "constants.hpp"

Player::Player(const std::string& name, Position position)
  : _name {name}
  , _sprite {sf::Vector2f(PLAYER_DEFAULT_WIDTH, PLAYER_DEFAULT_HEIGHT)}
{
  resetPosition(position);
}

void Player::resetPosition(Position position)
{
  static const float honrizontal_padding = 40;
  _sprite.setPosition( ( position == Position::Left ) ? honrizontal_padding : WINDOW_WIDTH - honrizontal_padding - _sprite.getSize().x,
                       HEADER_HEIGHT + ((WINDOW_HEIGHT - HEADER_HEIGHT) - _sprite.getSize().y) / 2 );
}

void Player::draw(sf::RenderWindow& window)
{
  window.draw(_sprite);
}
