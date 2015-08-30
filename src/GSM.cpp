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

int GSM::handleStateEvent(sf::Event event, sf::Vector2i mouse) {
    switch(states_.top()->processInput(event, mouse)) {
        case -1: {
            return -1;
            break;
        }
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

    return 0;
}

void GSM::updateState(float dt) {
    states_.top()->update(dt);
}

void GSM::renderTopState(sf::RenderWindow& window) {
    states_.top()->render(window);
}

ostream& operator<<(ostream& out, GSM& gsm) {
    out << setw(6) << '\n'
        << "GSM Size" << gsm.getNumberOfStates() << " state(s)";
    out << *gsm.getTopState();
    return out;
}


