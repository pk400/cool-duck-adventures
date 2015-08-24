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
    int processInput(sf::Event event, sf::Vector2i mouse, float dt);
    void update();
    void render(sf::RenderWindow& window);

    // Button Manager
    bool checkButtonBoundaries(int key, sf::Vector2f mouse);
    void onMouseHover(int key, sf::Vector2f mouse);
};

#endif // MENUSTATE_HPP
