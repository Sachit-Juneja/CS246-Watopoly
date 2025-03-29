#ifndef PB_GYMS_H
#define PB_GYMS_H

#include "propertybuildings-new.h"
#include <vector>
#include <limits>

class Player;

// PBGyms handles gym-type properties where rent depends on dice roll and ownership count
class PBGyms : public PropertyBuildingsNew {
public:
    // Constructor
    PBGyms(std::string name, int pos, int cost, std::string Faculty);
    
    void event(Player *p);

    // Handles event when a player lands on this gym
    void event(Player *p, std::vector<Player*> allPlayers, int rollTotal); // Now accepts dice total. Have to double check on how we can pass that through. somehting to do with board class

    ~PBGyms() = default;
};

#endif