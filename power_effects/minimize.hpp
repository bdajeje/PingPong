#ifndef MINIMIZE_HPP
#define MINIMIZE_HPP

#include "power_effect.hpp"
#include "textures.hpp"

namespace power {

class Minimize : public PowerEffect
{
  public:

    Minimize();

    const sf::Texture* texture() const { return &Textures::instance()->get( Texture::PowerMinimize ); }
};

}

#endif // MINIMIZE_HPP
