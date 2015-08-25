#include "../include/Game.hpp"
#include "../include/PlayState.hpp"

PlayState::PlayState() {
    player = new Player();

    bgTexture_.loadFromFile("./assets/bg_mountains.png", sf::IntRect(0, 0, 240, 120));
    bgSprite_.setTexture(bgTexture_);
    bgSprite_.setScale(3.5f, 3.5f);
    bgSprite_.setOrigin(0, 120);
    bgSprite_.setPosition(0, WINDOW_HEIGHT - 32);

    platTexture_.loadFromFile("./assets/grass-dirt.png", sf::IntRect(0, 0, 32, 32));
    for(int i = 0; i < 25; i++) {
        sf::Sprite plat;
        plat.setTexture(platTexture_);
        plat.setOrigin(0, 32);
        plat.setPosition(32 * i, WINDOW_HEIGHT);
        platSprites_.push_back(plat);
    }
}

void PlayState::loadDebugText() {
    debug_input = new sf::Text("Input: ", font, DEBUG_TEXT_SIZE);
    debug_input->setPosition(5.f, 5.f);
}

int PlayState::processInput(sf::Event event, sf::Vector2i mouse, float dt) {
    player->handleInput(dt);
    return 0;
}

void PlayState::update() {
    player->update();
}

void PlayState::render(sf::RenderWindow& window) {
    window.clear(sf::Color(227, 162, 57));

    window.draw(bgSprite_);
    for(auto sprite : platSprites_) {
        window.draw(sprite);
    }

    player->draw(window);
}
