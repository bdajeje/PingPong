#include <iostream>
#include <functional>
#include <memory>
#include <vector>

#include <boost/lexical_cast.hpp>

#include <SFML/Graphics.hpp>

#include "constants.hpp"
#include "fonts.hpp"
#include "sounds.hpp"
#include "textures.hpp"
#include "game.hpp"

enum Argument {
  isSounds = 1, isMusic
};

bool isArgument(Argument argument, bool default_value, int argc, char** argv)
{
  if(argc <= argument)
    return default_value;

  return boost::lexical_cast<bool>(argv[argument]);
}

int main(int argc, char** argv)
{
  sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Ping Pong Extra");
  window.setFramerateLimit(60);

  srand (static_cast <unsigned> (time(0)));

  Sounds::init("resources/sounds/", isArgument(Argument::isSounds, true, argc, argv)
                                  , isArgument(Argument::isMusic, true, argc, argv));
  Textures::init("resources/textures/");
  Fonts::init("resources");

  Game game("nani", "nana");
  game.run(window);

  return EXIT_SUCCESS;
}

