#ifndef PLAYSTATE_HPP
#define PLAYSTATE_HPP

#include "./State.hpp"
#include "./Player.hpp"

class PlayState : public State {
private:
    Player* player;
    sf::Text* debug_input;
public:
    PlayState();
    void loadDebugText();
    int processInput(sf::Event event, sf::Vector2i mouse, float dt);
    void update();
    void render(sf::RenderWindow& window);
};

#endif // PLAYSTATE_HPP
