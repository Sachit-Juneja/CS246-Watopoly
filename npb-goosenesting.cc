#include "npb-goosenesting.h"
#include <iostream>

NPBGooseNesting::NPBGooseNesting()
    : NonPropertyBuilding("Goose Nesting", 20) {}

void NPBGooseNesting::event(Player *p) {
    std::cout << p->getName() << " has been attacked by nesting geese at Goose Nesting... but nothing happens." << std::endl;
}
