#ifndef TEXTURES_HPP
#define TEXTURES_HPP

#include <map>
#include <memory>
#include <string>

#include <SFML/Graphics.hpp>

enum class Texture {
  IconSoundOn, IconSoundOff,
  IconMusicOn, IconMusicOff
};

class Textures final
{
  public:

    static void init(const std::string& path);

    static std::unique_ptr<Textures>& instance() { return _instance; }

    const sf::Texture& get(Texture key) const;

  private:

    Textures(const std::string& path);
    sf::Texture* load( Texture texture );

  private:

    std::map<Texture, sf::Texture> _textures;
    static std::unique_ptr<Textures> _instance;
};

#endif // TEXTURES_HPP
