#ifndef PLAYSTATE_HPP
#define PLAYSTATE_HPP

#include "./State.hpp"
#include "./Player.hpp"

class PlayState : public State {
private:
    Player* player;
    sf::Text* debug_input;
public:
    PlayState(sf::RenderWindow& window);
    void loadDebugText();
    int processInput(sf::Event, float);
    void update();
    void render();
};

#endif // PLAYSTATE_HPP
