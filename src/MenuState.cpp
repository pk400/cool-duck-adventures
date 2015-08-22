#include "../include/Game.hpp"
#include "../include/MenuState.hpp"

MenuState::MenuState() {
    loadText();
}

void MenuState::loadText() {
    debug_state->setString(DEBUG_STR + "Menu State");

    menu_start = new sf::Text("START", font, 30);
    menu_start->setOrigin(menu_start->getLocalBounds().width / 2, menu_start->getLocalBounds().height / 2);
    menu_start->setPosition(WINDOW_WIDTH / 2, (WINDOW_HEIGHT / 2) - (menu_start->getLocalBounds().height));
}

int MenuState::processInput(sf::Event event, float dt) {
    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        int mouse_x = event.mouseButton.x;
        int mouse_y = event.mouseButton.y;

        if(mouse_x > menu_start->getGlobalBounds().left && mouse_x < menu_start->getGlobalBounds().left + menu_start->getLocalBounds().width &&
           mouse_y > menu_start->getGlobalBounds().top && mouse_y < menu_start->getGlobalBounds().top + menu_start->getLocalBounds().height) {
            return 1;
        }
    }

    return 0;
}

void MenuState::update() {}

void MenuState::render(sf::RenderWindow& win) {
    win.draw(*debug_state);
    win.draw(*menu_start);
}

