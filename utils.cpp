#include "utils.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>

std::string ensureDirEnd(std::string filepath)
{
  return (filepath.back() == '/') ? filepath : filepath + '/';
}

float rand(float min, float max)
{
  return min + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(max-min)));
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

sf::FloatRect enlarge(const sf::Vector2f& position, const sf::Vector2f& size, float raise)
{
  return sf::FloatRect{ position.x - raise, position.y - raise,
                        size.x + raise * 2, size.y + raise * 2 };
}
