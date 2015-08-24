#include "../include/Game.hpp"
#include <iostream>
#include <sstream>

Game::Game() {
    this->window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_TITLE);
    this->window.setVerticalSyncEnabled(true);
    this->window.setFramerateLimit(30);

    numFrames = 0;
    font.loadFromFile("./assets/arial.ttf");
    fps_text.setFont(font);
    fps_text.setPosition(5.f, 5.f);
    fps_text.setCharacterSize(12);

    // Initialize the state manager
    this->gsm = new GSM(window);
}

void Game::run() {
    sf::Clock clock;
    sf::Time lastUpdate = sf::Time::Zero;

    while(this->window.isOpen()) {
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
    while(this->window.pollEvent(event)) {
        if(event.type == sf::Event::Closed)
            this->window.close();
    }
    this->gsm->processInputFromState(event, dt);
}

void Game::update() {
    this->gsm->updateTopState();
}

void Game::render() {
    this->window.clear();

    this->gsm->renderTopState();
    this->window.draw(fps_text);

    this->window.display();
}
