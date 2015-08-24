#include "../include/Game.hpp"
#include "../include/PlayState.hpp"

PlayState::PlayState() {
    player = new Player();
    loadDebugText();
}

void PlayState::loadDebugText() {
    debug_input = new sf::Text("Input: ", font, DEBUG_TEXT_SIZE);
    debug_input->setPosition(5.f, 5.f);

    player->loadText(font);
}

int PlayState::processInput(sf::Event event, float dt) {

}

void PlayState::update() {
    player->update();
}

void PlayState::render(sf::RenderWindow& win) {
    win.draw(*debug_input);
    player->draw(win);
}
