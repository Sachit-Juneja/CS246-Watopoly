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

    Dice dice = new Dice(); 
    
    public:

        static std::vector<Buildings *> allBuildings; // All buildings on Board
        static std::vector<Player *> allPlayers; // All Players

        Board(Controller * gc); // Initializes a new game board;

        void loadGame(fstream& loadFile); // Load a saved game
        void newGame();
        void startGame(); // Start the game
        
        void notifyObservers() override; // Update Display

};

#endif
