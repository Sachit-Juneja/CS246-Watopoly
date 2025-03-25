#include "pb-academicbuilding.h"
#include "player.h"
#include "auction.h"
#include <iostream>

PBAcademicBuilding::PBAcademicBuilding(std::string name, int pos, int cost, std::string Faculty, int improvementCost, std::array<int, 6> tuitionLevels)
    : PropertyBuildingsNew(name, pos, cost, Faculty), improvementLevel(0), improvementCost(improvementCost), tuitionLevels(tuitionLevels) {}

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


void PBAcademicBuilding::event(Player *p, std::vector<Player*> allPlayers) {
    std::cout << p->getName() << " landed on " << getName() << "." << std::endl;
    Auction auction;

    if (getOwner() == nullptr) {
        std::cout << "Would you like to buy " << getName() << " for $" << getCost() << "? (y/n): ";
        char c;
        std::cin >> c;
        if (c == 'y' || c == 'Y') {
            if (p->getMoney() >= getCost()) {
                p->addMoney(-getCost());
                setOwner(p);
            } else {
                std::cout << "Not enough money. Auction begins!" << std::endl;
                auction.start(this, allPlayers);
            }
        } else {
            auction.start(this, allPlayers);
        }
    } else if (getOwner() != p) {
        if (isMortgaged()) {
            int discount = getCost() * 0.6;
            std::cout << "This building is mortgaged. Would you like to buy it for $" << discount << "? (y/n): ";
            char c;
            std::cin >> c;
            if (c == 'y' || c == 'Y') {
                if (p->getMoney() >= discount) {
                    p->addMoney(-discount);
                    setOwner(p);
                    unmortgage();
                } else {
                    std::cout << "Insufficient funds. Auction begins!" << std::endl;
                    auction.start(this, allPlayers);
                }
            } else {
                auction.start(this, allPlayers);
            }
        } else {
            int rent = getTuition();
            std::cout << "Paying tuition of $" << rent << " to " << getOwner()->getName() << "." << std::endl;
            p->addMoney(-rent);
            getOwner()->addMoney(rent);
        }
    } else {
        std::cout << "You own this building." << std::endl;
    }
}


void PBAcademicBuilding::event(Player *p) {
    return;
}
