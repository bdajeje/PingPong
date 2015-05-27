#include "textures.hpp"

#include <iostream>

#include "utils.hpp"

std::unique_ptr<Textures> Textures::_instance;

void Textures::init(const std::string& path)
{
  if(_instance)
    return;

  _instance.reset( new Textures(path) );
}

Textures::Textures(const std::string& path)
{
  _textures[Texture::IconSoundOff].loadFromFile( path + "sounds_off.png" );
  _textures[Texture::IconSoundOn].loadFromFile( path + "sounds_on.png" );
}

const sf::Texture& Textures::get(Texture key) const
{
  return _textures.at(key);
}
