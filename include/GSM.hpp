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
    int processInputFromState(sf::Event event, sf::Vector2i mouse);
    void updateTopState(float dt);
    void renderTopState(sf::RenderWindow& window);
    State*& getTopState() { return states_.top(); }
    int getNumberOfStates();
};

ostream& operator<<(ostream& out, GSM& gsm);

#endif // GSM_HPP
