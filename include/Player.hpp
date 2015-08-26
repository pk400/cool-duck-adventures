#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

class State;

//enum PlayerState { STANDING, MOVING_LEFT, MOVING_RIGHT, JUMPING };

class Player {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Font font_;
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f gravity;
    float maxSpeed = 200.f;
    string stateText;
    bool isStanding;
    bool isMovingLeft;
    bool isMovingRight;
    bool isJumping;
    bool isAtVerticalPeak;
public:
    Player();
    void update(float dt);
    void draw(sf::RenderWindow& win);
    void handleInput();
    string getPlayerState() { return stateText; }
    sf::Vector2f getPosition() { return position; }
    sf::Vector2f getVelocity() { return velocity; }
    sf::Vector2f getGravity() { return gravity; }

    void moveLeft(float dt);
    void moveRight(float dt);
    void jump(float dt);
};

ostream& operator<<(ostream& out, Player& player);

#endif // PLAYER_HPP
