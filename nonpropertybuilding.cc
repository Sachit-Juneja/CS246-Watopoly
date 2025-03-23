#include "nonpropertybuilding.h"

// Constructor passes name and position to base Buildings constructor
NonPropertyBuilding::NonPropertyBuilding(std::string &name, int pos)
    : Buildings(name, pos) {}
