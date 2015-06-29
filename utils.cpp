#include "utils.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>

std::string ensureDirEnd(std::string filepath)
{
  return (filepath.back() == '/') ? filepath : filepath + '/';
}

bool doesCircleCollideRectangle(const sf::CircleShape& circle, const sf::Sprite& sprite)
{
  return collide( circle.getPosition(), enlarge(sprite.getPosition(), sprite.getGlobalBounds(), circle.getRadius()) );
}

// Is a point inside a straight rectangle
bool collide(const sf::Vector2f& destination, const sf::FloatRect& rectangle)
{
  if( destination.x < rectangle.left                   ||
      destination.x > rectangle.left + rectangle.width ||
      destination.y < rectangle.top                    ||
      destination.y > rectangle.top + rectangle.height )
    return false;

  return true;
}

void resize( sf::Sprite& texture, sf::Vector2f size )
{
  sf::Vector2f scale;
  const auto& bounds = texture.getGlobalBounds();
  scale.x = (bounds.width != 0) ? size.x / bounds.width : 1.0;
  scale.y = (bounds.height != 0) ? size.y / bounds.height : 1.0;
  texture.setScale( scale );
}

sf::FloatRect enlarge(const sf::Vector2f& position, const sf::FloatRect& rectangle, float raise)
{
  return sf::FloatRect{ position.x - raise, position.y - raise,
                        rectangle.width + raise * 2, rectangle.height + raise * 2 };
}

sf::FloatRect enlarge(const sf::RectangleShape& rectangle, float raise)
{
  return enlarge( rectangle.getPosition(), rectangle.getGlobalBounds(), raise );
}
