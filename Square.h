#ifndef SQUARE_H
#define SQUARE_H
#include <cstddef> 
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <array>

// Local Header Files
#include "player.h"
#include "buildings.h"
#include "propertybuildings-new.h"
#include "nonpropertybuilding.h"
#include "pb-gyms.h"
#include "pb-residences.h"
#include "pb-academicbuilding.h"   

// Property Buildings
#include "pb-academicbuilding.h"
#include "pb-residences.h"
#include "pb-gyms.h"

// Non-Property Buildings
#include "npb-osap.h"
#include "npb-dctimsline.h"
#include "npb-gotims.h"
#include "npb-goosenesting.h"
#include "npb-tuition.h"
#include "npb-coopfee.h"
#include "npb-specials-slc.h"
#include "npb-specials-needleshall.h"

// Dice / Random
#include "dice.h"

// Observer pattern
#include "observer-observer.h"
#include "observer-subject.h"

using namespace std;

class Square{
    Buildings* building; // pointer to the building in that Square.
    vector<Player*> PlayersList; // list of players in that Square.
    // possible field for improvements
    public: 
        void assignBuilding(Buildings* b); // assigns b to building for the Square, ctor
        void addPlayer(Player* p); // adds p to PlayersList
        void removePlayer(Player *p); // removes p from PlayersList
        string render(int line_number); // returns the line(s) to print for this square, since each square has 3 lines. 
        void clearPlayers(); // clears all players from the square. 
};
#endif
