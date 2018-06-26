#ifndef GAME_HPP
#define GAME_HPP

#include "GSM.hpp"

class Game {
public:
    Game(int game_width, int game_height, std::string game_title);
    int gameRun();
    void handleEvents();
    void update(float dt);
    void render();
    sf::RenderWindow& getContextWindow()    { return *window; }
private:
    const int gamewidth;
    const int gameheight;
    sf::RenderWindow* window;
    GSM* gsm;
    float dt;
};

#endif // GAME_HPP
