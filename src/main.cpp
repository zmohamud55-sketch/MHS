#include <iostream>
#include <string>
#include "StateSystem.h"

static void showMenu() {
    std::cout << "\n--- State System Menu ---\n";
    std::cout << "1) Show current state\n";
    std::cout << "2) Change state\n";
    std::cout << "3) Restore previous state (Memento)\n";
    std::cout << "4) Exit\n";
    std::cout << "Choice: ";
}

static std::string askStateName() {
    std::cout << "Enter state (Normal / Sleep / LowConsumption / HighPerformance): ";
    std::string s;
    std::cin >> s;
    return s;
}

int main() {
    StateSystem system;

    int choice = 0;
    while (true) {
        showMenu();
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Exiting.\n";
            return 0;
        }

        if (choice == 1) {
            system.showCurrentState();
        } else if (choice == 2) {
            std::string stateName = askStateName();
            system.changeState(stateName);
        } else if (choice == 3) {
            system.restorePreviousState();
        } else if (choice == 4) {
            std::cout << "Bye.\n";
            break;
        } else {
            std::cout << "Unknown choice.\n";
        }
    }

    return 0;
}
