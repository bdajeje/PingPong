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

    static void init(const std::string& path);

    static std::unique_ptr<Sounds>& instance() { return _instance; }

    void toggleSound();

    bool isSoundAuthorized() const { return _is_sounds; }

    void play(Sound sound);

  private:

    Sounds(const std::string& path);

    void loadSounds();
    void load(Sound key, const std::string& filename);

  private:

    std::string _path;
    bool _is_sounds {true};
    std::map<Sound, sf::Sound> _loaded_sounds;
    std::map<Sound, sf::SoundBuffer> _buffers;

    static const std::map<Sound, std::string> _sounds_filenames;
    static std::unique_ptr<Sounds> _instance;
};

#endif // SOUNDS_HPP
