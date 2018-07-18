#ifndef GAME_HPP
#define GAME_HPP

#include "GSM.hpp"
#include "Settings.hpp"

class Game {
public:
    Game(Settings settings);
    int gameRun();
    void handleEvents();
    void update(float dt);
    void render();
    sf::RenderWindow& getContextWindow()    { return *window; }
private:
    Settings gs;
    sf::RenderWindow* window;
    GSM* gsm;
    float dt;
};

#endif // GAME_HPP
