#ifndef STATE_HPP
#define STATE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

const sf::Time FPS = sf::seconds(1.f/60.f);

enum DebugEnum {
    DEFAULT,
    MENU,
    PLAY
};

const DebugEnum DEBUG_MODE      = PLAY;
const int WINDOW_WIDTH          = 800;
const int WINDOW_HEIGHT         = 480;
const int DEBUG_TEXT_OFFSET     = 100;
const int DEBUG_TEXT_SIZE       = 12;
const int DEBUG_TEXT_PADDING    = 12;
const std::string GAME_TITLE    = "Platformer";
const std::string DEBUG_STR     = "State: ";


class State {
protected:
    sf::RenderWindow& window_;
    sf::Font font;
    State(sf::RenderWindow& window) :
        window_(window) {
        font.loadFromFile("./assets/arial.ttf");
    }
public:
    //virtual void loadDebugText() = 0;
    virtual int processInput(sf::Event, float) = 0;
    virtual void update() = 0;
    virtual void render() = 0;
};

#endif // STATE_HPP
