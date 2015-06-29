#include "jukebox.hpp"

#include <iostream>

#include "files.hpp"
#include "sounds.hpp"

std::unique_ptr<Jukebox> Jukebox::_instance;

Jukebox::Jukebox(const std::string& musics_path)
  : _music_filenames {utils::files::listFilesInDir(musics_path, ".*\\.ogg")}
{
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(_music_filenames.begin(), _music_filenames.end(), g);
}

void Jukebox::start(const std::string& musics_path)
{
  if(!_instance)
    _instance.reset(new Jukebox(musics_path));

  _instance->_thread.reset( new std::thread(std::bind(&Jukebox::playNextMusic, _instance.get())) );
}

void Jukebox::playNextMusic()
{
  if( _music_filenames.empty() )
  {
    std::cout << "No music to play" << std::endl;
    return;
  }

  _current_playing++;
  if( _current_playing >= _music_filenames.size() )
    _current_playing = 0;

  sf::Time duration = Sounds::instance()->play(_music_filenames[_current_playing]);
  if(duration == sf::Time::Zero)
    return;

  std::this_thread::sleep_for(std::chrono::microseconds(duration.asMicroseconds()));
  playNextMusic();
}
