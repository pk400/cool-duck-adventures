#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

class Player {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Text* debug_acceleration;
    sf::Text* debug_velocity;
    sf::Font font;
    int posX,
        posY;
    float acceleration = 0.2;
    float velocity;
public:
    Player();
    void loadText(sf::Font, int);
    void move(int);
    void update();
    void draw(sf::RenderWindow& win);
};

#endif // PLAYER_HPP
