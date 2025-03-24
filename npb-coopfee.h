#ifndef NPB_COOPFEE_H
#define NPB_COOPFEE_H

#include "nonpropertybuilding.h"

class NPBCoopFee : public NonPropertyBuilding {
public:
    NPBCoopFee(); // Hardcoded name + position = 38
    void event(Player *p) override;
};

#endif
