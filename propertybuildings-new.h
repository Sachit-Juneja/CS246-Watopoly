#ifndef PROPERTYBUILDINGS_NEW_H
#define PROPERTYBUILDINGS_NEW_H

#include "buildings.h"
#include "player.h"
#include <string>   
#include <vector>

class Player;

class PropertyBuildingsNew : public Buildings {
protected:
    Player *owner;
    int cost;
    bool mortgaged;
    std::string Faculty;

public:
    // Constructor: initializes name, board position, and cost
    PropertyBuildingsNew(std::string name, int pos, int cost, std::string Faculty);

    // Owner management
    Player* getOwner() const;
    void setOwner(Player *p);

    // Property cost
    int getCost() const;

    // Mortgage status
    bool isMortgaged() const;
    void mortgage();
    void unmortgage();

    // Event handling (pure virtual, subclass must define)
    virtual void event(Player *p)  = 0;

    virtual void auction();

    // new addition (Arav, Monday March 24 @ 9:23 pm): getter for faculty
    string getFaculty();

    virtual ~PropertyBuildingsNew() = default;
};

#endif
