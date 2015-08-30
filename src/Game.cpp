#include "../include/Game.hpp"
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
    //gsm = new GSM();
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
        << "F:"  << setw(6) << frames++
        << "DT:" << setw(6) << dt
        << "MX:" << setw(6) << sf::Mouse::getPosition(*window).x
        << "MY:" << setw(6) << sf::Mouse::getPosition(*window).y
        << *gsm;

    debugBox_.setString(debugline.str());
    debugBox_.setPosition(10.f, 10.f);
}
