#include "../include/State.hpp"
#include "../include/Player.hpp"
#include <sstream>

Player::Player() :
    position((WINDOW_WIDTH / 2) - 32, (WINDOW_HEIGHT - 32)),
    velocity(0.2f, 0.f),
    gravity(0.f, -2.f) {

    texture.loadFromFile("./assets/spritesheet.png", sf::IntRect(0, 32, 32, 32));
    sprite.setTexture(texture);
    sprite.setOrigin(0, 32);
    sprite.setPosition(position);
}

void Player::update() {
    sprite.setPosition(position);
}

void Player::draw(sf::RenderWindow& win) {
    win.draw(sprite);
}

void Player::handleInput(float dt) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        if(ps == STANDING) {
            ps = MOVING_LEFT;
            velocity = sf::Vector2f(0.f, 0.f);
        }
        position.x -= velocity.x * dt;
        velocity.x += pow(position.x * dt, 1.5);
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        if(ps == STANDING) {
            ps = MOVING_RIGHT;
            velocity = sf::Vector2f(0.f, 0.f);
        }
        position.x += velocity.x * dt;
        velocity.x += pow(position.x * dt, 1.5);
    } else {
        ps = STANDING;
        velocity += sf::Vector2f(-5.f, 0.f);
    }

    if(velocity.x > 200.f)
        velocity.x = 200.f;
}
