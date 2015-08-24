#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

class State;

class Player {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Font font_;
    sf::Text* debugPlayerState_;
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f gravity;
public:
    Player();
    void loadText(sf::Font);
    void move_right(float);
    void update();
    void draw(sf::RenderWindow& win);
};

#endif // PLAYER_HPP
