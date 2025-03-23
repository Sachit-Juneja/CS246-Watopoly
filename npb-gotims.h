#ifndef GOTIMS_H
#define GOTIMS_H
#include <cstddef> 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "player.h"

class GoTims {
    void event(Player *p) override;

    GoTims(); // Constructor
}

#endif
