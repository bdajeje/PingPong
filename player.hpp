#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

#include <memory>
#include <string>

#include "power_block.hpp"

enum class Position {Left, Right};

enum class Movement {None, Up, Down};

class Player final
{
  public:

    Player(const std::string& name, Position position);

    const std::string& name() const { return _name; }
    unsigned int score() const { return _score; }
    const sf::Vector2f& position() const { return _sprite.getPosition(); }
    const sf::Vector2f& size() const { return _sprite.getSize(); }
    sf::FloatRect bounds() const { return _sprite.getLocalBounds(); }
    const sf::RectangleShape& sprite() const { return _sprite; }

    float upperLimit() const { return position().y; }
    float lowerLimit() const { return position().y + size().y; }
    float leftLimit() const { return position().x; }
    float rightLimit() const { return position().x + size().x; }

    void raiseScore() { _score++; }
    void reset();
    void goUp(bool moving, float elapsed_time);
    void goDown(bool moving, float elapsed_time);
    void gainPower(std::shared_ptr<PowerBlock>& power_block) { _power_block = power_block; }

    void draw(sf::RenderWindow& window);

  private:

    void resetSpeed();
    void resetPosition();
    inline float height() const { return _sprite.getGlobalBounds().height; }
    void setMove(Movement direction, bool moving, float elapsed_time);

  private:

    std::string _name;
    sf::RectangleShape _sprite;
    Position _side;
    unsigned int _score {0};
    float _speed; /* Current speed */
    Movement _direction {Movement::None};

    /*! Currently owned power block by player */
    std::shared_ptr<PowerBlock> _power_block;
};

typedef std::shared_ptr<Player> PlayerPtr;

#endif // PLAYER_HPP
