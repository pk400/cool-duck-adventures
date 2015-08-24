#ifndef GSM_HPP
#define GSM_HPP

#include "./MenuState.hpp"
#include "./PlayState.hpp"
#include <stack>

class GSM {
private:
    std::stack<State*> states_;
public:
    GSM();
    void pushState(State* s);
    void popState();
    int getNumberOfStates();
    void processInputFromState(sf::Event, float);
    void updateTopState();
    void renderTopState(sf::RenderWindow&);
};

#endif // GSM_HPP
