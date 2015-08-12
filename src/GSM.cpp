#include "../include/GSM.hpp"

GSM::GSM() {
    State* menu = new MenuState();
    states.push(menu);
}

bool GSM::pushState(State* s) {
    states.push(s);
    if(states.size() > 0)
        return true;
    return false;
}

bool GSM::popState() {
    if(states.size() > 0){
        states.pop();
        return true;
    }
    return false;
}

int GSM::getNumberOfStates() {
    return states.size();
}

void GSM::processInputFromState(sf::Event event) {
    switch(states.top()->processInput(event)) {
        case 1: {
            State* playstate = new PlayState();
            states.pop();
            states.push(playstate);
            break;
        }
        case 2: {
            State* menu = new MenuState();
            states.pop();
            states.push(menu);
            break;
        }
        case 0: break;
        default: break;
    }
}

void GSM::updateTopState() {
    states.top()->update();
}

void GSM::renderTopState(sf::RenderWindow& win) {
    states.top()->render(win);
}
