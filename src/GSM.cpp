#include "../include/GSM.hpp"

State* menustate;
State* playstate;

GSM::GSM() {
    menustate = new MenuState();
    states.push(menustate);
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

void GSM::processInputFromState(sf::Event event, float dt) {
    switch(states.top()->processInput(event, dt)) {
        case 1: {
            playstate = new PlayState();
            states.pop();
            states.push(playstate);
            break;
        }
        case 2: {
            states.push(menustate);
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
