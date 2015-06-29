#include "power_block.hpp"

#include "constants.hpp"
#include "utils.hpp"
#include "textures.hpp"
#include "power_effects/maximize.hpp"
#include "power_effects/minimize.hpp"
#include "power_effects/double.hpp"
#include "power_effects/triple.hpp"
#include "power_effects/cloack.hpp"

PowerBlock::PowerBlock()
{
  // Randomly choose an power effect
  switch( rand(0, NBR_EFFECTS - 1) )
  {
    case 0: _effect.reset( new power::Maximize ); break;
    case 1: _effect.reset( new power::Minimize ); break;
    case 2: _effect.reset( new power::Double ); break;
    case 3: _effect.reset( new power::Triple ); break;
    case 4: _effect.reset( new power::Cloack ); break;
  }

  // Set a position
  _sprite.setPosition( rand( POWER_BLOCK_MIN_X, POWER_BLOCK_MAX_X ),
                       rand( POWER_BLOCK_MIN_Y, POWER_BLOCK_MAX_Y ));

  _sprite.setTexture( *(_effect->texture()) );
  resize( _sprite, sf::Vector2f{POWER_BLOCK_WIDTH, POWER_BLOCK_HEIGHT} );
}

void PowerBlock::draw(sf::RenderWindow& window)
{
  window.draw(_sprite);
}

