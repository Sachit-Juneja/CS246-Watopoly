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

int PBAcademicBuilding::getImprovementCost() {
    return improvementCost;
}

int PBAcademicBuilding::getImprovementLevel() {
    return improvementLevel;
}

void PBAcademicBuilding::event(Player *p, std::vector<Player *> allPlayers) {
    std::cout << p->getName() << " landed on " << getName() << "." << std::endl;
    Auction auction;
    int rent = 0;

    if (getOwner() == nullptr) {
        std::cout << "Would you like to buy " << getName() << " for $" << getCost() << "? (y/n): ";
        char c;
        std::cin >> c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear buffer
        if (c == 'y' || c == 'Y') {
            if (p->getMoney() >= getCost()) {
                if (PropertyBuildingsNew::getOwner() && PropertyBuildingsNew::getOwner() != p) {
                    PropertyBuildingsNew::getOwner()->removeBuilding(this);
                }
                p->addMoney(-getCost());
                setOwner(p);
                p->addBuilding(this);
                std::cout << p->getName() << " bought " << getName() << " for $" << getCost() << "." << std::endl;
            } else {
                std::cout << "Not enough money. Auction begins!" << std::endl;
                auction.start(this, allPlayers);
            }
        } else {
            auction.start(this, allPlayers);
        }
    } 
    else if (getOwner() != p) {
        if (isMortgaged()) {
            int discount = getCost() * 0.6;
            std::cout << "This building is mortgaged. Would you like to buy it for $" << discount << "? (y/n): ";
            char c;
            std::cin >> c;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear buffer
            if (c == 'y' || c == 'Y') {
                if (p->getMoney() >= discount) {
                    if (PropertyBuildingsNew::getOwner() && PropertyBuildingsNew::getOwner() != p) {
                        PropertyBuildingsNew::getOwner()->removeBuilding(this);
                    }
                    p->addMoney(-discount);
                    setOwner(p);
                    p->addBuilding(this);
                    unmortgage();
                    std::cout << p->getName() << " bought the mortgaged property and unmortgaged it.\n";
                } else {
                    std::cout << "Insufficient funds. Auction begins!" << std::endl;
                    auction.start(this, allPlayers);
                }
            } else {
                auction.start(this, allPlayers);
            }
        } 
        else {
            if (getOwner()->hasMonopoly(getFaculty()) && improvementLevel == 0) {
                rent = 2 * getTuition();
                std::cout << "There is a monopoly on " << getFaculty() << ". Rent is $" << rent << "." << std::endl;
            } 
            else {
                rent = getTuition();
                std::cout << "Rent is $" << getTuition() << "." << std::endl;
            }

            // Check if the player can afford the tuition
            if (p->getMoney() < rent) {
                std::cout << p->getName() << " does not have enough money to pay the tuition of $" << rent << "." << std::endl;
                std::cout << p->getName() << " must mortgage properties, trade, or declare bankruptcy." << std::endl;
                p->setBankruptcy(true);  // Set bankruptcy but wait for explicit command
                return; // Let Board handle the situation
            } 
            else {
                p->addMoney(-rent);
                getOwner()->addMoney(rent);
                std::cout << p->getName() << " pays tuition of $" << rent << " to " << getOwner()->getName() << "." << std::endl;
            }
        }
    } 
    else {
        std::cout << "You own this building." << std::endl;
    }
}

// Unused event override
void PBAcademicBuilding::event(Player *p) {
    // Does nothing
    return;
}
