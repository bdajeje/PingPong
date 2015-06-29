#ifndef TRIPLE_HPP
#define TRIPLE_HPP

#include <power_effects/power_effect.hpp>
#include "textures.hpp"

namespace power {

class Triple : public PowerEffect
{
  public:

    Triple();

    const sf::Texture* texture() const { return &Textures::instance()->get( Texture::PowerTripple ); }
};

}

#endif // TRIPLE_HPP
