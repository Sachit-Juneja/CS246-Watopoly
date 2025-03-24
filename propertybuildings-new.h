#ifndef PROPERTYBUILDINGS_NEW_H
#define PROPERTYBUILDINGS_NEW_H

#include "buildings.h"

class PropertyBuildingsNew : public Buildings {
protected:
    Player *owner;
    int cost;
    bool mortgaged;
    string Faculty;

public:
    // Constructor: initializes name, board position, and cost
    PropertyBuildingsNew(std::string name, int pos, int cost, string Faculty);

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
    virtual void event(Player *p) override = 0;

    virtual void auction();

    virtual ~PropertyBuildingsNew() = default;
};

#endif
