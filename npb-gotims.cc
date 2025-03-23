#include "npb-gotims.h"

GoTims::GoTims(): NonPropertyBuilding{"GoTims", 30} {
        
}

GoTims::event(Player * p) {
    p->setPosition(10);
}
