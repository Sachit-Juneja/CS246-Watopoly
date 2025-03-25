#ifndef BOARD_H
#define BOARD_H
#include <cstddef> 
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

// Local Header Files
#include "player.h"
#include "buildings.h"
#include "propertybuildings-new.h"
#include "nonpropertybuilding.h"
#include "pb-gyms.h"
#include "pb-residences.h"
#include "pb-academicbuilding.h"   

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

class Board {
    Controller *gc;               // Game controller (external logic)
    Dice dice;                    // Dice system
    int currentPlayerIndex = 0;   // Current player's turn index

public:
    static std::vector<Buildings *> allBuildings; // All game buildings (ownable + special)
    static std::vector<Player *> allPlayers;      // All game players

    Board(Controller *gc);       // Initialize the board

    void notifyObservers();      // Display/observer pattern hook
    void gameLoop();             // Main command loop
    void handleCommand(const std::string &input); // Handle individual command

    Player* getCurrentPlayer();  // Current player pointer
    Buildings* getBuildingByName(const std::string &name); // Look up building
};


#endif

