#include "Game.hpp"
#include <iostream>
#include <sstream>

Game::Game()
    : window(new sf::RenderWindow()), gamewidth(800), gameheight(480),
    gsm(new GSM()), dt(0.f) {
    window->create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
                   "Platformer", sf::Style::Titlebar| sf::Style::Close);
    window->setVerticalSyncEnabled(true);
    window->setFramerateLimit(60);
}

Game::Game(int w_width, int w_height)
    : gamewidth(w_width), gameheight(w_height), gsm(new GSM()), dt(0.f) {
    window = new sf::RenderWindow();
    window->create(sf::VideoMode(gamewidth, gameheight), "Sprout",
        sf::Style::Titlebar | sf::Style::Close);
    window->setVerticalSyncEnabled(true);
    window->setFramerateLimit(60);
}

int Game::exec() {
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
