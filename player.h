#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
class Board;
class Player {

    std::string name;
    char icon;
    int currentPosition = 0;
    int money = 1500;

    friend class Board; 
    
    public:
        // static std::vector<char> players; 

        Player(int character); // Constructor
        void setPosition(int building);
        int getPosition(); 
  
        // Calculates and moves player directly.
        // Modifies: currentPosition
        // Returns: Index of the new position/building it is on. */
        int move(int numBuildings); 

        std::string getName();

        // Adds or removes money from the player
        // Returns: New amount of money in player after calculations.
        int addMoney(int amount); 

        int getMoney();
};

#endif
