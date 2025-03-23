#ifndef NPB_SPECIALS_NEEDLESHALL_H
#define NPB_SPECIALS_NEEDLESHALL_H

#include "nonpropertybuilding.h"
#include "npb-specials.h"
#include "player.h"

class NPBSpecialsNeedlesHall : public NonPropertyBuilding {
    NPBSpecials specials;

public:
    NPBSpecialsNeedlesHall(std::string &name, int pos);
    void event(Player *p) override; // Handles money change or cup award
};

#endif
