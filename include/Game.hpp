#ifndef GAME_HPP
#define GAME_HPP

#include "./GSM.hpp"
#include "./Player.hpp"

class Game {
public:
    int numFrames;
    float dt;
    Game();
    int exec();
    void handleEvents();
    void update(float dt);
    void render();
    void setupDebugBox();
    sf::RenderWindow& getContextWindow() { return *window; }
private:
    sf::RenderWindow* window;
    GSM* gsm;
    sf::Font font;
    sf::Text debugBox_;
    map<string, string> lines;
};

ostream& operator<<(ostream& out, Game& game);

#endif // GAME_HPP
