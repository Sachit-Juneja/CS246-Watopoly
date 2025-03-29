#include "buildings.h"
#include "player.h"
#include <vector>
#include <string>

// Constructor implementation
Buildings::Buildings(std::string name, int pos)
    : POS{pos}, building_name{name} {}

// Add a player to the building
void Buildings::addPlayer(Player *p) {
    currentPlayers.push_back(p);
}

// Remove a player from the building
void Buildings::removePlayer(Player *p) {
    auto it = std::find(currentPlayers.begin(), currentPlayers.end(), p);
    if (it != currentPlayers.end()) {
        currentPlayers.erase(it);
    }
}

// Return current players
std::vector<Player*> Buildings::getCurrentPlayer() {
    return currentPlayers;
}

// Return building name
std::string Buildings::getName() const {
    return building_name;
}

int Buildings::getPosition(){
    return POS;
}
