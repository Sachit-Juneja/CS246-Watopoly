#include "pb-academicbuilding.h"
#include "player.h"
#include <iostream>

PBAcademicBuilding::PBAcademicBuilding(std::string name, int pos, int cost, std::string Faculty,
                                       int improvementCost, std::array<int, 6> tuitionLevels)
    : PropertyBuildingsNew(name, pos, cost, Faculty),
      improvementLevel(0), improvementCost(improvementCost), tuitionLevels(tuitionLevels) {}

// Event: handle purchase or rent
void PBAcademicBuilding::event(Player *p) {
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
                std::cout << "Insufficient funds." << std::endl;
            }
        } else {
            std::cout << "Property will go to auction (not implemented)." << std::endl;
        }
    } else if (getOwner() != p) {
        if (isMortgaged()) {
            std::cout << building_name << " is mortgaged. No tuition charged." << std::endl;
            return;
        }

        int tuition = getTuition();
        std::cout << p->getName() << " must pay tuition of $" << tuition << " to " << getOwner()->getName() << "." << std::endl;
        p->addMoney(-tuition);
        getOwner()->addMoney(tuition);
    } else {
        std::cout << "You own this building." << std::endl;
    }
}

// Calculate tuition based on current improvement level
int PBAcademicBuilding::getTuition() const {
    return tuitionLevels[improvementLevel];
}

// Add improvement (up to 5)
void PBAcademicBuilding::improve() {
    if (improvementLevel < 5) {
        ++improvementLevel;
        std::cout << "Improvement added. Level: " << improvementLevel << std::endl;
    } else {
        std::cout << "Maximum improvements reached." << std::endl;
    }
}

// Remove improvement (down to 0)
void PBAcademicBuilding::unimprove() {
    if (improvementLevel > 0) {
        --improvementLevel;
        std::cout << "Improvement removed. Level: " << improvementLevel << std::endl;
    } else {
        std::cout << "No improvements to remove." << std::endl;
    }
}

int PBAcademicBuilding::getImprovementCost(){
    return improvementCost;
}

int PBAcademicBuilding::getImprovementLevel(){
    return improvementLevel;
}

