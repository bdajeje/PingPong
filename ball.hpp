#ifndef BALL_HPP
#define BALL_HPP

#include "drawable.hpp"

class Ball final : public Drawable
{
  public:

    Ball();

    void draw(sf::RenderWindow& window);

  private:

    sf::Vector2f _speeds;
    sf::CircleShape _sprite;
};

#endif // BALL_HPP
