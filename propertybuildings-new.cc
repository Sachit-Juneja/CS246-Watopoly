#include "propertybuildings-new.h"

// Constructor: passes name and position to Buildings, sets cost
PropertyBuildingsNew::PropertyBuildingsNew(std::string name, int pos, int cost, string Faculty)
    : Buildings(name, pos), cost(cost), Faculty{Faculty} {}

// Return current owner
Player* PropertyBuildingsNew::getOwner() const {
    return owner;
}

// Assign new owner
void PropertyBuildingsNew::setOwner(Player *p) {
    owner = p;
}

// Get purchase cost
int PropertyBuildingsNew::getCost() const {
    return cost;
}

// Check if property is mortgaged
bool PropertyBuildingsNew::isMortgaged() const {
    return mortgaged;
}

// Mortgage property
void PropertyBuildingsNew::mortgage() {
    mortgaged = true;
}

// Unmortgage property
void PropertyBuildingsNew::unmortgage() {
    mortgaged = false;
}

void PropertyBuildingsNew::auction() {
    std::cout << "Auction logic not yet implemented.\n";
}

string PropertyBuildingsNew::getFaculty(){
    return Faculty;
}
