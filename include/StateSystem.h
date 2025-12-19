#ifndef STATESYSTEM_H
#define STATESYSTEM_H

#include <string>
#include "IState.h"
#include "StateMemento.h"

// StateSystem: uses State pattern for behavior changes,
// and Memento pattern to restore previous state.
class StateSystem {
private:
    IState* current;         // current State
    StateMemento previous;   // Memento (previous state snapshot)

    // helper: create state objects by name
    IState* createStateByName(const std::string& stateName) const;

public:
    StateSystem();
    ~StateSystem();

    void showCurrentState() const;

    // State pattern behavior
    void changeState(const std::string& newStateName);

    // Memento pattern behavior
    void restorePreviousState();
};

#endif
