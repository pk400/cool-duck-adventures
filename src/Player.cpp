#include "../include/State.hpp"
#include "../include/Player.hpp"
#include <sstream>

Player::Player() :
    position((WINDOW_WIDTH / 2) - 32, (WINDOW_HEIGHT - 32)),
    velocity(0.5f, 0.f),
    gravity(0.f, -2.f) {

    texture.loadFromFile("./assets/spritesheet.png", sf::IntRect(0, 32, 32, 32));
    sprite.setTexture(texture);
    sprite.setOrigin(0, 32);
    sprite.setPosition(position);
}

void Player::update(float dt) {
    float maxSpeed = 150.f;

    switch(ps) {
        case MOVING_LEFT: {
            position.x -= (velocity.x * dt);
            velocity.x  += pow(position.x * dt, 1.5);
            if(velocity.x > maxSpeed)
                velocity.x = maxSpeed;
            break;
        }
        case MOVING_RIGHT: {
            position.x += (velocity.x * dt);
            velocity.x  += pow(position.x * dt, 1.5);
            if(velocity.x > maxSpeed)
                velocity.x = maxSpeed;
            break;
        }
        case JUMPING:
        case STANDING: {
            velocity.x = 0.f;
            break;
        }
    }

    sprite.setPosition(position);
}

void Player::draw(sf::RenderWindow& win) {
    win.draw(sprite);
}

void Player::handleInput() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        ps = MOVING_LEFT;
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        ps = MOVING_RIGHT;
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        ps = JUMPING;
    } else {
        ps = STANDING;
    }
}

ostream& operator<<(ostream& out, Player& player) {
    out << setw(16) << "Player" << "Yes" << '\n';
    out << setw(16) << "Velocity";
    out << setw(6) << player.getVelocity().x << ' ' << player.getVelocity().y << '\n';
    out << setw(16) << "Gravity";
    out << setw(6) << player.getGravity().x << ' ' << player.getGravity().y << '\n';
    out << setw(16) << "Player Input";

    switch(player.getPlayerState()) {
        case 0: out << "Idle"; break;
        case 1: out << "M. Left"; break;
        case 2: out << "M. Right"; break;
        case 3: out << "Jumping"; break;
    }
    out << '\n';

    return out;
}
