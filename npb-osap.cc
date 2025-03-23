#include "npb-osap.h"

Osap::Osap(): NonPropertyBuilding{"OSAP", 0} {
        
}

Osap::event(Player * p) {
    p->addMoney(200);
}
