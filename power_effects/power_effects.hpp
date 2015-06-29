#ifndef POWER_EFFECTS_HPP
#define POWER_EFFECTS_HPP

#include <vector>

#include "power_effects/minimize.hpp"
#include "power_effects/maximize.hpp"

namespace power {

static const std::vector<PowerEffect*> PowerTypes = {
  new Minimize,
  new Maximize
};

}

#endif // POWER_EFFECTS_HPP
