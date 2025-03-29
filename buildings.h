#ifndef BUILDINGS_H
#define BUILDINGS_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

// Forward declare Player to break circular dependencies
class Player;

class Buildings {
protected:
    const int POS;                        // Position on board (0-39)
    std::string building_name;           // Name of the building
    std::vector<Player*> currentPlayers; // Players currently on this building

public:
    Buildings(std::string name, int pos);

    // Player interaction
    virtual void addPlayer(Player *p);
    virtual void removePlayer(Player *p);
    virtual std::vector<Player*> getCurrentPlayer();

    // Called when a player lands on this building
    virtual void event(Player *p) = 0;

    int getPosition();

    virtual ~Buildings() = default;

    std::string getName() const;

    virtual int getPosition() const;  // Ensure this method exists
};

#endif
