#include "display.h"
using namespace std;

Display::Display(Board *board, const vector<Buildings*>& buildings){
    b = board;
    grid.resize(11, vector<Square*>(11, nullptr));
    for(int i = 0; i < 11; ++i){
        for(int j = 0; j < 11; ++j){
            grid[i][j] = new Square();
        }
    }
    draw(buildings);
}

int* getCoordinates(int p, int arr[]) {
    if (p >= 0 && p <= 10) {
        // Bottom row: right to left
        arr[0] = 10;
        arr[1] = 10 - p;
    } else if (p >= 11 && p <= 20) {
        // Left column: bottom to top
        arr[0] = 10 - (p - 10);
        arr[1] = 0;
    } else if (p >= 21 && p <= 30) {
        // Top row: left to right
        arr[0] = 0;
        arr[1] = p - 20;
    } else if (p >= 31 && p <= 39) {
        // Right column: top to bottom
        arr[0] = p - 30;
        arr[1] = 10;
    }
    return arr;
}

void Display::draw(vector<Buildings*> buildings){
    for(Buildings *b: buildings){
        int position = b->getPosition();
        int coords[2] = {0,0};
        getCoordinates(position, coords);
        grid[coords[0]][coords[1]]->assignBuilding(b);
    }
    for (int r = 1; r <= 9; ++r) {
        for (int c = 1; c <= 9; ++c) {
            grid[r][c]->assignBuilding(nullptr);
        }
    }
}


void Display::notify(){
    // Step 1: reset the set. 
    for(auto &i: grid){ // i is a vec
        for(auto &j: i){
            j->clearPlayers();
        }
    }
    // Step 2: add the players from the board class to the desired square. 
    for(Player* p: b->allPlayers){
        int position_p = p->getPosition();
        // position_p ranges from 0 to 39
        // convert 0 to 39 to in terms of [x,y] and then add [x,y] to the grid. 
        int Coordinates[2] = {0,0};
        getCoordinates(position_p, Coordinates); // implemented above
        grid[Coordinates[0]][Coordinates[1]]->addPlayer(p); 
    }
    // Step 3: print the grid out now.
    for (int r = 0; r < 11; ++r) {           // For each row
        for (int line = 0; line < 8; ++line) {  // For each line in a square
            for (int c = 0; c < 11; ++c) {   // For each column
                cout << grid[r][c]->render(line);
            }
            cout << endl;
        }
    }
}
