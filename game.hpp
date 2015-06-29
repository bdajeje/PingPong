#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
#include <string>

#include "ball.hpp"
#include "header.hpp"
#include "jukebox.hpp"
#include "player.hpp"
#include "sounds.hpp"
#include "power_block.hpp"

class Game final
{
  public:

    Game(const std::string& player_1_name, const std::string& player_2_name);

    void run(sf::RenderWindow& window);

  private:

    void draw(sf::RenderWindow& window);
    void userEvent(sf::RenderWindow& window);
    void gameUpdate();
    Sound randomEndSound();

  private:

    std::shared_ptr<Player> _player_1;
    std::shared_ptr<Player> _player_2;
    std::shared_ptr<Player> _player_last_ball_touched;
    Ball _ball;
    Header _header;
    std::shared_ptr<PowerBlock> _power_block;
    State _game_state { State::Wait };
    sf::Clock _clock;
    sf::Int32 _block_next_spawn_time {0};
    std::map<sf::Keyboard::Key, std::function<void(bool, float)>> _key_bindings;
};

#endif // GAME_HPP
