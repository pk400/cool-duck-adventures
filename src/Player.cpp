#include "../include/State.hpp"
#include "../include/Player.hpp"
#include <sstream>

Player::Player() :
    position((WINDOW_WIDTH / 2) - 32, (WINDOW_HEIGHT - 32)),
    velocity(0.5f, 0.f),
    gravity(0.f, -2.f),
    isStanding(false),
    isMovingLeft(false),
    isMovingRight(false),
    isJumping(false) {

    texture.loadFromFile("./assets/spritesheet.png", sf::IntRect(0, 32, 32, 32));
    sprite.setTexture(texture);
    sprite.setOrigin(0, 32);
    sprite.setPosition(position);
}

void Player::update(float dt) {
    stateText = "";

    if(isJumping) {
        jump(dt);
    }
    if(isMovingLeft) {
        moveLeft(dt);
    }
    if(isMovingRight) {
        moveRight(dt);
    }

    /*switch(ps) {
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
        case JUMPING: {

            break;
        }
        case STANDING: {
            velocity.x = 0.f;
            break;
        }
    }*/

    if(position.x < 5.f)
        position.x = 5.f;
    if(position.x > WINDOW_WIDTH - 5.f)
        position.x = WINDOW_WIDTH - 5.f;
    sprite.setPosition(position);

    isStanding = false;
    isMovingLeft = false;
    isMovingRight = false;
    isJumping = false;
}

void Player::draw(sf::RenderWindow& win) {
    win.draw(sprite);
}

void Player::handleInput() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        isMovingLeft = true;
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        isMovingRight = true;
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        isJumping = true;
    } else {
        isStanding = true;
    }
}

void Player::moveLeft(float dt) {
    stateText += "Left";
    position.x -= (velocity.x * dt);
    velocity.x  += pow(position.x * dt, 1.5);
    if(velocity.x > maxSpeed)
        velocity.x = maxSpeed;
}

void Player::moveRight(float dt) {
    stateText += "Right";
    position.x += (velocity.x * dt);
    velocity.x  += pow(position.x * dt, 1.5);
    if(velocity.x > maxSpeed)
        velocity.x = maxSpeed;
}

void Player::jump(float dt) {
    stateText += "Jump";
}

ostream& operator<<(ostream& out, Player& player) {
    out << setw(16) << "Player" << "Yes" << '\n';
    out << setw(16) << "Position";
    out << setw(6) << player.getPosition().x << ' ' << player.getPosition().y << '\n';
    out << setw(16) << "Velocity";
    out << setw(6) << player.getVelocity().x << ' ' << player.getVelocity().y << '\n';
    out << setw(16) << "Gravity";
    out << setw(6) << player.getGravity().x << ' ' << player.getGravity().y << '\n';
    out << setw(16) << "Player Input" << player.getPlayerState() << '\n';

    return out;
}
