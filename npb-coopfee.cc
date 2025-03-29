#include "npb-coopfee.h"
#include "player.h"
#include <iostream>

NPBCoopFee::NPBCoopFee()
    : NonPropertyBuilding("Coop Fee", 38) {}

void NPBCoopFee::event(Player *p) {
    std::cout << p->getName() << " landed on Coop Fee and must pay $150." << std::endl;

    if (p->getMoney() < 150) {
        std::cout << "Insufficient funds! You cannot pay this amount. Declare bankruptcy or mortgage some properties!" << std::endl;
        p->setBankruptcy(true);
        return;
    }

    else {    
        p->addMoney(-150);
        std::cout << "$150 has been paid to the Bank." << std::endl;
    }    
}
