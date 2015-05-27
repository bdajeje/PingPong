#include "sounds.hpp"

#include <iostream>

#include "utils.hpp"

std::unique_ptr<Sounds> Sounds::_instance;

const std::map<Sound, std::string> Sounds::_sounds_filenames = {
  { Sound::Begin, "begin.wav" },
  { Sound::Ends_1, "applause_1.wav" },
  { Sound::Ends_2, "applause_2.wav" },
  { Sound::Ends_3, "applause_3.wav" },
  { Sound::PlayerHit, "ping.wav" },
};

void Sounds::init(const std::string& path)
{
  if(_instance)
    return;

  _instance.reset( new Sounds(path) );
}

Sounds::Sounds(const std::string& path)
  : _path {ensureDirEnd(path)}
{
  loadSounds();
}

void Sounds::loadSounds()
{
  for( const auto& it : _sounds_filenames )
    load(it.first, it.second);
}

void Sounds::load(Sound key, const std::string& filename)
{
  // Try to find already loaded sound
  auto found = _loaded_sounds.find(key);
  if( found != _loaded_sounds.end() )
    return;

  // Load sound
  sf::SoundBuffer& buffer = _buffers[key];
  if(!buffer.loadFromFile( _path + filename ))
  {
    std::cerr << "Can't load sound: " << _path + filename << std::endl;
    return;
  }

  sf::Sound& sound = _loaded_sounds[key];
  sound.setBuffer(buffer);
}

void Sounds::play(Sound key)
{
  if( !_is_sounds )
    return;

  auto found = _loaded_sounds.find(key);
  if(found == _loaded_sounds.end())
    return;

  found->second.play();
}

void Sounds::toggleSound()
{
  _is_sounds = !_is_sounds;

  // Stop all sounds
  if(!_is_sounds)
  {
    for( auto& it : _loaded_sounds )
      it.second.stop();
  }
}
