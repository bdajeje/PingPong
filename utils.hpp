#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

#include <SFML/Graphics.hpp>

enum class State {Wait, Pause, Run, Winner};
enum class Edge {Top, Bottom, Left, Right, None};

/*! Takes a input string and ensure it ends with a '/'
 *  \param filepath - to update
 *  \returns returns filepath input with a '/' at the end
 */
std::string ensureDirEnd(std::string filepath);

template <class T>
T rand(T min, T max)
{
  return min + static_cast<T> (rand()) /(static_cast<T> (RAND_MAX/(max-min)));
}

bool collide(const sf::Vector2f& destination, const sf::FloatRect& rectangle);

bool doesCircleCollideRectangle(const sf::CircleShape& circle, const sf::Sprite& sprite);

sf::FloatRect enlarge(const sf::Vector2f& position, const sf::FloatRect& rectangle, float raise);
sf::FloatRect enlarge(const sf::RectangleShape& rectangle, float raise);

void resize(sf::Sprite& texture, sf::Vector2f size );

#endif // UTILS_HPP
