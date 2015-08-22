#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include "./State.hpp"

class MenuState : public State {
private:
    sf::Text* menu_start;
public:
    MenuState();
    void loadText();
    int processInput(sf::Event, float);
    void update();
    void render(sf::RenderWindow&);
};

#endif // MENUSTATE_HPP
