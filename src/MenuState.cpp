#include "../include/Game.hpp"
#include "../include/MenuState.hpp"

MenuState::MenuState() {
    addButtons();
}

void MenuState::addButtons() {
    int inc = 0;

    buttons_.push_back(new sf::Text("START"   , font, 30));
    buttons_.push_back(new sf::Text("Options" , font, 30));
    buttons_.push_back(new sf::Text("Help"    , font, 30));
    buttons_.push_back(new sf::Text("Exit"    , font, 30));

    sf::Vector2f pos(5.f, 5.f);
    for(auto btn : buttons_) {
        btn->setPosition(pos);
        pos.y += 40.f;
    }
}

int MenuState::processInput(sf::Event event, float dt) {
    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        if(checkButtonBoundaries(START, sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) return 1;
        if(checkButtonBoundaries(OPTIONS, sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) return 1;
        if(checkButtonBoundaries(HELP, sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) return 1;
        if(checkButtonBoundaries(EXIT, sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) return 1;
    }

    return 0;
}

void MenuState::update() {}

void MenuState::render(sf::RenderWindow& window) {
    for(auto btn : buttons_) {
        window.draw(*btn);
    }
}

bool MenuState::checkButtonBoundaries(int key, sf::Vector2f mouse) {
    sf::Text* btn = buttons_.at(key);

    sf::Vector2f width(btn->getGlobalBounds().left, btn->getGlobalBounds().left + btn->getGlobalBounds().width);
    sf::Vector2f height(btn->getGlobalBounds().top, btn->getGlobalBounds().top + btn->getGlobalBounds().height);

    if(mouse.x > width.x && mouse.x < width.y
       && mouse.y > height.x && mouse.y < height.y)
        return true;
    return false;
}
