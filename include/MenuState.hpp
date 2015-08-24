#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include "./State.hpp"

class MenuState : public State {
private:
    enum ButtonKeys {
        START,
        OPTIONS,
        HELP,
        EXIT
    };
    vector<sf::Text*> buttons_;
public:
    MenuState();
    void addButtons();
    int processInput(sf::Event event, float dt);
    void update();
    void render();

    // Button Manager
    bool checkButtonBoundaries(int key, sf::Vector2f mouse);
};

#endif // MENUSTATE_HPP
