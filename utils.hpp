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

float rand(float min, float max);

bool collide(const sf::Vector2f& destination, const sf::FloatRect& rectangle);

sf::FloatRect enlarge(const sf::Vector2f& position, const sf::Vector2f& size, float raise);

void resize(sf::Sprite& texture, sf::Vector2f size );

#endif // UTILS_HPP
