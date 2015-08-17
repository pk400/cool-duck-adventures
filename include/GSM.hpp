#ifndef GSM_HPP
#define GSM_HPP

#include "./MenuState.hpp"
#include "./PlayState.hpp"
#include <stack>

class GSM {
private:
    std::stack<State*> states;
public:
    GSM();
    bool pushState(State* s);
    bool popState();
    int getNumberOfStates();
    void processInputFromState(sf::Event);
    void updateTopState();
    void renderTopState(sf::RenderWindow&);
};

#endif // GSM_HPP
