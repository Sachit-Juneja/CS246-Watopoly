#ifndef NONPROPERTYBUILDING_H
#define NONPROPERTYBUILDING_H

#include "buildings.h"

// Abstract class representing buildings that cannot be owned by players.
// Examples: Goose Nesting, OSAP, DC Tims Line, etc.
class NonPropertyBuilding : public Buildings {
public:
    // Constructor: initializes name and board position of the building.
    NonPropertyBuilding(std::string &name, int pos);

    // Adds a player to the current building.
    // Used when a player lands on or moves into this building.
    void addPlayer(Player *p) override;

    // Removes a player from the current building.
    // Used when a player moves out of this building.
    void removePlayer(Player *p) override;

    // Returns a list of players currently on this building.
    std::vector<Player*> getCurrentPlayer() override;

    // Abstract method to define the building-specific event that occurs
    // when a player lands on this building.
    virtual void event(Player *p) override = 0;

    // Virtual destructor.
    virtual ~NonPropertyBuilding() = default;
};

#endif
