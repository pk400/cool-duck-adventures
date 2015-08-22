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

void Player::loadText(sf::Font f, int textpos) {
    this->font = f;
}

void Player::move_right(float dt) {
    //cout << position.x << " : ";

    stringstream ss;
    ss << position.x << " : " << velocity.x << " : " << dt;
    cout << ss.str() << endl;

    position.x += (velocity.x * dt);
    //position.x += 0.5;

    //cout << position.x << endl;
    sprite.setPosition(position);
}

void Player::update() {
}

void Player::draw(sf::RenderWindow& win) {
    win.draw(sprite);
    //win.draw(*debug_velocity);
}
