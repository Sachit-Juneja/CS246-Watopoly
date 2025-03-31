#include "pb-residences.h"
#include "auction.h"
#include "player.h"
#include <iostream>

PBResidences::PBResidences(std::string name, int pos, int cost, std::string Faculty)
    : PropertyBuildingsNew(name, pos, cost, Faculty) {}

// Residence event logic
void PBResidences::event(Player *p, std::vector<Player *> allPlayers) {
    std::cout << p->getName() << " landed on " << getName() << "." << std::endl;
    Auction auction;

    if (getOwner() == nullptr) {
        std::cout << "Would you like to buy it for $" << getCost() << "? (y/n): ";
        char c;
        std::cin >> c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear buffer
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
            std::cout << "Buy mortgaged property for $" << price << "? (y/n): ";
            char c;
            std::cin >> c;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear buffer
            if (c == 'y' || c == 'Y') {
                if (p->getMoney() >= price) {
                    p->addMoney(-price);
                    setOwner(p);
                    unmortgage();
                    std::cout << p->getName() << " bought the mortgaged property and unmortgaged it.\n";
                } else {
                    std::cout << "Insufficient funds. Auctioning..." << std::endl;
                    auction.start(this, allPlayers);
                }
            } else {
                auction.start(this, allPlayers);
            }
        } 
        else {
            // Calculate rent based on number of residences owned by the owner
            int owned = getOwner()->getNumResidencesOwned(); // Owner's count
            int rent = (owned == 1 ? 25 : (owned == 2 ? 50 : (owned == 3 ? 100 : 200)));

            
            // If player can not afford, figure out if they can still pay the full amount after mortgaging. Handle all other bankrupcy/mortgaging in the Board class. We only need this code here and not in the non property buildings as in those the player pays the bank the full amount (and goes bankrupt even if they can't afford it)
            p->addMoney(-rent);
            if (p->getMoney() < 0) {
                int playerTotalPayableAssets = p->getMoney() + ((p->getTotalAssets() - p->getMoney()) / 2);
                if (playerTotalPayableAssets < rent) {

                    cout << "The bank has calculated that you can not pay rent even after mortgaging all properties. Declaring Bankruptcy is highly recommended (or you can try to mortgage your properties to no avail.)" << endl;

                } else {
                    getOwner()->addMoney(rent);
                    std::cout << p->getName() << " pays rent of $" << rent << " to " << getOwner()->getName() << "." << std::endl;
                }
            } else {
                getOwner()->addMoney(rent);
                std::cout << p->getName() << " pays rent of $" << rent << " to " << getOwner()->getName() << "." << std::endl;
            }

        }
    } 
    else {
        std::cout << "You own this residence." << std::endl;
    }
}

// Unused event override
void PBResidences::event(Player *p) {
    return;
}
