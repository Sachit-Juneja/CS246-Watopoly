#ifndef BUILDINGS_H
#define BUILDINGS_H
#include <cstddef> 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#include "player.h" //-> commented out for now, will be added once Austin is done with Players.

//class Player; //forward declaration

class Buildings{
    protected:
        const int POS; // to track current position in board. (number between 0 - 39)
        string building_name;
        vector<Player *> currentPlayers;//-> uncomment once Player class is done. in Public so that Board class can access it

        public:
        // Constructor

        Buildings(string name, int pos);
    
        // Adds a player to the building
        virtual void addPlayer(Player *p);
    
        // Removes a player from the building
        virtual void removePlayer(Player *p);
    
        // Gets current players on the building
        virtual vector<Player*> getCurrentPlayer();
    
        // Event triggered when a player lands on this building
        virtual void event(Player *p) = 0;
    
        virtual ~Buildings() = default;
};    

#endif
