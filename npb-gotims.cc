#include "npb-gotims.h"

GoTims::GoTims(): NonPropertyBuilding{"GoTims", 30} {
        
}

void GoTims::event(Player * p) {
    p->setPosition(10);
    p->setTimsLine(1);
    cout << p->getName() << " has been sent to DC Tims Line." << endl;
}
