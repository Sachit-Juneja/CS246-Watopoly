#include "pb-residences.h"
#include "player.h"  // Ensure this is included for Player methods
#include <iostream>

// Constructor: passes everything to base
PBResidences::PBResidences(std::string name, int pos, int cost, std::string Faculty)
    : PropertyBuildingsNew(name, pos, cost, Faculty) {}

// Event: handles rent or purchase logic
void PBResidences::event(Player *p) {
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
                std::cout << "Insufficient funds to purchase " << building_name << "." << std::endl;
            }
        } else {
            std::cout << "Property will go to auction (not implemented here)." << std::endl;
        }
    } else if (getOwner() != p) {
        // Calculate rent based on number of residences owned
        int numResidencesOwned = 0;
        // TODO: This requires Board or Player to track owned properties.
        // For now, we simulate with a placeholder value:
        // Replace this logic with actual ownership tracking later.

        // Example placeholder: simulate owner has 2 residences
        numResidencesOwned = 2;  // This should be dynamically calculated

        int rent = 0;
        if (numResidencesOwned == 1) rent = 25;
        else if (numResidencesOwned == 2) rent = 50;
        else if (numResidencesOwned == 3) rent = 100;
        else if (numResidencesOwned >= 4) rent = 200;

        std::cout << p->getName() << " must pay $" << rent << " rent to " << getOwner()->getName() << "." << std::endl;
        p->addMoney(-rent);
        getOwner()->addMoney(rent);
    } else {
        std::cout << "You already own this residence." << std::endl;
    }
}
