#include "../include/Game.hpp"
#include "../include/PlayState.hpp"

PlayState::PlayState() {
    player = new Player();
    loadText();
}

void PlayState::loadText() {
    int text_height = 0;

    // DEBUG STATE TEXT
    debug_state = new sf::Text("State: Play State", font, DEBUG_TEXT_SIZE);
    debug_state->setPosition(WINDOW_WIDTH - DEBUG_TEXT_OFFSET, text_height);
    text_height += DEBUG_TEXT_PADDING;

    // DEBUG INPUT TEXT
    debug_input = new sf::Text("Input: ", font, DEBUG_TEXT_SIZE);
    debug_input->setPosition(WINDOW_WIDTH - DEBUG_TEXT_OFFSET, text_height);
    text_height += DEBUG_TEXT_PADDING;

    // LOAD PLAYER INPUT TEXT
    player->loadText(font, text_height);
}

int PlayState::processInput(sf::Event event) {
    std::string debug_str = "Input: ";

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        player->move(1);
        debug_str += 'A';
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        player->move(2);
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
    player->draw(win);
}
