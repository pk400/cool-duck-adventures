#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include "./State.hpp"

class MenuState : public State {
public:
    MenuState();
    void update();
    void render();
};

#endif // MENUSTATE_HPP
