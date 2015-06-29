#ifndef CLOACK_HPP
#define CLOACK_HPP

#include <power_effects/power_effect.hpp>
#include "textures.hpp"

namespace power {

class Cloack : public PowerEffect
{
  public:

    Cloack();

    const sf::Texture* texture() const { return &Textures::instance()->get( Texture::PowerCloack ); }
};

}

#endif // CLOACK_HPP
