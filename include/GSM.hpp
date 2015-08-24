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
    int processInputFromState(sf::Event event, sf::Vector2i mouse, float dt);
    void updateTopState();
    void renderTopState(sf::RenderWindow& window);
};

#endif // GSM_HPP
