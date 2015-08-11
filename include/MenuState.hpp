#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include <SFML/Graphics.hpp>
#include "./State.hpp"

class MenuState : public State {
private:
    sf::Font font;
    sf::Text game_title;
public:
    MenuState();
    void update();
    void render();
};

#endif // MENUSTATE_HPP
