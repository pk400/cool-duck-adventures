#ifndef GAME_HPP
#define GAME_HPP

#include "GSM.hpp"
#include "Settings.hpp"

class Game {
public:
    Game(Settings settings);
    int gameRun();
    void handleEvents();
    void update();
    void render();
    sf::RenderWindow& getContextWindow()    { return *window_; }
private:
    Settings gs_;
    sf::RenderWindow* window_;
    GSM* gsm_;
    float dt_;
};

#endif // GAME_HPP
