#include "Game.hpp"
#include "PlayState.hpp"

PlayState::PlayState() {
    player = new Player();

    // mobs
    mobtexture_.loadFromFile("./assets/player.png", sf::IntRect(0, 0, 24, 27));
    mobsprite_.setTexture(mobtexture_);
    mobsprite_.setOrigin(24, 27);
    mobsprite_.setPosition(100, WINDOW_HEIGHT - 32);

    // backgrounds
    bgTexture_.loadFromFile("./assets/bg_mountains.png", sf::IntRect(0, 0, 240, 120));
    bgSprite_.setTexture(bgTexture_);
    bgSprite_.setScale(3.5f, 3.5f);
    bgSprite_.setOrigin(0, 120);
    bgSprite_.setPosition(0, WINDOW_HEIGHT - 32);

    // platform
    platTexture_.loadFromFile("./assets/grass-dirt.png", sf::IntRect(0, 0, 32, 32));
    for(int i = 0; i < 25; i++) {
        sf::Sprite plat;
        plat.setTexture(platTexture_);
        plat.setOrigin(0, 32);
        plat.setPosition(32 * i, WINDOW_HEIGHT);
        platSprites_.push_back(plat);
    }
}

int PlayState::processInput(sf::Event event, sf::Vector2i mouse) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        return 2;
    player->handleInput();
    return 0;
}

void PlayState::update(float dt) {
    player->update(dt);
}

void PlayState::render(sf::RenderWindow& window) {
    window.clear(sf::Color(227, 162, 57));

    window.draw(bgSprite_);
    for(auto sprite : platSprites_) {
        window.draw(sprite);
    }

    window.draw(mobsprite_);

    player->draw(window);
}
void PlayState::toString(ostream& out) const {
    out << setw(16) << "Current State" << "Playstate" << '\n';
    out << *player;
}


