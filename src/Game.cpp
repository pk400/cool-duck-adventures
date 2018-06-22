#include "Game.hpp"
#include <iostream>
#include <sstream>

Game::Game()
    : window(new sf::RenderWindow()), gamewidth(800), gameheight(480),
    gsm(new GSM()), frames(0), dt(0.f) {
    window->create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
                   "Platformer", sf::Style::Titlebar| sf::Style::Close);
    window->setVerticalSyncEnabled(true);
    window->setFramerateLimit(60);

    font.loadFromFile("./assets/ubuntu-font-family-0.83/UbuntuMono-R.ttf");

    debugBox_.setFont(font);
    debugBox_.setOrigin(0.f, 0.f);
    debugBox_.setCharacterSize(12);
}

Game::Game(int w_width, int w_height)
    : gamewidth(w_width), gameheight(w_height), gsm(new GSM()), frames(0), dt(0.f) {
    window = new sf::RenderWindow();
    window->create(sf::VideoMode(gamewidth, gameheight), "Cool Duck Adventures!",
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

    setupDebugBox();

    frames++;
}

void Game::render() {
    window->clear();

    gsm->renderTopState(*window);
    window->draw(debugBox_);

    window->display();
}

void Game::setupDebugBox() {
    stringstream debugline;

    debugline << fixed << left << setprecision(2)
        << setw(16) << "Frame"       << setw(15) << frames << '\n'
        << setw(16) << "Delta Time"  << dt << '\n'
        << setw(16) << "Mouse X"     << sf::Mouse::getPosition(*window).x << '\n'
        << setw(16) << "Mouse Y"     << sf::Mouse::getPosition(*window).y << '\n'
        << *gsm;

    debugBox_.setString(debugline.str());
    debugBox_.setPosition(0.f, 0.f);
}
