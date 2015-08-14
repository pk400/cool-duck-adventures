#include "../include/State.hpp"
#include "../include/Player.hpp"
#include <sstream>

Player::Player() : posX(0), posY(0), velocity(0) {
    texture.loadFromFile("./assets/spritesheet.png", sf::IntRect(0, 32, 32, 32));
    sprite.setTexture(texture);
    sprite.setPosition(posX, posY);
}

void Player::loadText(sf::Font f, int textpos) {
    this->font = f;

    // DEBUG ACCELERATION TEXT
    std::stringstream accel_str;
    accel_str << "Accel: " << acceleration;
    debug_acceleration = new sf::Text(accel_str.str(), this->font, DEBUG_TEXT_SIZE);
    debug_acceleration->setPosition(WINDOW_WIDTH - DEBUG_TEXT_OFFSET, textpos);
    textpos += DEBUG_TEXT_PADDING;

    // DEBUG VELOCITY TEXT
    std::stringstream velo_str;
    velo_str << "Velocity: " << velocity;
    debug_velocity = new sf::Text(velo_str.str(), this->font, DEBUG_TEXT_SIZE);
    debug_velocity->setPosition(WINDOW_WIDTH - DEBUG_TEXT_OFFSET, textpos);
    textpos += DEBUG_TEXT_PADDING;
}

void Player::move(int e) {
    std::stringstream velo_str;
    debug_velocity->setString("Velocity: 0.0");

    if(e == 1) {
        if(velocity < 1.5) {
            velocity += acceleration;
            posX -= velocity;
            velo_str << "Velocity: " << velocity;
            debug_velocity->setString(velo_str.str());
            sprite.move(posX, posY);
        }
        sprite.move(posX, posY);
    }

    if(e == 2) {
        if(velocity < 1.5) {
            velocity += acceleration;
            posX += velocity;
            velo_str << "Velocity: " << velocity;
            debug_velocity->setString(velo_str.str());
            sprite.move(posX, posY);
        }
        sprite.move(posX, posY);
    }
}

void Player::update() {

}

void Player::draw(sf::RenderWindow& win) {
    win.draw(sprite);
    win.draw(*debug_acceleration);
    win.draw(*debug_velocity);
}
