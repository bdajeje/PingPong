#ifndef HEADER_HPP
#define HEADER_HPP

#include "drawable.hpp"
#include "player.hpp"

class Header final : public Drawable
{
  public:

    Header(PlayerPtr& player_1, PlayerPtr& player_2);

    void draw(sf::RenderWindow& window);

  private:

    void positionScore(sf::Text& score_text, Position position);
    void setNameStyle(sf::Text& name);
    void setScoreStyle(sf::Text& score);

  private:

    PlayerPtr _player_1;
    PlayerPtr _player_2;

    sf::Text _player_name_1;
    sf::Text _player_score_1;
    sf::Text _player_name_2;
    sf::Text _player_score_2;
    sf::RectangleShape _border;
};

#endif // HEADER_HPP
