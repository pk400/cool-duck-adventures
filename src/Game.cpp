#include "../include/Game.hpp"
#include <iostream>

Game::Game() {
    this->window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_TITLE);
    this->window.setVerticalSyncEnabled(true);
    this->window.setFramerateLimit(60);

    // Initialize the state manager
    this->gsm = new GSM(this->window);
}

void Game::run() {
    while(this->window.isOpen()) {
        // Handle inputs
        this->processInput();

        // Handle update
        this->update();

        // Handle render
        this->render();
    }
}

void Game::processInput() {
    sf::Event event;
    while(this->window.pollEvent(event)) {
        if(event.type == sf::Event::Closed)
            this->window.close();


        if(event.type == sf::Event::KeyPressed) {
            switch(event.key.code) {
                case sf::Keyboard::A: std::cout << "A" << std::endl; break;
                case sf::Keyboard::D: std::cout << "D" << std::endl; break;
                case sf::Keyboard::Space: std::cout << "Space" << std::endl; break;
                default: break;
            }
        }
    }
}

void Game::update() {
    this->gsm->updateTopState();
}

void Game::render() {
    this->gsm->renderTopState();
}
