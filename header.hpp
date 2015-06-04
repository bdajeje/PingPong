#ifndef HEADER_HPP
#define HEADER_HPP

#include "player.hpp"
#include "utils.hpp"

class Header final
{
  public:

    Header(PlayerPtr& player_1, PlayerPtr& player_2);

    void draw(sf::RenderWindow& window, State state);

    void setWinner(const PlayerPtr& winner);

  private:

    void positionScore(sf::Text& score_text, Position position);
    void setNameStyle(sf::Text& name);
    void setScoreStyle(sf::Text& score);
    void setIcon(sf::Sprite& sprite, const sf::Texture& texture, const sf::Vector2f& size, const sf::Vector2f& position);

  private:

    PlayerPtr _player_1;
    PlayerPtr _player_2;

    sf::Text _player_name_1;
    sf::Text _player_score_1;
    sf::Text _player_name_2;
    sf::Text _player_score_2;
    sf::Text _intro_text;
    sf::Text _pause_text;
    sf::Text _winner_text;
    sf::RectangleShape _border;
    sf::Sprite _icon_sound_on;
    sf::Sprite _icon_sound_off;
    sf::Sprite _icon_music_off;
    sf::Sprite _icon_music_on;
};

#endif // HEADER_HPP
