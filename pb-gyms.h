#ifndef PB_GYMS_H
#define PB_GYMS_H

#include "propertybuildings-new.h"

class PBGyms : public PropertyBuildingsNew {
public:
    PBGyms(std::string name, int pos, int cost, std::string Faculty);

    void event(Player *p) override;

    ~PBGyms() override = default;
};

#endif
