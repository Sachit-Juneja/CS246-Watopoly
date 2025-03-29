#ifndef DISPLAY_H
#define DISPLAY_H
#include "observer-observer.h"
#include "board.h"
#include "Square.h"
using namespace std;
class Display : public Observer{
    Board *b; // since a Disply object owns a 
    //Square *s; // to represent and render each building
    vector< vector<Square*>> grid;
    public:
        Display(Board *board, const vector<Buildings*>& buildings); 
        void draw(vector<Buildings *> buildings); // buildings comes from "allBuildings" field in board, b. 
        void notify() override; // redraws the current state of the grid. Called by the board through notifyObservers() when there is some change in the state. 
};

#endif
