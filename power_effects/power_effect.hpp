#ifndef POWEREFFECT_HPP
#define POWEREFFECT_HPP

#include <SFML/Graphics.hpp>

namespace power {

class PowerEffect
{
  public:

    PowerEffect();
    virtual ~PowerEffect() = default;

    virtual const sf::Texture* texture() const = 0;
};

}

#endif // POWEREFFECT_HPP
