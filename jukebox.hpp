#ifndef JUKEBOX_HPP
#define JUKEBOX_HPP

#include <vector>
#include <memory>
#include <thread>

class Jukebox final
{
  public:

    static void start(const std::string& musics_path);

  private:

    Jukebox(const std::string& musics_path);
    void playNextMusic();

  private:

    std::string _musics_path;
    size_t _current_playing {0};
    std::vector<std::string> _music_filenames;
    std::unique_ptr<std::thread> _thread;
    static std::unique_ptr<Jukebox> _instance;
};

#endif // JUKEBOX_HPP
