#include "../include/Game.hpp"
#include <iostream>
#include <sstream>

Game::Game() :
    numFrames(0),
    dt(0.f) {
    window_.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_TITLE, sf::Style::Titlebar | sf::Style::Close);
    window_.setVerticalSyncEnabled(true);
    window_.setFramerateLimit(60);

    font.loadFromFile("./assets/ubuntu-font-family-0.83/UbuntuMono-R.ttf");

    debugBox_.setFont(font);
    debugBox_.setOrigin(0.f, 0.f);
    debugBox_.setCharacterSize(12);

    gsm = new GSM();
}

void Game::run() {
    sf::Clock clock;

    while(window_.isOpen()) {
        dt = clock.restart().asSeconds();

        if(dt > 0.15f)
            dt = 0.15f;

        handleEvents();
        update(dt);

        this->render();
    }
}

void Game::handleEvents() {
    sf::Event event;
    while(window_.pollEvent(event)) {
        if(event.type == sf::Event::Closed)
            window_.close();
    }

    switch(gsm->processInputFromState(event, sf::Mouse::getPosition(window_))) {
        case -1: {
            window_.close();
            break;
        }
    }
}

void Game::update(float dt) {
    this->gsm->updateTopState(dt);

    stringstream ss;
    ss << *this << *gsm;

    debugBox_.setString(ss.str());
    debugBox_.setPosition(WINDOW_WIDTH - debugBox_.getGlobalBounds().width - 10.f, 10.f);
}

void Game::render() {
    window_.clear();

    gsm->renderTopState(window_);
    window_.draw(debugBox_);

    window_.display();
}

ostream& operator<<(ostream& out, Game& game) {
    out << fixed << left << setprecision(2);
    out << setw(16) << "Frame"       << setw(15) << game.numFrames++ << '\n';
    out << setw(16) << "Delta Time"  << game.dt << '\n';
    out << setw(16) << "Mouse X"     << sf::Mouse::getPosition(game.getContextWindow()).x << '\n';
    out << setw(16) << "Mouse Y"     << sf::Mouse::getPosition(game.getContextWindow()).y << '\n';

    return out;
}
