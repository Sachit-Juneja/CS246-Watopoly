#ifndef BOARD_H
#define BOARD_H
#include <cstddef> 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Local Header Files
#include "player.h"
#include "buildings.h"
#include "propertybuilding.h"
#include "nonpropertybuilding.h"

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

class Controller; // Forward declaration

// Board Class Implementation:

class Board : public Subject {

    Controller *gc; // Pointer back to the game controller

    std::vector<Buildings *> buildings; // All buildings on Board
    std::vector<Player *> players; // All Players
    Dice dice; 
    
    public:
        Board(Controller * gc); // Initializes a new game board;


        void notifyObservers() override; // Update Display

        std::vector<Buildings*> getBuidings();
        std::vector<Player*> getPlayers();
        
};


#endif
