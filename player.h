#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "buildings.h"
#include "pb-residences.h"
#include "pb-gyms.h"
#include "pb-academicbuilding.h"
#include <map> // need to verify if this is allowed for using map
using namespace std;
class Board; // forward declaration

class Player {

    std::string name;
    char icon;
    int currentPosition = 0;
    int money = 1500;
    int timCups = 0; 
    int ownedResidences;
    int ownedGyms;
    bool bankrupt = false;

    // TO DO: need to add the fields for the tims logic also. 


    // How many moves the player has been in the tims line.
    // 0 = not in line
    // This number should never exceed 3 if implemented correctly.
    int inTimsLineMoves = 0; 


    vector<Buildings*> buildings_owned; // keeps track of the buildings that the player owns. 
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

        // actions to be performed by a player
        void addBuilding(Buildings *b); // adds b to buildings_owned
        void removeBuilding(Buildings *b); // removes b from buildings_owned

        // getting a count of the Residences, Buildings, Academic Buildings (incl. Monopolies)

        // getter for numResidences owned
        int getNumResidencesOwned();

        // getter for numGyms owned
        int getGymsOwned();

        // getter for numAcademicBuildingsowned
        int getNumAcademicBuildingsOwned();

        // checking if a player has a monopoly for given faculty. 
        bool hasMonopoly(string Faculty);

        // returning the "networth" of a player
        int getTotalAssets();

        //Bankruptcy
        bool getBankruptcy();
        void setBankruptcy(bool b);        
};

#endif
