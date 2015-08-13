#include "../include/State.hpp"
#include "../include/Player.hpp"

Player::Player() : posX(0), posY(0), velocity(0) {
    texture.loadFromFile("./assets/spritesheet.png", sf::IntRect(0, 32, 32, 32));
    sprite.setTexture(texture);
    sprite.setPosition(posX, posY);
}

void Player::move(int e) {
    if(e == 3) {
        if(velocity < 6) {
            velocity += acceleration;
            posX += velocity;
        }
        sprite.move(posX, posY);
    }
}

void Player::draw(sf::RenderWindow& win) {
    win.draw(sprite);
}
