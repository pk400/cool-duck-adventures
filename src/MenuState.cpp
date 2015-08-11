#include "../include/MenuState.hpp"
#include <iostream>

MenuState::MenuState() {
    std::cout << "MenuState CREATED" << std::endl;
    font.loadFromFile("../assets/arial.ttf");

    game_title.setString("PLATFORMER");
    game_title.setFont(font);


}
void MenuState::update() {}
void MenuState::render() {
    Draw(game_title);
}

