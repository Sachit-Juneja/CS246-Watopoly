#ifndef DCTIMS_H
#define DCTIMS_H
#include <cstddef> 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "player.h"
#include "nonpropertybuilding.h"
#include "npb-specials.h"

class DCTimsLine : public NonPropertyBuilding {

    public:
        DCTimsLine(); // Constructor

        void event(Player * p) override;
};

#endif
