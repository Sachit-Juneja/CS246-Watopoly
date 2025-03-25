#ifndef PB_GYMS_H
#define PB_GYMS_H

#include "propertybuildings-new.h"

class PBGyms : public PropertyBuildingsNew {
public:
    PBGyms(std::string name, int pos, int cost, std::string Faculty);
    
    void event(Player *p) override;
    void event(Player *p, int rollTotal = 0); // Now accepts dice total. Have to double check on how we can pass that through. somehting to do with board class

    ~PBGyms() override = default;
};

#endif
