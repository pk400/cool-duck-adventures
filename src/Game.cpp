#include "Game.hpp"

#include <iostream>
#include <sstream>

Game::Game(Settings& settings) {
    gs_ = &settings;
    gsm_ = new GSM();
    dt_ = 0.f;
    window_ = new sf::RenderWindow();
}

int Game::setup() {
    window_->create(sf::VideoMode(gs_->width, gs_->height), gs_->title,
        sf::Style::Titlebar | sf::Style::Close);
    window_->setVerticalSyncEnabled(gs_->vertical_sync);
    window_->setFramerateLimit(gs_->frame_rate);

    // gs_ points to the Settings struct created in Main.cpp, it will be
    // referenced throughout the project. It should always have the same address
    // to avoid having to create copies of the exact same object everytime.
    gsm_->setSettings(*gs_);

    // TODO(pk400): Make setup() return an error if setup fails
    return 0;
}

/*
 * Everytime the game goes through a loop, it is counted as one frame.
 */
int Game::gameRun() {
    sf::Clock clock;

    while(window_->isOpen()) {
        dt_ = clock.restart().asSeconds();

        if(dt_ > 0.015f)
            dt_ = 0.015f;

        handleEvents();
        update();
        render();
    }

    return EXIT_SUCCESS;
}

void Game::handleEvents() {
    sf::Event event;

    while(window_->pollEvent(event)) {
        switch(event.type) {
        case sf::Event::Closed:
            window_->close();
        case sf::Event::LostFocus:
        case sf::Event::GainedFocus:
        default:
            break;
        }
    }

    switch(gsm_->handleStateEvent(event, sf::Mouse::getPosition(*window_))) {
        case -1: {
            window_->close();
            break;
        default:
            break;
        }
    }
}

void Game::update() {
    gsm_->updateState(dt_);
}

void Game::render() {
    window_->clear();
    gsm_->renderTopState(*window_);
    window_->display();
}
