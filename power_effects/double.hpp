#ifndef DOUBLE_HPP
#define DOUBLE_HPP

#include <power_effects/power_effect.hpp>
#include "textures.hpp"

namespace power {

class Double : public PowerEffect
{
  public:

    Double();

    const sf::Texture* texture() const { return &Textures::instance()->get( Texture::PowerDouble ); }
};

}

#endif // DOUBLE_HPP
