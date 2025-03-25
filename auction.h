#ifndef AUCTION_H
#define AUCTION_H

#include "propertybuildings-new.h"
#include <vector>

class Player; // Forward declaration

class Auction {
public:
    // Starts auction for given property and players
    void start(PropertyBuildingsNew *property, const std::vector<Player*> &players);
};

#endif
