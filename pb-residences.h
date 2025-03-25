#ifndef PB_RESIDENCES_H
#define PB_RESIDENCES_H

#include "propertybuildings-new.h"

// PBResidences handles residence-type buildings with rent tiers based on ownership count
class PBResidences : public PropertyBuildingsNew {
public:
    PBResidences(std::string name, int pos, int cost, std::string Faculty);

    // Event when player lands on this residence
    void event(Player *p, std::vector<Player*> allPlayers);
    void event(Player *p) override;
    
    ~PBResidences() override = default;
};

#endif