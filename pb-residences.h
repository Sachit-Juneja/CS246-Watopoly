#ifndef PB_RESIDENCES_H
#define PB_RESIDENCES_H

#include "propertybuildings-new.h"

class PBResidences : public PropertyBuildingsNew {
public:
    PBResidences(std::string name, int pos, int cost, std::string Faculty);

    void event(Player *p) override;

    ~PBResidences() override = default;
};

#endif
