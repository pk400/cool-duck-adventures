#ifndef GSM_HPP
#define GSM_HPP

#include "./MenuState.hpp"
#include "./PlayState.hpp"
#include <stack>

#include "./Settings.hpp"

class GSM {
private:
    std::stack<State*> states_;
    Settings* settings_;
public:
    GSM();
    void setSettings(Settings* s) { settings_ = s; std::cout << "GSM " << s << std::endl; }
    void pushState(State* s);
    void popState();
    int handleStateEvent(sf::Event event, sf::Vector2i mouse);
    void updateState(float dt);
    void renderTopState(sf::RenderWindow& window);
    State*& getTopState() { return states_.top(); }
    int getNumberOfStates();
};

#endif // GSM_HPP
