#include "header.hpp"

#include "constants.hpp"
#include "fonts.hpp"

Header::Header(PlayerPtr& player_1, PlayerPtr& player_2)
  : _player_1 {player_1}
  , _player_2 {player_2}
  , _border { sf::Vector2f{WINDOW_WIDTH, HEADER_BORDER_HEIGHT} }
{
  // Border
  _border.setPosition( sf::Vector2f{0, HEADER_HEIGHT - _border.getSize().y} );
  _border.setFillColor(sf::Color{HEADER_BORDER_COLOR_R ,HEADER_BORDER_COLOR_G, HEADER_BORDER_COLOR_B});

  // Set player names
  _player_name_1.setString( player_1->name() );
  _player_name_2.setString( player_2->name() );
  setNameStyle(_player_name_1);
  setNameStyle(_player_name_2);

  // Scores
  setScoreStyle(_player_score_1);
  setScoreStyle(_player_score_2);

  // Position names
  const float names_y = (_border.getPosition().y / 4) + _player_name_1.getGlobalBounds().height / 2;
  _player_name_1.setPosition( WINDOW_WIDTH / 4 - _player_name_1.getGlobalBounds().width / 2, names_y );
  _player_name_2.setPosition( ((WINDOW_WIDTH / 4) * 3) - _player_name_2.getGlobalBounds().width / 2, names_y );

  // Position scores
  positionScore(_player_score_1, Position::Left);
  positionScore(_player_score_2, Position::Right);
}

void Header::draw(sf::RenderWindow& window)
{
  // Border
  window.draw( _border );

  // Names
  window.draw( _player_name_1 );
  window.draw( _player_name_2 );

  // Scores
  _player_score_1.setString( std::to_string(_player_1->score()) );
  _player_score_2.setString( std::to_string(_player_2->score()) );
  window.draw( _player_score_1 );
  window.draw( _player_score_2 );
}

void Header::positionScore(sf::Text& score_text, Position position)
{
  int x_multiplicator = (position == Position::Left) ? 1 : 3;

  score_text.setPosition(
    (WINDOW_WIDTH / 4) * x_multiplicator + score_text.getGlobalBounds().width / 2,
    ((HEADER_HEIGHT - _border.getGlobalBounds().height) / 4) * 3 + score_text.getGlobalBounds().height / 2
  );
}

void Header::setNameStyle(sf::Text& name)
{
  name.setFont( *Fonts::get(fonts::Default) );
  name.setCharacterSize( HEADER_NAME_SIZE );
  name.setColor( sf::Color{HEADER_NAME_COLOR_R, HEADER_NAME_COLOR_G, HEADER_NAME_COLOR_B} );
}

void Header::setScoreStyle(sf::Text& score)
{
  score.setFont( *Fonts::get(fonts::Default) );
  score.setCharacterSize( HEADER_SCORE_SIZE );
  score.setColor( sf::Color{HEADER_SCORE_COLOR_R, HEADER_SCORE_COLOR_G, HEADER_SCORE_COLOR_B} );
}
