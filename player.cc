#include "player.h"
#include "pb-residences.h"     
#include "pb-gyms.h"           
#include "pb-academicbuilding.h"  
#include <string>
#include <iostream>

using namespace std;

Player::Player(int character, std::string actualName): actualName{actualName} {
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
    if (currentPosition + spaces > 39) {
        // If the player goes past the last building, they get $200
        addMoney(200);
    }
    currentPosition = (((currentPosition + spaces) % 40) + 40) % 40; 
    return currentPosition;
}

string Player::getName() {
    return name;
}

string Player::getActualName() {
    return actualName;
}

bool Player::getBankruptcy() {
    return bankrupt;
}

void Player::setBankruptcy(bool b) {
    bankrupt = b;
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

void Player::addBuilding(Buildings *b) {
    buildings_owned.emplace_back(b);
}

void Player::removeBuilding(Buildings *b) {
    auto it = find(buildings_owned.begin(), buildings_owned.end(), b);
    if (it != buildings_owned.end()) {
        buildings_owned.erase(it);
    }
}

int Player::getNumResidencesOwned() {
    int numResidencesOwnedCounter = 0;
    for (Buildings *b : buildings_owned) {
        PBResidences *residence = dynamic_cast<PBResidences *>(b);
        if (residence) {
            numResidencesOwnedCounter++;
        }
    }
    return numResidencesOwnedCounter;
}

int Player::getGymsOwned() {
    int numGymsOwnedCounter = 0;
    for (Buildings *b : buildings_owned) {
        PBGyms *gym = dynamic_cast<PBGyms *>(b);
        if (gym) {
            numGymsOwnedCounter++;
        }
    }
    return numGymsOwnedCounter;
}

int Player::getNumAcademicBuildingsOwned() {
    int numAcademicBuildingsowned = 0;
    for (Buildings *b : buildings_owned) {
        PBAcademicBuilding *AcademicBuilding = dynamic_cast<PBAcademicBuilding *>(b);
        if (AcademicBuilding) {
            numAcademicBuildingsowned++;
        }
    }
    return numAcademicBuildingsowned;
}

bool Player::hasMonopoly(string Faculty) {
    map<string, int> monopoly_map = {{"Arts1", 3}, {"Arts2", 3},
                                     {"Eng", 3}, {"Health", 3},
                                     {"Env", 3}, {"Sci1", 3},
                                     {"Sci2", 3}, {"Math", 2}};
    int monopoly_tracker_counter = 0;
    for (Buildings *b : buildings_owned) {
        PBAcademicBuilding *AcademicBuilding = dynamic_cast<PBAcademicBuilding *>(b);
        if (AcademicBuilding) {
            if ((AcademicBuilding->getFaculty()) == Faculty) {
                monopoly_tracker_counter++;
            }
        }
    }
    return (monopoly_map[Faculty] == monopoly_tracker_counter);
}

int Player::getTotalAssets() {
    int total = getMoney();
    for (Buildings *b : buildings_owned) {
        PBResidences *residences = dynamic_cast<PBResidences *>(b);
        PBGyms *gym = dynamic_cast<PBGyms *>(b);
        PBAcademicBuilding *AcademicBuilding = dynamic_cast<PBAcademicBuilding *>(b);
        if (residences) {
            if (!residences->isMortgaged()) {
                total += residences->getCost();
            }
        } else if (gym) {
            if (!gym->isMortgaged()) {
                total += gym->getCost();
            }
        } else if (AcademicBuilding) {
            if (!AcademicBuilding->isMortgaged()) {
                total += AcademicBuilding->getCost();
                total += AcademicBuilding->getImprovementLevel() * AcademicBuilding->getImprovementCost();
            }
        }
    }
    return total;
}

// NEW: Return list of owned buildings
std::vector<Buildings *> Player::getBuildingsOwned() const {
    return buildings_owned;
}

void Player::clearProperties() {
    buildings_owned.clear();  // Clears all owned buildings
}


// Updated declareBankruptcy
void Player::declareBankruptcy(Player *creditor) {
    setBankruptcy(true); // Mark player as bankrupt

    if (creditor) {
        std::cout << getName() << " is bankrupt! Transferring assets to " << creditor->getName() << "." << std::endl;

        // Transfer all owned properties to the creditor
        for (auto *b : buildings_owned) {
            b->addPlayer(creditor);
            creditor->addBuilding(b);
            std::cout << b->getName() << " transferred to " << creditor->getName() << "." << std::endl;
        }

        // Transfer any remaining money to creditor
        creditor->addMoney(getMoney());
    } 
    else {
        std::cout << getName() << " is bankrupt! All assets returned to the bank." << std::endl;

        // Return all properties to the bank (null ownership)
        for (auto *b : buildings_owned) {
            b->addPlayer(nullptr);
            std::cout << b->getName() << " is now available for auction." << std::endl;
        }
    }

    // Reset player’s money and properties
    addMoney(-getMoney()); // Set money to 0
    buildings_owned.clear();
}
