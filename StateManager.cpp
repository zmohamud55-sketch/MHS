#include "StateManager.h"
#include "State.h"      // needed for getName()
#include "Logger.h"

StateManager::StateManager()
    : currentState(0)
{
}

StateManager::~StateManager()
{
    while (!history.empty()) {
        history.pop();
    }
}

void StateManager::changeState(State* newState)
{
    if (!newState) return;

    if (currentState) {
        if ((int)history.size() == MAX_HISTORY) {
            history.pop();
        }
        history.push(currentState);
    }

    currentState = newState;

    Logger::getInstance().log(
        std::string("State changed to ") + currentState->getName()
    );
}

void StateManager::undoState()
{
    if (history.empty()) {
        Logger::getInstance().log("No previous state to restore");
        return;
    }

    currentState = history.top();
    history.pop();

    Logger::getInstance().log(
        std::string("State restored to ") + currentState->getName()
    );
}

std::string StateManager::getCurrentState() const
{
    return currentState ? currentState->getName() : "None";
}
