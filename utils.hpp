#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

#include <SFML/System.hpp>

/*! Takes a input string and ensure it ends with a '/'
 *  \param filepath - to update
 *  \returns returns filepath input with a '/' at the end
 */
std::string ensureDirEnd(std::string filepath);

float rand(float min, float max);

bool isColliding(const sf::Vector2f& destination, const sf::Vector2f& position, const sf::Vector2f& size);

#endif // UTILS_HPP
