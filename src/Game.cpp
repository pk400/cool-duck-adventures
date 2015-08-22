#include "../include/Game.hpp"
#include <iostream>
#include <sstream>

Game::Game() {
    this->window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_TITLE);
    this->window.setFramerateLimit(60);

    // Initialize the state manager
    this->gsm = new GSM();
}

void Game::run() {
    sf::Clock clock;

    while(this->window.isOpen()) {
        float dt = clock.restart().asSeconds();

        dt *= 100.f;


        // Handle inputs
        this->processInput(dt);

        // Handle update
        this->update();

        // Handle render
        this->render();
    }
}

void Game::processInput(float dt) {
    sf::Event event;
    while(this->window.pollEvent(event)) {
        if(event.type == sf::Event::Closed)
            this->window.close();

        this->gsm->processInputFromState(event, dt);
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
