#ifndef NPB_SPECIALS_NEEDLESHALL_H
#define NPB_SPECIALS_NEEDLESHALL_H

#include "nonpropertybuilding.h"
#include "npb-specials.h"
#include "player.h"

class Player;

class NPBSpecialsNeedlesHall : public NonPropertyBuilding {
    NPBSpecials specials;

public:
    // Constructor: position is passed in, name is hardcoded
    NPBSpecialsNeedlesHall(int position);
    void event(Player *p) override;
};

#endif
