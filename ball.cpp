#include "ball.hpp"

#include "constants.hpp"

Ball::Ball()
  : _sprite { BALL_RADIUS }
{
  _sprite.setFillColor( sf::Color{BALL_COLOR_R, BALL_COLOR_G, BALL_COLOR_B} );
  _sprite.setPosition( WINDOW_WIDTH / 2, HEADER_HEIGHT + (WINDOW_HEIGHT - HEADER_HEIGHT) / 2 );
  _sprite.setOrigin(sf::Vector2f{ BALL_RADIUS, BALL_RADIUS });
}

void Ball::draw(sf::RenderWindow& window)
{
  window.draw( _sprite );
}
