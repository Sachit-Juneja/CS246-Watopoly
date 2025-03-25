#include "pb-gyms.h"
#include "player.h"
#include <iostream>

PBGyms::PBGyms(std::string name, int pos, int cost, std::string Faculty)
    : PropertyBuildingsNew(name, pos, cost, Faculty) {}

// Event now takes rollTotal as argument
void PBGyms::event(Player *p, int rollTotal) {
    std::cout << p->getName() << " landed on " << building_name << "." << std::endl;

    if (getOwner() == nullptr) {
        std::cout << building_name << " is unowned. Would you like to buy it for $" << getCost() << "? (y/n): ";
        char choice;
        std::cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            if (p->getMoney() >= getCost()) {
                p->addMoney(-getCost());
                setOwner(p);
                std::cout << p->getName() << " bought " << building_name << " for $" << getCost() << "." << std::endl;
            } else {
                std::cout << "Not enough funds to purchase." << std::endl;
            }
        } else {
            std::cout << "Property will go to auction (not implemented)." << std::endl;
        }
    } else if (getOwner() != p) {
        // Placeholder: Owner owns 1 Gym (replace with real count logic)
        int gymsOwned = 1;

        int multiplier = (gymsOwned == 2) ? 10 : 4;
        int rent = rollTotal * multiplier;

        std::cout << p->getName() << " must pay $" << rent << " rent to " << getOwner()->getName() 
                  << " based on their roll of " << rollTotal << "." << std::endl;

        p->addMoney(-rent);
        getOwner()->addMoney(rent);
    } else {
        std::cout << "You own this Gym. No rent charged." << std::endl;
    }
}

void PBGyms::event(Player *p) {
    // Does nothing
    return;
}
