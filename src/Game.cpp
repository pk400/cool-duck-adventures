#include "Game.hpp"

#include <iostream>
#include <sstream>

Game::Game(int game_width, int game_height, std::string game_title)
    : gamewidth(game_width), gameheight(game_height), gsm(new GSM()), dt(0.f) {
    window = new sf::RenderWindow();
    window->create(sf::VideoMode(gamewidth, gameheight), game_title,
        sf::Style::Titlebar | sf::Style::Close);
    window->setVerticalSyncEnabled(true);
    window->setFramerateLimit(60);
}

/*
 * Everytime the game goes through a loop, it is counted as one frame.
 */
int Game::gameRun() {
    sf::Clock clock;

    while(window->isOpen()) {
        dt = clock.restart().asSeconds();

        if(dt > 0.15f)
            dt = 0.15f;

        handleEvents();
        update(dt);
        render();
    }

    return EXIT_SUCCESS;
}

void Game::handleEvents() {
    sf::Event event;

    while(window->pollEvent(event)) {
        switch(event.type) {
        case sf::Event::Closed:
            window->close();
        case sf::Event::LostFocus:
        case sf::Event::GainedFocus:
        default:
            break;
        }
    }

    switch(gsm->handleStateEvent(event, sf::Mouse::getPosition(*window))) {
        case -1: {
            window->close();
            break;
        default:
            break;
        }
    }
}

void Game::update(float dt) {
    gsm->updateState(dt);
}

void Game::render() {
    window->clear();
    gsm->renderTopState(*window);
    window->display();
}
