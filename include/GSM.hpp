#ifndef GSM_HPP
#define GSM_HPP

#include "State.hpp"
#include <Stack>

class GSM {
private:
    std::stack<State> states;
public:
    GSM();
};

#endif // GSM_HPP
