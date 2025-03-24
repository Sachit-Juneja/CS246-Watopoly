#ifndef PROPERTYBUILDINGS_H
#define PROPERTYBUILDINGS_H
#include "player.h"
#include "buildings.h"
#include <cstddef> 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Propertybuildings : public Buildings{
    protected:
        int rent;
        // field called owner that is a pointer to a Player, 
        // need to reevauluate relation between a Player , Building, Property Building classes. 
        Player* owner;    
        string Faculty; // what does this field do. 
    public: 
        Propertybuildings(int rent, Player* owner, const string& Faculty, const string& name, int pos);
        virtual ~Propertybuildings() = default;
        virtual void buy(Player *p);
        virtual void auction();
        virtual int getRent(Player *p);
        virtual Player* getOwner();
        // need to figure this method out: getOwner -> since it returns a Player, do this once the above problem is figured out. 
        virtual string getFaculty();
};
#endif
