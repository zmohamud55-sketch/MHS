#include "StateSystem.h"
#include <iostream>

// Concrete States (kept here so your include/ stays exactly like screenshot)

class NormalState : public IState {
public:
    virtual std::string name() const { return "Normal"; }
    virtual void onEnter() const {
        std::cout << "[STATE] Entered Normal mode (default behavior)." << std::endl;
    }
};

class SleepState : public IState {
public:
    virtual std::string name() const { return "Sleep"; }
    virtual void onEnter() const {
        std::cout << "[STATE] Entered Sleep mode (minimal activity)." << std::endl;
    }
};

class LowConsumptionState : public IState {
public:
    virtual std::string name() const { return "LowConsumption"; }
    virtual void onEnter() const {
        std::cout << "[STATE] Entered LowConsumption mode (power saving)." << std::endl;
    }
};

class HighPerformanceState : public IState {
public:
    virtual std::string name() const { return "HighPerformance"; }
    virtual void onEnter() const {
        std::cout << "[STATE] Entered HighPerformance mode (max performance)." << std::endl;
    }
};

StateSystem::StateSystem() : current(0), previous("Normal") {
    current = new NormalState();
    current->onEnter();
}

StateSystem::~StateSystem() {
    if (current) {
        delete current;
        current = 0;
    }
}

IState* StateSystem::createStateByName(const std::string& stateName) const {
    if (stateName == "Normal") return new NormalState();
    if (stateName == "Sleep") return new SleepState();
    if (stateName == "LowConsumption") return new LowConsumptionState();
    if (stateName == "HighPerformance") return new HighPerformanceState();

    // fallback
    return new NormalState();
}

void StateSystem::showCurrentState() const {
    std::cout << "Current state: " << (current ? current->name() : "None") << std::endl;
}

void StateSystem::changeState(const std::string& newStateName) {
    if (!current) return;

    // Save current state into memento BEFORE changing
    previous = StateMemento(current->name());

    // Switch to new state
    delete current;
    current = createStateByName(newStateName);

    std::cout << "State changed to " << current->name() << std::endl;
    current->onEnter();
}

void StateSystem::restorePreviousState() {
    if (!current) return;

    std::string prevName = previous.getSavedStateName();

    // If previous equals current, still restore (ok for demo)
    delete current;
    current = createStateByName(prevName);

    std::cout << "Restored previous state: " << current->name() << std::endl;
    current->onEnter();
}
