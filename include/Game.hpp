#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "./GSM.hpp"
#include "./Player.hpp"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 480;
const std::string GAME_TITLE = "Sidescroller";

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
