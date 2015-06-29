#ifndef POWERBLOCK_HPP
#define POWERBLOCK_HPP

#include <memory>

#include <SFML/Graphics.hpp>

#include "power_effects/power_effect.hpp"

class PowerBlock final
{
  public:

    PowerBlock();

    void draw(sf::RenderWindow& window);

    const sf::Sprite& sprite() const { return _sprite; }

  private:

    sf::Sprite _sprite;
    std::unique_ptr<power::PowerEffect> _effect;
};

#endif // POWERBLOCK_HPP
