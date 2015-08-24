#ifndef GAME_HPP
#define GAME_HPP

#include "./GSM.hpp"
#include "./Player.hpp"

class Game {
private:
    sf::RenderWindow window_;
    GSM* gsm;
    int numFrames;
    sf::Font font;
    sf::Text fps_text;
public:
    Game();
    void run();
    void handleEvents(float);
    void update();
    void render();
};

#endif // GAME_HPP
