#include "pb-residences.h"
#include "auction.h"
#include "player.h"
#include <iostream>

PBResidences::PBResidences(std::string name, int pos, int cost, std::string Faculty)
    : PropertyBuildingsNew(name, pos, cost, Faculty) {}

// Residence event logic
void PBResidences::event(Player *p, std::vector<Player*> allPlayers) {
    std::cout << p->getName() << " landed on " << getName() << "." << std::endl;
    Auction auction;

    if (getOwner() == nullptr) {
        std::cout << "Would you like to buy it for $" << getCost() << "? (y/n): ";
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
            std::cout << "Buy mortgaged property for $" << price << "? (y/n): ";
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
            int owned = p->getNumResidencesOwned(); // Replace with actual count later
            int rent = (owned == 1 ? 25 : (owned == 2 ? 50 : (owned == 3 ? 100 : 200)));
            p->addMoney(-rent);
            getOwner()->addMoney(rent);
            std::cout << p->getName() << " pays rent of $" << rent << "." << std::endl;
        }
    } else {
        std::cout << "You own this residence." << std::endl;
    }
}