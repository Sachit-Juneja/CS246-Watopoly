#ifndef BUILDINGS_H
#define BUILDINGS_H
#include <cstddef> 
#include <iostream>
#include <vector>
using namespace std;
// #include "players.h" -> commented out for now, will be added once Austin is done with Players.

class Building{
    // vector<Player> currentPlayers; -> uncomment once Player class is done. 
    public:
        virtual void addPlayer() = 0;
        virtual void removePlayer() = 0;
        virtual void getCurrentPlayer() = 0;
        virtual void event() = 0;
};