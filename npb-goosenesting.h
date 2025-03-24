#ifndef NPB_GOOSENESTING_H
#define NPB_GOOSENESTING_H

#include "nonpropertybuilding.h"

class NPBGooseNesting : public NonPropertyBuilding {
public:
    NPBGooseNesting(); // Hardcoded name + position = 1
    void event(Player *p) override;
};

#endif
