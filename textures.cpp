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
  _textures[Texture::IconMusicOn].loadFromFile( path + "music_on.png" );
  _textures[Texture::IconMusicOff].loadFromFile( path + "music_off.png" );
  _textures[Texture::PowerMinimize].loadFromFile( path + "power_minimize.png" );
  _textures[Texture::PowerMaximize].loadFromFile( path + "power_maximize.png" );
  _textures[Texture::PowerDouble].loadFromFile( path + "power_double.png" );
  _textures[Texture::PowerTripple].loadFromFile( path + "power_triple.png" );
  _textures[Texture::PowerCloack].loadFromFile( path + "power_cloack.png" );
}

const sf::Texture& Textures::get(Texture key) const
{
  return _textures.at(key);
}
