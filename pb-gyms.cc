#include "pb-gyms.h"
#include "auction.h"
#include "player.h"
#include <iostream>

PBGyms::PBGyms(std::string name, int pos, int cost, std::string Faculty)
    : PropertyBuildingsNew(name, pos, cost, Faculty) {}

// Gym event logic
void PBGyms::event(Player *p, std::vector<Player *> allPlayers, int rollTotal) {
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
                p->addBuilding(this); // new addition
                std::cout << p->getName() << " bought " << getName() << " for $" << getCost() << "." << std::endl;
            } else {
                std::cout << "Insufficient funds. Auctioning..." << std::endl;
                auction.start(this, allPlayers);
            }
        } else {
            auction.start(this, allPlayers);
        }
    } 
    else if (getOwner() != p) {
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
                    std::cout << p->getName() << " bought the mortgaged gym and unmortgaged it.\n";
                } else {
                    std::cout << "Insufficient funds. Auctioning..." << std::endl;
                    auction.start(this, allPlayers);
                }
            } else {
                auction.start(this, allPlayers);
            }
        } 
        else {
            // Calculate rent based on the number of gyms owned by the owner
            int gymsOwned = getOwner()->getGymsOwned(); // Use owner's count
            int rent = rollTotal * (gymsOwned == 2 ? 10 : 4);

            // Check if the player can pay the rent
            if (p->getMoney() < rent) {
                std::cout << p->getName() << " does not have enough money to pay the fee of $" << rent << "." << std::endl;
                std::cout << p->getName() << " must mortgage properties, trade, or declare bankruptcy." << std::endl;
                p->setBankruptcy(true);  // Set bankruptcy but wait for explicit command
                return;  // Return control to Board
            }
            
            else {
                p->addMoney(-rent);
                getOwner()->addMoney(rent);
                std::cout << p->getName() << " pays rent of $" << rent << " to " << getOwner()->getName() << "." << std::endl;
            }
        }
    } 
    else {
        std::cout << "You own this gym." << std::endl;
    }
}

// Unused event override
void PBGyms::event(Player *p) {
    // Does nothing
    return;
}
