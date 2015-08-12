#include "../include/Game.hpp"
#include <iostream>

Game::Game() {
    this->window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_TITLE);

    // Initialize the state manager
    this->gsm = new GSM();
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

        this->gsm->processInputFromState(event);
    }
}

void Game::update() {
    this->gsm->updateTopState();
}

void Game::render() {
    this->window.clear();
    this->gsm->renderTopState(this->window);
    this->window.display();
}
