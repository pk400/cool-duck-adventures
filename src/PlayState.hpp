#ifndef PLAYSTATE_HPP
#define PLAYSTATE_HPP

#include "State.hpp"
#include "Player.hpp"

class PlayState : public State {
private:
    Player* player;
    sf::Texture mobtexture_;
    sf::Texture bgTexture_;
    sf::Texture platTexture_;
    sf::Sprite bgSprite_;
    sf::Sprite mobsprite_;
    vector<sf::Sprite> platSprites_;
public:
    PlayState();
    int processInput(sf::Event event, sf::Vector2i mouse);
    void update(float dt);
    void render(sf::RenderWindow& window);
};

#endif // PLAYSTATE_HPP
