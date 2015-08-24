#include "../include/GSM.hpp"

State* menustate;
State* playstate;

GSM::GSM() {
    switch(DEBUG_MODE) {
        case DEFAULT: {
            menustate = new MenuState();
            states_.push(menustate);
            break;
        }

        case MENU: {
            menustate = new MenuState();
            states_.push(menustate);
            break;
        }

        case PLAY: {
            playstate = new PlayState();
            states_.push(playstate);
            break;
        }
    }
}

void GSM::pushState(State* state) {
    states_.push(state);
}

void GSM::popState() {
    //TODO: Possibly add an exception handler here in case no states to pop
    states_.pop();
}

int GSM::getNumberOfStates() {
    return states_.size();
}

void GSM::processInputFromState(sf::Event event, float dt) {
    switch(states_.top()->processInput(event, dt)) {
        case 1: {
            playstate = new PlayState();
            states_.pop();
            states_.push(playstate);
            break;
        }
        case 2: {
            states_.push(menustate);
            break;
        }
        case 0: break;
        default: break;
    }
}

void GSM::updateTopState() {
    states_.top()->update();
}

void GSM::renderTopState(sf::RenderWindow& win) {
    states_.top()->render(win);
}
