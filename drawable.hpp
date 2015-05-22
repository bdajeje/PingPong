#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <SFML/Graphics.hpp>

class Drawable
{
  public:

    Drawable() = default;
    virtual ~Drawable() = default;

    virtual void draw(sf::RenderWindow& window) = 0;
};

#endif // DRAWABLE_HPP
