#include "auction.h"
#include "player.h"
#include <iostream>
#include <limits>
#include "propertybuildings-new.h"

void Auction::start(PropertyBuildingsNew *property, const std::vector<Player *> &players) {
    std::cout << "Auction started for " << property->getName() << "." << std::endl;

    int highestBid = 0;
    Player *highestBidder = nullptr;

    // Track players still in the auction
    std::vector<Player *> activePlayers(players);

    // Run auction until only one player remains
    while (activePlayers.size() > 1) {
        for (auto it = activePlayers.begin(); it != activePlayers.end(); ) {
            Player *p = *it;
            
            // Remove bankrupt players
            if (p->getBankruptcy()) {
                it = activePlayers.erase(it); 
                continue;
            }

            std::cout << p->getName() << ", enter your bid (or 0 to skip): $";
            int bid;
            std::cin >> bid;

            // Input validation
            while (std::cin.fail() || bid < 0) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid bid. Enter a valid amount: $";
                std::cin >> bid;
            }

            if (bid == 0) {
                std::cout << p->getName() << " has skipped the auction." << std::endl;
                it = activePlayers.erase(it); // Remove player if they skip
                continue;
            }

            if (bid > p->getMoney()) {
                std::cout << "Insufficient funds. Bid ignored." << std::endl;
                continue;
            }

            if (bid > highestBid) {
                highestBid = bid;
                highestBidder = p;
                std::cout << p->getName() << " is now the highest bidder with $" << highestBid << "." << std::endl;
            } else {
                std::cout << "Bid is too low. Current highest bid is $" << highestBid << "." << std::endl;
            }

            ++it;
        }

        // Check if only one player remains after a round
        if (activePlayers.size() == 1) {
            break;
        }
    }

    // Determine the winner
    if (highestBidder) {
        highestBidder->addMoney(-highestBid);
        property->setOwner(highestBidder);
        std::cout << highestBidder->getName() << " wins the auction for $" << highestBid << "!" << std::endl;
    } else {
        property->setOwner(nullptr); // No bids were made so owner is BANK (this is important when someone is bankrupt so the property can be returned to the bank)
        std::cout << "No valid bids. Property remains unowned." << std::endl;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
