#include "player.h"
#include "pb-residences.h"     
#include "pb-gyms.h"           
#include "pb-academicbuilding.h"  
#include <string>
#include <iostream>

using namespace std;

Player::Player(int character) {
    if (character == 1) {
        name = "Goose";
        icon = 'G';
    } else if (character == 2) {
        name = "GRT Bus";
        icon = 'B';
    } else if (character == 3) {
        name = "Tim Hortons Doughnut";
        icon = 'D';
    } else if (character == 4) {
        name = "Professor";
        icon = 'P';
    } else if (character == 5) {
        name = "Student";
        icon = 'S';
    } else if (character == 6) {
        name = "Money";
        icon = '$';
    } else if (character == 7) {
        name = "Laptop";
        icon = 'L';
    } else if (character == 8) {
        name = "Pink tie";
        icon = 'T';
    } else {
        // Fallback if invalid input
        cout << "PLAYER CLASS CHARACTER ERROR (LINE SHOULD NOT BE REACHED)" << endl;
    }
    charNum = character;
}
        
void Player::setPosition(int building) { //0-39
    currentPosition = building;
}

int Player::getPosition() {
    return currentPosition;
}

int Player::getCharNum() {
    return charNum;
}

char Player::getIcon() {
    return icon;
}

int Player::getTimCups() {
    return timCups;
}

void Player::setTimCups(int cups) {
    timCups = cups;
    return;
}

int Player::move(int spaces) {
    currentPosition = (((currentPosition + spaces) % 40) + 40) % 40; 
    return currentPosition;
}

string Player::getName() {
    return name;
}

bool Player::getBankruptcy() {
    return bankrupt;
}

void Player::setBankruptcy(bool b) {
    b = true;
}

int Player::addMoney(int amount) {
    money += amount;
    return money; 
}

int Player::getMoney() {
    return money;
}

void Player::setTimsLine(int num) {
    inTimsLineMoves = num;
}

int Player::getTimsLine() {
    return inTimsLineMoves;
}

void Player::addBuilding(Buildings *b){
    buildings_owned.emplace_back(b);
}

void Player::removeBuilding(Buildings *b){
    auto it = find(buildings_owned.begin(), buildings_owned.end(), b);
    if(it != buildings_owned.end()){
        buildings_owned.erase(it);
    }
}


int Player::getNumResidencesOwned(){
    /*
    1. loop (iterate using iterator) through the buildings_owned vector
    2. since each element is a pointer to a building (we have a building pointer), if this building pointer
    can be converted to a Residence pointer, we increment the counter variable for residencesOwned
    */

   // step 1: iterating through buildings_owned vector using range based for loop
   int numResidencesOwnedCounter = 0;
    for(Buildings *b: buildings_owned){
        PBResidences *residence = dynamic_cast<PBResidences *>(b);
        if(residence){
            numResidencesOwnedCounter++;
        }
    }
    return numResidencesOwnedCounter;
}

int Player::getGymsOwned(){
    /*
    1. loop (iterate using iterator) through the buildings_owned vector
    2. since each element is a pointer to a building (we have a building pointer), if this building pointer
    can be converted to a Gym pointer, we increment the counter variable for residencesOwned
    */

   // step 1: iterating through buildings_owned vector using range based for loop
   int numGymsOwnedCounter = 0;
    for(Buildings *b: buildings_owned){
        PBGyms *gym = dynamic_cast<PBGyms *>(b);
        if(gym){
            numGymsOwnedCounter++;
        }
    }
    return numGymsOwnedCounter;
}

int Player::getNumAcademicBuildingsOwned(){
   int numAcademicBuildingsowned = 0;
    for(Buildings *b: buildings_owned){
        PBAcademicBuilding *AcademicBuilding = dynamic_cast<PBAcademicBuilding *>(b);
        if(AcademicBuilding){
            numAcademicBuildingsowned++;
        }
    }
    return numAcademicBuildingsowned;
}

bool Player::hasMonopoly(string Faculty){
    // step 1: create a map where the key is the monopoly block (for academic building) and the value
    // is the number of academic buildings that come under this monopoly block. 
    map<string, int> monopoly_map = {{"Arts1", 3}, {"Arts2", 3},
                          {"Eng", 3}, {"Health", 3},
                          {"Env", 3}, {"Sci1", 3},
                          {"Sci2", 3}, {"Math", 2}};
    // loop through the 
    int monopoly_tracker_counter = 0;
    for(Buildings *b: buildings_owned){
        PBAcademicBuilding *AcademicBuilding = dynamic_cast<PBAcademicBuilding*>(b);
        if(AcademicBuilding){
            // so since now you have an academic building, want to check if the faculty matches 
            // of this academic building i.g.
            if((AcademicBuilding->getFaculty()) == Faculty){
                monopoly_tracker_counter++;
            }
        }
    }
    return (monopoly_map[Faculty] == monopoly_tracker_counter);
}

int Player::getTotalAssets(){
    int total = getMoney();
    for(Buildings *b: buildings_owned){
        PBResidences *residences = dynamic_cast<PBResidences*>(b);
        PBGyms *gym = dynamic_cast<PBGyms *>(b);
        PBAcademicBuilding *AcademicBuilding = dynamic_cast<PBAcademicBuilding*>(b);
        if(residences){
            if(residences->isMortgaged()){
                // implement
                continue;
            }else{
                // implement
                total += residences->getCost();
            }
        }else if(gym){
            if(gym->isMortgaged()){
                // implement
                continue;
            }else{
                // implement
                total += gym->getCost();
            }
        }else if(AcademicBuilding){
            if(AcademicBuilding->isMortgaged()){
                // implement
                continue;
            }else{
                // implement
                total += AcademicBuilding->getCost();
                total += AcademicBuilding->getImprovementLevel() * AcademicBuilding->getImprovementCost();
            }
        }else{
            // none of residences, gym, Academic Building
        }
    }

    return total;
}
