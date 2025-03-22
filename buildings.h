#ifndef BUILDINGS_H
#define BUILDINGS_H
#include <cstddef> 
#include <iostream>
#include <vector>
#include <string>
using namespace std;
// #include "players.h" -> commented out for now, will be added once Austin is done with Players.

class Player; //forward declaration

class Buildings{
    protected:
        const int POS; // to track current position in board. (number between 0 - 39)
        string building_name;
        vector<Player *> currentPlayers;//-> uncomment once Player class is done. in Public so that Board class can access it

    public:
        // when board class is implemented move currentPlayers to protected section and add friend class Board;
        virtual void addPlayer(Player *p) = 0;
        virtual void removePlayer(Player *p) = 0;
        virtual vector<Player*> getCurrentPlayer() = 0;
        virtual void event(Player *p) = 0; // handles the response of the square(building when p lands on it).
        Buildings(string &name, int pos);
        virtual ~Buildings() = default; 
};

#endif
