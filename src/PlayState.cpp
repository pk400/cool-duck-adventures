#include "../include/Game.hpp"
#include "../include/PlayState.hpp"

PlayState::PlayState() {
    loadText();
}

void PlayState::loadText() {
    debug_state = new sf::Text("State: Play State", font, 12);
    debug_state->setPosition(WINDOW_WIDTH - 100, 0);

    debug_input = new sf::Text("Input: ", font, 12);
    debug_input->setPosition(WINDOW_WIDTH - 100, debug_state->getLocalBounds().height);
}

int PlayState::processInput(sf::Event event) {
    std::string debug_str = "Input: ";

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        debug_str += 'A';
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        debug_str += 'D';
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        debug_str += "Spacebar";
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        return 2;
    }

    debug_input->setString(debug_str);

    return 0;
}

void PlayState::update() {
}

void PlayState::render(sf::RenderWindow& win) {
    win.draw(*debug_state);
    win.draw(*debug_input);
}
