#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 480;
const std::string GAME_TITLE = "Sidescroller";

class Game {
private:
    sf::RenderWindow window;
    sf::Texture player_tex;
    sf::Sprite player_spr;
public:
    Game();
    void loop();
    void processInput();
    void update();
    void render();
};

#endif // GAME_HPP
