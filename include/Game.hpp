#ifndef GAME_HPP
#define GAME_HPP

#include "./GSM.hpp"
#include "./Player.hpp"

class Game {
private:
    sf::RenderWindow window_;
    GSM* gsm;
    sf::Font font;
    sf::Text debugBox_;
public:
    int numFrames;
    float dt;
    Game();
    void run();
    void handleEvents();
    void update(float dt);
    void render();
    sf::RenderWindow& getContextWindow() { return window_; }
};

ostream& operator<<(ostream& out, Game& game);

#endif // GAME_HPP
