#include "pb-gyms.h"
#include "auction.h"
#include "player.h"
#include <iostream>

PBGyms::PBGyms(std::string name, int pos, int cost, std::string Faculty)
    : PropertyBuildingsNew(name, pos, cost, Faculty) {}

// Gym event logic
void PBGyms::event(Player *p, std::vector<Player*> allPlayers, int rollTotal) {
    std::cout << p->getName() << " landed on " << getName() << "." << std::endl;
    Auction auction;

    if (getOwner() == nullptr) {
        std::cout << "Buy for $" << getCost() << "? (y/n): ";
        char c;
        std::cin >> c;
        if (c == 'y' || c == 'Y') {
            if (p->getMoney() >= getCost()) {
                p->addMoney(-getCost());
                setOwner(p);
            } else {
                std::cout << "Insufficient funds. Auctioning..." << std::endl;
                auction.start(this, allPlayers);
            }
        } else {
            auction.start(this, allPlayers);
        }
    } else if (getOwner() != p) {
        if (isMortgaged()) {
            int price = getCost() * 0.6;
            std::cout << "Buy mortgaged gym for $" << price << "? (y/n): ";
            char c;
            std::cin >> c;
            if (c == 'y' || c == 'Y') {
                if (p->getMoney() >= price) {
                    p->addMoney(-price);
                    setOwner(p);
                    unmortgage();
                } else {
                    std::cout << "Insufficient funds. Auctioning..." << std::endl;
                    auction.start(this, allPlayers);
                }
            } else {
                auction.start(this, allPlayers);
            }
        } else {
            int gymsOwned = 1; // Replace with logic for actual count
            int rent = rollTotal * (gymsOwned == 2 ? 10 : 4);
            p->addMoney(-rent);
            getOwner()->addMoney(rent);
            std::cout << "Rent: $" << rent << " paid to " << getOwner()->getName() << "." << std::endl;
        }
    } else {
        std::cout << "You own this gym." << std::endl;
    }
}

void PBGyms::event(Player *p) {
    // Does nothing
    return;
}

