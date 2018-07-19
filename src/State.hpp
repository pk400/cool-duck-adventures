#ifndef STATE_HPP
#define STATE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <iomanip>
using namespace std;

const sf::Time FPS = sf::seconds(1.f/60.f);

enum DebugEnum { DEFAULT, MENU, PLAY };
const DebugEnum DEBUG_MODE = DEFAULT;
const int WINDOW_WIDTH          = 1600;
const int WINDOW_HEIGHT         = 800;

class State {
protected:
	sf::Font font;
	State() {
		font.loadFromFile("../assets/ubuntu-font-family-0.83/UbuntuMono-R.ttf");
	}
public:
    virtual int processInput(sf::Event event, sf::Vector2i mouse) = 0;
    virtual void update(float dt) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
};

#endif // STATE_HPP
