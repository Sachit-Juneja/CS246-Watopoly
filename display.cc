#include "display.h"
using namespace std;

void Display::draw(vector<Buildings*> buildings){
    for(auto b: buildings){
        int building_counter = 0;
        // Collect OSAP -> DC Tims Line
        for(int x = 10; x >= 1; --x){
            grid[x][10]->assignBuilding(buildings[building_counter]);
            ++building_counter;
        }
        building_counter = 11;
        // RCH -> Goose Nesting
        for(int y = 9; y >= 0; --y){
            grid[0][y]->assignBuilding(buildings[building_counter]);
            building_counter++;
        }
        // EV1 -> Go to Tims
        building_counter = 21; // wrong
        for(int x = 1; x <= 10; ++x){
            grid[x][0]->assignBuilding(buildings[building_counter]);
            ++building_counter;// wrong
        }
        // EIT -> DC
        building_counter = 31; // wrong
        for(int y = 1; y <= 9; ++y){
            grid[10][y]->assignBuilding(buildings[building_counter]);
            ++building_counter;
        }
        //building_counter should be 39 now. 
        // non empty squares (1,1) to (9,9)
        for(int i = 1; i <= 9; ++i){
            for(int j = 1; j <= 9; ++j){
                grid[i][j]->assignBuilding(nullptr);
            }
        }
    }
}

// getCoordinates: converts a player's position, p, into a 2-element array representing 
// their coordinates on the grid through the arr[] array.
int* getCoordinates(int p, int arr[]){
    // Case 1: 
    if((p >= 0) && (p <= 10)){
        arr[1] = 10;
        int x = 10 - p;
        arr[0] = x;
    }else if((p >= 11) && (p <= 20)){
        arr[0] = 0;
        arr[1] = 10 - (p - 10);
    }else if((p >= 21) && (p <= 30)){
        arr[0] = p - 20;
        arr[1] = 0;
    }else if((p >= 31) && (p <= 39)){
        arr[0] = 10;
        arr[1] = p - 30;
    }
    return arr;
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
    for(int square_line_number = 0; square_line_number < 5; ++square_line_number){
        for(int row = 0; row < 11; ++row){
            for(int col = 0; col < 11; ++col){
                cout << grid[row][col]->render(square_line_number);
            }
            cout << endl;
        }
    } 
}

