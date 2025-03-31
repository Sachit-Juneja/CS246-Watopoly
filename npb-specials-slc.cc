#include "npb-specials-slc.h"
#include <iostream>

NPBSpecialsSLC::NPBSpecialsSLC(int position)
    : NonPropertyBuilding("SLC", position) {}

    // NPBSpecialsSLC slc1(2);
    // NPBSpecialsSLC slc2(17); HARDCODING PURPOSES!!!!!!!!!!!!!!!!                                                 
    // NPBSpecialsSLC slc3(33);
    

void NPBSpecialsSLC::event(Player *p) {
    if (specials.tryAwardCup(p)) {
        std::cout << p->getName() << " won a Roll Up the Rim cup at SLC!" << std::endl;
        return;
    }

    int outcome = specials.randomnumgen(1, 24);

    if (outcome == 1) {
        p->setPosition(10);
        p->setTimsLine(1);
        std::cout << p->getName() << " is sent to DC Tims Line!" << std::endl;
    } else if (outcome == 2) {
        p->setPosition(0);
        std::cout << p->getName() << " advances to Collect OSAP!" << std::endl;
    } else {
        int moveVal = 0;
        if (outcome <= 4) moveVal = -3;
        else if (outcome <= 8) moveVal = -2;
        else if (outcome <= 12) moveVal = -1;
        else if (outcome <= 15) moveVal = 1;
        else if (outcome <= 19) moveVal = 2;
        else moveVal = 3;

        p->move(moveVal);
        std::cout << p->getName() << " moves " << moveVal 
                  << " spaces." << std::endl;
        // Trigger event on newPos via Board
    }
}
