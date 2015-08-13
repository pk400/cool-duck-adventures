#ifndef PLAYSTATE_HPP
#define PLAYSTATE_HPP

#include "./State.hpp"
#include "./Player.hpp"

class PlayState : public State {
private:
    Player* player;
    sf::Text* debug_state;
    sf::Text* debug_input;
public:
    PlayState();
    void loadText();
    int processInput(sf::Event);
    void update();
    void render(sf::RenderWindow&);
};

#endif // PLAYSTATE_HPP
