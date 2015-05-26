#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <memory>
#include <string>

#include "drawable.hpp"

enum class Position {Left, Right};

enum class Movement {None, Up, Down};

class Player final : public Drawable
{
  public:

    Player(const std::string& name, Position position);

    const std::string& name() const { return _name; }
    unsigned int score() const { return _score; }

    void resetPosition(Position position);
    void resetSpeed();
    void raiseScore() { _score++; }

    void goUp(bool moving);
    void goDown(bool moving);

    void draw(sf::RenderWindow& window);

  private:

    inline float height() const { return _sprite.getGlobalBounds().height; }
    void setMove(Movement direction, bool moving);

  private:

    std::string _name;
    sf::RectangleShape _sprite;
    unsigned int _score {0};
    sf::Clock _last_move; /* Last movement time */
    float _speed; /* Current speed */
    Movement _direction {Movement::None};
};

typedef std::shared_ptr<Player> PlayerPtr;

#endif // PLAYER_HPP
