#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

class State;

enum PlayerState { STANDING, MOVING_LEFT, MOVING_RIGHT, JUMPING };

class Player {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Font font_;
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f gravity;
    PlayerState ps;
public:
    Player();
    void update(float dt);
    void draw(sf::RenderWindow& win);
    void handleInput();
    PlayerState getPlayerState() { return ps; }
    sf::Vector2f getVelocity() { return velocity; }
    sf::Vector2f getGravity() { return gravity; }
};

ostream& operator<<(ostream& out, Player& player);

#endif // PLAYER_HPP
