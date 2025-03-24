#ifndef PB_RESIDENCES_H
#define PB_RESIDENCES_H
#include "Propertybuildings.h"
#include <cstddef> 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "player.h"
using namespace std;

class Player;

class Residences : public Propertybuildings {
    //static vector<Player *> currentPlayers;
    static std::vector<Player*> currentPlayers;
    public: 
        Residences(vector<Player *> owners, int rent, Player* owner, string Faculty);
        int numOwned();  
};
#endif
