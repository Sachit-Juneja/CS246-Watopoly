#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
class Board; // forward declaration

class Player {

    std::string name;
    char icon;
    int currentPosition = 0;
    int money = 1500;
    int timCups = 0; 

    // How many moves the player has been in the tims line.
    // 0 = not in line
    // This number should never exceed 3 if implemented correctly.
    int inTimsLineMoves = 0; 


    friend class Board; 
    
    public:
        // static std::vector<char> players; 

        Player(int character); // Constructor
        void setPosition(int building);
        int getPosition(); 

        int getTimCups();
        void setTimCups(int cups);
  
        // Calculates and moves player directly.
        // Modifies: currentPosition
        // Returns: Index of the new position/building it is on. */
        int move(int numBuildings); 

        std::string getName();

        // Adds or removes money from the player
        // Returns: New amount of money in player after calculations.
        int addMoney(int amount); 
        int getMoney();

        void setTimsLine(int num);
        int getTimsLine();

};

#endif
