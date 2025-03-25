#ifndef PB_ACADEMICBUILDING_H
#define PB_ACADEMICBUILDING_H

#include "propertybuildings-new.h"
#include <array>

class PBAcademicBuilding : public PropertyBuildingsNew {
    int improvementLevel;                     // 0 to 5
    int improvementCost;
    std::array<int, 6> tuitionLevels;         // Tuition for 0–5 improvements

public:
    PBAcademicBuilding(std::string name, int pos, int cost, std::string Faculty,
                       int improvementCost, std::array<int, 6> tuitionLevels);

    void event(Player *p) override; // this should be a virtual function right? 

    void improve();      // Add improvement
    void unimprove();    // Remove improvement
    int getTuition() const;

    // getters for improvementLevel and improvementCost
    int getImprovementLevel();
    int getImprovementCost();

    ~PBAcademicBuilding() override = default;
};

#endif
