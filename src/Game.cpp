#include "../include/Game.hpp"
#include <iostream>
#include <sstream>

Game::Game() {
    window_.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_TITLE);
    window_.setVerticalSyncEnabled(true);
    window_.setFramerateLimit(30);

    numFrames = 0;
    font.loadFromFile("./assets/arial.ttf");
    fps_text.setFont(font);
    fps_text.setPosition(5.f, 5.f);
    fps_text.setCharacterSize(12);

    // Initialize the state manager
    gsm = new GSM();
}

void Game::run() {
    sf::Clock clock;
    sf::Time lastUpdate = sf::Time::Zero;

    while(this->window_.isOpen()) {
        sf::Time dt = clock.restart();
        lastUpdate += dt;

        while(lastUpdate > FPS) {
            lastUpdate -= FPS;
            this->handleEvents(FPS.asSeconds());
            this->update();

            stringstream ss;
            ss << "Frame: " << numFrames++;
            ss << "\nDelta Time: " << lastUpdate.asSeconds();
            fps_text.setString(ss.str());
        }

        this->render();
    }
}

void Game::handleEvents(float dt) {
    sf::Event event;
    while(window_.pollEvent(event)) {
        if(event.type == sf::Event::Closed)
            window_.close();
    }

    switch(gsm->processInputFromState(event, sf::Mouse::getPosition(window_), dt)) {
        case -1: {
            cout << "heye" << endl;
            window_.close();
            break;
        }
    }
}

void Game::update() {
    this->gsm->updateTopState();
}

void Game::render() {
    window_.clear();

    gsm->renderTopState(window_);
    window_.draw(fps_text);

    window_.display();
}
