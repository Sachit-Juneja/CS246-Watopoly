#ifndef GOTIMS_H
#define GOTIMS_H
#include <cstddef> 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "player.h"
#include "nonpropertybuilding.h"
class GoTims : public NonPropertyBuilding {

    public:
        void event(Player *p);

        GoTims(); // Constructor
};

#endif
