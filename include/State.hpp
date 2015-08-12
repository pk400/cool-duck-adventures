#ifndef STATE_HPP
#define STATE_HPP

#include <SFML/Graphics.hpp>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 480;
const std::string GAME_TITLE = "Platformer";

const std::string DEBUG_STR = "State: ";

class State {
protected:
    sf::Font font;
    sf::Text* debug_state;
public:
    State() {
        font.loadFromFile("./assets/arial.ttf");
        debug_state = new sf::Text(DEBUG_STR, font, 12);
        debug_state->setPosition(WINDOW_WIDTH - 100, 0);
    }
    virtual void loadText() = 0;
    virtual int processInput(sf::Event) = 0;
    virtual void update() = 0;
    virtual void render(sf::RenderWindow&) = 0;
};

#endif // STATE_HPP
