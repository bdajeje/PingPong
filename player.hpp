#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <memory>
#include <string>

#include "drawable.hpp"

enum class Position {Left, Right};

class Player final : public Drawable
{
  public:

    Player(const std::string& name, Position position);

    const std::string& name() const { return _name; }
    unsigned int score() const { return _score; }

    void resetPosition(Position position);
    void raiseScore() { _score++; }

    void draw(sf::RenderWindow& window);

  private:

    std::string _name;
    sf::RectangleShape _sprite;
    unsigned int _score {0};
};

typedef std::shared_ptr<Player> PlayerPtr;

#endif // PLAYER_HPP
