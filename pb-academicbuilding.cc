#include "pb-academicbuilding.h"
#include "player.h"
#include "auction.h"
#include <iostream>

PBAcademicBuilding::PBAcademicBuilding(std::string name, int pos, int cost, std::string faculty,
                                       int improvementCost, std::array<int, 6> tuitionLevels)
    : PropertyBuildingsNew(name, pos, cost, faculty),
      improvementLevel(0), improvementCost(improvementCost), tuitionLevels(tuitionLevels) {}

int PBAcademicBuilding::getTuition() const {
    return tuitionLevels[improvementLevel];
}

void PBAcademicBuilding::improve() {
    if (improvementLevel < 5) ++improvementLevel;
}

void PBAcademicBuilding::unimprove() {
    if (improvementLevel > 0) --improvementLevel;
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