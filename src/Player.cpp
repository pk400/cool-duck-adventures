#include "../include/State.hpp"
#include "../include/Player.hpp"
#include <sstream>
#include <math.h>

Player::Player() :
    position((WINDOW_WIDTH / 2) - 32, (WINDOW_HEIGHT - 32)),
    velocity(10.f, 0.f),
    gravity(0.f, 50.f),
    isStanding(false),
    isMovingLeft(false),
    isMovingRight(false),
    isJumping(false),
    isAtVerticalPeak(false) {

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
    } else if(isMovingRight) {
        moveRight(dt);
    } else {
        stateText += "Standing";
    }

    if(position.x < 5.f)
        position.x = 5.f;
    if(position.x > WINDOW_WIDTH - 5.f)
        position.x = WINDOW_WIDTH - 5.f;
    if(position.y > (WINDOW_HEIGHT - 32.f))
        position.y = WINDOW_HEIGHT - 32.f;
    sprite.setPosition(position);

    isStanding = false;
    isMovingLeft = false;
    isMovingRight = false;
}

void Player::draw(sf::RenderWindow& win) {
    //sf::View view(position, sf::Vector2f(400, 240));
    //win.setView(view);

    win.draw(sprite);
}

void Player::handleInput() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        isMovingLeft = true;
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        isMovingRight = true;
    } else {
        isStanding = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        isJumping = true;
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
    float jumpSpeed = 5.f;

    if(!isAtVerticalPeak) {
        velocity.y -= pow(jumpSpeed, 2.3);
        if(position.y < (WINDOW_HEIGHT - 32.f) - 20.f) {
            isAtVerticalPeak = true;
            position.y = (WINDOW_HEIGHT - 32.f) - 20.f;
        }
    } else {
        velocity.y += pow(jumpSpeed, 2.3);
        if(position.y >= (WINDOW_HEIGHT - 32.f)){
            isAtVerticalPeak = false;
            isJumping = false;
            velocity.y = 0.f;
        }
    }

    if(isMovingLeft)
        position.x -= (velocity.x * dt);
    if(isMovingRight)
        position.x += (velocity.x * dt);
    position.y += (velocity.y * dt);
}

ostream& operator<<(ostream& out, Player& player) {
    out << setw(16) << "Position";
    out << setw(6) << player.getPosition().x << ' ' << player.getPosition().y << '\n';
    out << setw(16) << "Velocity";
    out << setw(6) << player.getVelocity().x << ' ' << player.getVelocity().y << '\n';
    out << setw(16) << "Gravity";
    out << setw(6) << player.getGravity().x << ' ' << player.getGravity().y << '\n';
    out << setw(16) << "Player Input" << player.getPlayerState() << '\n';

    return out;
}
