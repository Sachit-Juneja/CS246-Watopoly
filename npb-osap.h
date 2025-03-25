#ifndef OSAP_H
#define OSAP_H
#include <cstddef> 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "player.h"
#include "nonpropertybuilding.h"

class Osap : public NonPropertyBuilding {
    public:
    
    void event(Player *p);

    Osap(); // Constructor
};

#endif
