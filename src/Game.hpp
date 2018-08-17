#ifndef GAME_HPP
#define GAME_HPP

#include "Settings.hpp"
#include "GSM.hpp"

class Game {
public:
    Game(Settings& settings);
    int setupWindow();
    int setupGSM();
    int gameRun();
    void handleEvents();
    void update();
    void render();
    sf::RenderWindow& getContextWindow()    { return *window_; }
private:
    Settings* gs_;
    sf::RenderWindow* window_;
    GSM* gsm_;
    float dt_;
};

#endif // GAME_HPP
