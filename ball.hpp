#ifndef BALL_HPP
#define BALL_HPP

#include "player.hpp"
#include "utils.hpp"

class Ball final
{
  public:

    Ball();

    void draw(sf::RenderWindow& window);

    /*!
     * \returns first player : winner or nullptr
     *          second player: touched player or nullptr
     */
    std::pair<PlayerPtr,PlayerPtr> updatePosition(float elapsed_time, const PlayerPtr& player_1, const PlayerPtr& player_2);

    inline float radius() const { return _sprite.getRadius(); }
    const sf::Vector2f& position() const { return _sprite.getPosition(); }
    const sf::CircleShape& sprite() const { return _sprite; }

    float upperLimit() const { return position().y - radius(); }
    float lowerLimit() const { return position().y + radius(); }
    float leftLimit() const { return position().x - radius(); }
    float rightLimit() const { return position().x + radius(); }

    void reset();

  private:

    void initSpeed();
    bool playerCollide(const PlayerPtr& player, float reset_x);

  private:

    sf::Vector2f _speeds;
    sf::CircleShape _sprite;
};

#endif // BALL_HPP
