#include "npb-specials-needleshall.h"
#include <iostream>

NPBSpecialsNeedlesHall::NPBSpecialsNeedlesHall(std::string &name, int pos)
    : NonPropertyBuilding(name, pos) {}

void NPBSpecialsNeedlesHall::event(Player *p) {
    if (specials.tryAwardCup(p)) {
        std::cout << p->getName() << " won a Roll Up the Rim cup at Needles Hall!" << std::endl;
        return;
    }

    int outcome = specials.randomnumgen(1, 18);
    int moneyChange = 0;

    if (outcome == 1) moneyChange = -200;
    else if (outcome <= 3) moneyChange = -100;
    else if (outcome <= 6) moneyChange = -50;
    else if (outcome <= 12) moneyChange = 25;
    else if (outcome <= 15) moneyChange = 50;
    else if (outcome <= 17) moneyChange = 100;
    else moneyChange = 200;

    p->addMoney(moneyChange);
    // std::cout << p->getName() << " landed on Needles Hall and ";
    if (moneyChange >= 0) std::cout << "gained $" << moneyChange << "!" << std::endl;
    else std::cout << "lost $" << -moneyChange << "!" << std::endl;
}
