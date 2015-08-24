#ifndef GSM_HPP
#define GSM_HPP

#include "./MenuState.hpp"
#include "./PlayState.hpp"
#include <stack>

class GSM {
private:
    sf::RenderWindow& window_;
    std::stack<State*> states_;
public:
    GSM(sf::RenderWindow& window);
    void pushState(State* s);
    void popState();
    int getNumberOfStates();
    void processInputFromState(sf::Event, float);
    void updateTopState();
    void renderTopState();
};

#endif // GSM_HPP
