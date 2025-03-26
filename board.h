#ifndef BOARD_H
#define BOARD_H
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

class Controller;

class Board : public Subject {
    Dice dice;
    int currentPlayerIndex = 0;
    int doublesRolled = 0;
    
public:
    inline static std::vector<Buildings *> allBuildings;
    inline static std::vector<Player *> allPlayers;

    Board();

    //void notifyObservers(); not needed here - should be in the Subject class. 


    void loadGame(fstream& loadFile); // Load a saved game
    void newGame(); // Initialize the basic board. 
    void startGame(); // Start the game
        
    void gameLoop();
    void handleCommand(const std::string &input);

    Player* getCurrentPlayer();
    Buildings* getBuildingByName(const std::string &name);
    void advanceTurn();
    void forceMoveToDC(Player *p);
};


#endif
