#ifndef OSAP_H
#define OSAP_H
#include <cstddef> 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "player.h"

class Osap {
    void event(Player *p) override;

    Osap(); // Constructor
}

#endif
