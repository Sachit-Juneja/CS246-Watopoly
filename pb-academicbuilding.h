#ifndef PB_ACADEMICBUILDING_H
#define PB_ACADEMICBUILDING_H

#include "propertybuildings-new.h"
#include <array>

// Academic building class handles rent based on improvement levels (0-5)
class PBAcademicBuilding : public PropertyBuildingsNew {
    int improvementLevel;                     // Current improvement level
    int improvementCost;                      // Cost to add an improvement
    std::array<int, 6> tuitionLevels;         // Tuition for 0–5 improvements

public:
    // Constructor
    PBAcademicBuilding(std::string name, int pos, int cost, std::string faculty,
                       int improvementCost, std::array<int, 6> tuitionLevels);

    // Handles player landing on this property
    virtual void event(Player *p, std::vector<Player*> allPlayers) = 0;

    // Manage improvements
    void improve();
    void unimprove();
    int getTuition() const;

    ~PBAcademicBuilding() override = default;
};

#endif