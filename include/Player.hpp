#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

class Player {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Text* debug_acceleration;
    int posX, posY;
    float acceleration = 0.3;
    float velocity;
public:
    Player();
    void move(int);
    void draw(sf::RenderWindow& win);
};

#endif // PLAYER_HPP
