#ifndef STATEMEMENTO_H
#define STATEMEMENTO_H

#include <string>

// Memento: stores a snapshot of the previous state's name
class StateMemento {
private:
    std::string savedStateName;

public:
    StateMemento() : savedStateName("Normal") {}
    StateMemento(const std::string& name) : savedStateName(name) {}

    std::string getSavedStateName() const {
        return savedStateName;
    }
};

#endif
