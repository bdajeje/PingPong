#include <iostream>
#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

#include "ball.hpp"
#include "constants.hpp"
#include "fonts.hpp"
#include "header.hpp"
#include "player.hpp"

int main()
{
  sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Ping Pong Extra");
  window.setFramerateLimit(60);

  Fonts::init("resources");

  auto player_1 = std::make_shared<Player>("Nani", Position::Left);
  auto player_2 = std::make_shared<Player>("Nana", Position::Right);
  std::vector<PlayerPtr> players = {player_1, player_2};

  Header header {player_1, player_2};
  Ball ball;

  while(window.isOpen())
  {
    // User events management
    sf::Event event;
    while(window.pollEvent(event))
    {
      switch(event.type)
      {
        case sf::Event::Closed: window.close(); break;
        case sf::Event::KeyPressed:
        {

          break;
        }
        default: break;
      }
    }

    // Clear entire screen
    window.clear();

    // Draw header
    header.draw(window);

    // Draw players
    for( const auto& player : players )
      player->draw(window);

    // Draw ball
    ball.draw(window);

    // Render screen
    window.display();
  }

  return 0;
}

