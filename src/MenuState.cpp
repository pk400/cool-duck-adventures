#include "Game.hpp"
#include "MenuState.hpp"

MenuState::MenuState() {
    addButtons();

    bgTexture_.loadFromFile("./assets/tempMenuBG.png");

    bgSprite_.setTexture(bgTexture_);
    bgSprite_.setTextureRect(sf::IntRect(1024, 0, -1024, 576));
    bgSprite_.setScale(0.9f, 0.9f);
}

void MenuState::addButtons() {
    float startPosX = 100.f;
    float startPosY = 100.f;
    sf::Vector2f pos(startPosX, startPosY);

    buttons_.push_back(new sf::Text("START"   , font, 30));
    buttons_.push_back(new sf::Text("Options" , font, 30));
    buttons_.push_back(new sf::Text("Help"    , font, 30));
    buttons_.push_back(new sf::Text("Exit"    , font, 30));

    for(auto btn : buttons_) {
        btn->setStyle(sf::Text::Bold);
        btn->setPosition(pos);
        pos.y += 60.f;
    }
}

int MenuState::processInput(sf::Event event, sf::Vector2i mouse) {
    if(checkButtonBoundaries(START, sf::Vector2f(mouse)))
        onMouseHover(START, sf::Vector2f(mouse));

    if(checkButtonBoundaries(OPTIONS, sf::Vector2f(mouse)))
        onMouseHover(OPTIONS, sf::Vector2f(mouse));

    if(checkButtonBoundaries(HELP, sf::Vector2f(mouse)))
        onMouseHover(HELP, sf::Vector2f(mouse));

    if(checkButtonBoundaries(EXIT, sf::Vector2f(mouse)))
        onMouseHover(EXIT, sf::Vector2f(mouse));

    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        if(checkButtonBoundaries(START  , sf::Vector2f(mouse))) return 1;
        if(checkButtonBoundaries(OPTIONS, sf::Vector2f(mouse))) return 0;
        if(checkButtonBoundaries(HELP   , sf::Vector2f(mouse))) return 0;
        if(checkButtonBoundaries(EXIT   , sf::Vector2f(mouse))) return -1;
    }

    return 0;
}

void MenuState::update(float dt) {
}

void MenuState::render(sf::RenderWindow& window) {
    window.draw(bgSprite_);
    for(auto btn : buttons_) {
        window.draw(*btn);
        btn->setFillColor(sf::Color::White);
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


void MenuState::onMouseHover(int key, sf::Vector2f mouse) {
    sf::Text* btn = buttons_.at(key);
    btn->setFillColor(sf::Color::Red);
}
