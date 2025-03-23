#include "buildings.h"

// Constructor: Initializes building name and position
Buildings::Buildings(string name, int pos) : building_name{name}, POS{pos} {}

// Adds a player to the currentPlayers vector
void Buildings::addPlayer(Player *p) {
    currentPlayers.push_back(p);
}

// Removes a player from the currentPlayers vector
void Buildings::removePlayer(Player *p) {
    auto it = find(currentPlayers.begin(), currentPlayers.end(), p);
    if (it != currentPlayers.end()) {
        currentPlayers.erase(it);
    }
}

// Returns the current list of players on the building
vector<Player*> Buildings::getCurrentPlayer() {
    return currentPlayers;
}
