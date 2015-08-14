#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

class Player {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Text* debug_acceleration;
    sf::Font font;
    int posX, posY;
    float acceleration = 0.3;
    float velocity;
public:
    Player();
    void loadText(sf::Font, float);
    void move(int);
    void draw(sf::RenderWindow& win);
};

#endif // PLAYER_HPP
