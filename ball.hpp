#ifndef BALL_HPP
#define BALL_HPP

#include "drawable.hpp"

class Ball final : public Drawable
{
  public:

    Ball();

    void draw(sf::RenderWindow& window);

    inline float radius() const { return _sprite.getRadius(); }

  private:

    void updatePosition();
    void initSpeed();

  private:

    sf::Vector2f _speeds;
    sf::CircleShape _sprite;
    sf::Clock _last_move; /* Last movement time */
};

#endif // BALL_HPP
