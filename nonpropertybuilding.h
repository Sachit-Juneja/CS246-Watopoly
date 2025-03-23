#ifndef NONPROPERTYBUILDING_H
#define NONPROPERTYBUILDING_H

#include "buildings.h"

// Abstract class for non-ownable buildings (e.g., OSAP, Goose Nesting)
class NonPropertyBuilding : public Buildings {
public:
    NonPropertyBuilding(std::string name, int pos);

    // Only event is pure virtual now; others are inherited
    virtual void event(Player *p) override = 0;

    virtual ~NonPropertyBuilding() = default;
};

#endif
