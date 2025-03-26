#ifndef AUCTION_H
#define AUCTION_H

#include "propertybuildings-new.h"
#include "player.h"
#include <vector>


class Auction {
public:
    // Starts auction for given property and players
    void start(PropertyBuildingsNew *property, const std::vector<Player*> &players);
};

#endif
