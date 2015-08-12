#ifndef GAME_HPP
#define GAME_HPP

#include "./GSM.hpp"
#include "./Player.hpp"

class Game {
private:
    sf::RenderWindow window;
    GSM* gsm;
public:
    Game();
    void run();
    void processInput();
    void update();
    void render();
};

#endif // GAME_HPP
