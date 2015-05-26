#include <iostream>
#include <functional>
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

  srand (static_cast <unsigned> (time(0)));

  Fonts::init("resources");

  auto player_1 = std::make_shared<Player>("Nani", Position::Left);
  auto player_2 = std::make_shared<Player>("Nana", Position::Right);
  std::vector<PlayerPtr> players = {player_1, player_2};

  Header header {player_1, player_2};
  Ball ball;

  std::map<sf::Keyboard::Key, std::function<void(bool)>> key_bindings = {
    {sf::Keyboard::W, std::bind( &Player::goUp, player_1.get(), std::placeholders::_1 )},
    {sf::Keyboard::S, std::bind( &Player::goDown, player_1.get(), std::placeholders::_1 )},
    {sf::Keyboard::Up, std::bind( &Player::goUp, player_2.get(), std::placeholders::_1 )},
    {sf::Keyboard::Down, std::bind( &Player::goDown, player_2.get(), std::placeholders::_1 )}
  };

  while(window.isOpen())
  {
    // User events management
    sf::Event event;
    while(window.pollEvent(event))
    {
      switch(event.type)
      {
        case sf::Event::Closed: window.close(); break;
        default: break;
      }
    }

    // Players key movements
    for( const auto& key_binding : key_bindings )
       key_binding.second( sf::Keyboard::isKeyPressed(key_binding.first) );

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

