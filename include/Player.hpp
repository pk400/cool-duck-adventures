#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

class Player {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Text* debug_velocity;
    sf::Font font;
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f gravity;
    //float acceleration = 0.2;
    //float velocity;
public:
    Player();
    void loadText(sf::Font, int);
    void move_right(float);
    //void move(int);
    void update();
    void draw(sf::RenderWindow& win);
};

#endif // PLAYER_HPP
