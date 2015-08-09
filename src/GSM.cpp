#include "../include/GSM.hpp"
#include <iostream>

GSM::GSM() {
    std::cout << "GSM CREATED" << std::endl;
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

void GSM::updateTopState() {
    states.top()->update();
}

void GSM::renderTopState() {
    states.top()->render();
}
