#ifndef STATE_SYSTEM_H
#define STATE_SYSTEM_H

#include <string>
#include <vector>

class StateSystem {
private:
    std::string currentState;
    std::vector<std::string> history;
    const size_t MAX_HISTORY; // To satisfy LLR-ST4 (History of 5)

public:
    StateSystem();
    // Integrated with the Hub's naming convention
    void changeState(const std::string& newState);
    void restorePrevious(); // Memento-like undo (LLR-ST5)
    std::string getCurrentState() const;
};

#endif