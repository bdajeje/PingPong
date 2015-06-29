#ifndef MAXIMIZE_HPP
#define MAXIMIZE_HPP

#include "power_effect.hpp"
#include "textures.hpp"

namespace power {

class Maximize final : public PowerEffect
{
  public:

    Maximize();

    const sf::Texture* texture() const { return &Textures::instance()->get( Texture::PowerMaximize ); }
};

}

#endif // MAXIMIZE_HPP
