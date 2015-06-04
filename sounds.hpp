#ifndef SOUNDS_HPP
#define SOUNDS_HPP

#include <SFML/Audio.hpp>

#include <map>
#include <memory>

enum class Sound {Begin,
                  Ends_1, Ends_2, Ends_3,
                  PlayerHit};

class Sounds final
{
  public:

    static void init(const std::string& sounds_path);

    static std::unique_ptr<Sounds>& instance() { return _instance; }

    void toggleSound();
    void toggleMusic();

    bool isSoundAuthorized() const { return _is_sounds; }
    bool isMusicAuthorized() const { return _is_music; }

    void play(Sound sound);
    sf::Time play(const std::string& music_path);
    void setMusicsVolume(sf::Music& music, float volume);

  private:

    Sounds(const std::string& sounds_path);

    void loadSounds();
    void load(Sound key, const std::string& filename);

  private:

    std::string _sounds_path;
    bool _is_sounds {true};
    bool _is_music {true};
    std::map<Sound, sf::Sound> _loaded_sounds;
    std::map<Sound, sf::SoundBuffer> _buffers;
    std::map<std::string, sf::Music> _loaded_musics;

    static const std::map<Sound, std::string> _sounds_filenames;
    static std::unique_ptr<Sounds> _instance;
};

#endif // SOUNDS_HPP
