#include "npb-tuition.h"
#include "player.h"
#include <iostream>

NPBTuition::NPBTuition()
    : NonPropertyBuilding("Tuition", 4) {}

void NPBTuition::event(Player *p) {
    std::cout << p->getName() << " has landed on Tuition." << std::endl;

    // Assume total worth = money only for now (can expand later)
    int tenPercent = p->getTotalAssets() / 10;
    
    std::cout << "Choose payment option:\n"
              << "1. Pay $300\n"
              << "2. Pay 10% of your total worth ($" << tenPercent << ")\n"
              << "Enter choice (1 or 2): ";

    int choice;
    std::cin >> choice;
    std::cin.ignore(1000, '\n');
    int payment = (choice == 2) ? tenPercent : 300;

    p->addMoney(-payment);
    std::cout << p->getName() << " paid $" << payment << " in tuition." << std::endl;
}
