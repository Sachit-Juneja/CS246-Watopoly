#include "auction.h"
#include "player.h"
#include <iostream>
#include <limits>

void Auction::start(PropertyBuildingsNew *property, const std::vector<Player*> &players) {
    std::cout << "Auction started for " << property->getName() << "." << std::endl;

    int highestBid = 0;
    Player *highestBidder = nullptr;

    for (Player *p : players) {
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

        if (bid > highestBid && bid <= p->getMoney()) {
            highestBid = bid;
            highestBidder = p;
        } else if (bid > p->getMoney()) {
            std::cout << "Insufficient funds. Bid ignored." << std::endl;
        }
    }

    if (highestBidder) {
        highestBidder->addMoney(-highestBid);
        property->setOwner(highestBidder);
        std::cout << highestBidder->getName() << " wins the auction for $" << highestBid << "!" << std::endl;
    } else {
        std::cout << "No valid bids. Property remains unowned." << std::endl;
    }
}
