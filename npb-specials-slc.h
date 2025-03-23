#ifndef NPB_SPECIALS_SLC_H
#define NPB_SPECIALS_SLC_H

#include "nonpropertybuilding.h"
#include "npb-specials.h"
#include "player.h"

class Player;

class NPBSpecialsSLC : public NonPropertyBuilding {
    NPBSpecials specials;

public:
    // Constructor: position is passed in, name is hardcoded
    NPBSpecialsSLC(int position);
    void event(Player *p) override;
};

#endif
