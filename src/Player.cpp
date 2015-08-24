#include "../include/State.hpp"
#include "../include/Player.hpp"
#include <sstream>

Player::Player() :
    position(0.f, (WINDOW_HEIGHT / 3)),
    velocity(0.8f, 0.f),
    gravity(0.f, 0.f) {
    texture.loadFromFile("./assets/spritesheet.png", sf::IntRect(0, 32, 32, 32));
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

void Player::loadText(sf::Font font) {
    font_ = font;

    debugPlayerState_ = new sf::Text("State: ", font_, DEBUG_TEXT_SIZE);
    debugPlayerState_->setPosition(5.f, 5.f);
    debugPlayerState_->setStyle(sf::Text::Style::Bold);
}

void Player::move_right(float dt) {

}

void Player::update() {

}

void Player::draw(sf::RenderWindow& win) {
    win.draw(sprite);
}
