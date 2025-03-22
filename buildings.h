#ifndef BUILDINGS_H
#define BUILDINGS_H
#include <cstddef> 
#include <iostream>
#include <vector>
#include <string>
using namespace std;
// #include "players.h" -> commented out for now, will be added once Austin is done with Players.

class Player; //forward declaration

class Building{
    protected:
        vector<Player *> currentPlayers;//-> uncomment once Player class is done. 
        int position; // to track current position in board.
        string building_name;

    public:
        virtual void addPlayer(Player *p) = 0;
        virtual void removePlayer(Player *p) = 0;
        virtual vector<Player*> getCurrentPlayer() = 0;
        virtual void event(Player *p) = 0; // handles the response of the square(building when p lands on it).
        Building(string &name, int pos);
        virtual ~Building() = default; 
};

#endif
