#include "npb-coopfee.h"
#include "player.h"
#include <iostream>

NPBCoopFee::NPBCoopFee()
    : NonPropertyBuilding("Coop Fee", 38) {}

void NPBCoopFee::event(Player *p) {
    std::cout << p->getName() << " landed on Coop Fee and must pay $150." << std::endl;
    p->addMoney(-150);
}
