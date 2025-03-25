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

class Controller;

class Board {
    Controller *gc;
    Dice dice;
    int currentPlayerIndex = 0;
    int doublesRolled = 0;

public:
    static std::vector<Buildings *> allBuildings;
    static std::vector<Player *> allPlayers;

    Board(Controller *gc);

    void notifyObservers();

    void gameLoop();
    void handleCommand(const std::string &input);

    Player* getCurrentPlayer();
    Buildings* getBuildingByName(const std::string &name);
    void advanceTurn();
    void forceMoveToDC(Player *p);
};


#endif
