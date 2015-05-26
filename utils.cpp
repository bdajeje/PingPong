#include "utils.hpp"

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
//bool pointInRectangle(const sf::Vector2f& destination, const sf::Vector2f& position, const sf::Vector2f& size)
//{
//  if( destination.x < position.x          ||
//      destination.x > position.x + size.x ||
//      destination.y < position.y          ||
//      destination.y > position.y + size.y )
//    return false;

//  return true;
//}
