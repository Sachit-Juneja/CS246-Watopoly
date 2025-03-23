#include "npb-osap.h"

Osap::Osap(): NonPropertyBuilding{"OSAP", 0} {}

void Osap::event(Player * p) {
    p->addMoney(200);
    cout << p->getName() << " has passed OSAP and has collected $200!" << endl;
}
