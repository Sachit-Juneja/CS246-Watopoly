#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {

    std::string name;
    int currentPosition = 0;
    int money = 1500;
    
    public:
        Player(std::string name); // Constructor
        
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
