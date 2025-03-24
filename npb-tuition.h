#ifndef NPB_TUITION_H
#define NPB_TUITION_H

#include "nonpropertybuilding.h"

class NPBTuition : public NonPropertyBuilding {
public:
    NPBTuition(); // Hardcoded name + position = 4
    void event(Player *p) override;
};

#endif
