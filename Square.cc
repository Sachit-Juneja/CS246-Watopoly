#include "Square.h"

void Square::assignBuilding(Buildings* b){
    building = b;
}

void Square::addPlayer(Player* p){
    PlayersList.emplace_back(p);
}

void Square::removePlayer(Player* p){
    auto it = find(PlayersList.begin(), PlayersList.end(), p);
    if(it != PlayersList.end()){
        PlayersList.erase(it);
    }
}
string Square::render(int line_number){
    ostringstream out;

    if (!building) {
        /*
        logic for empty squares in the middle. */
        out << "         "; // 9 ' ' essentially.
    } else {
        PBAcademicBuilding* academic_building = dynamic_cast<PBAcademicBuilding*>(building);
        PBResidences *residences = dynamic_cast<PBResidences*>(building);
        PBGyms *gym = dynamic_cast<PBGyms*>(building);
        NonPropertyBuilding *npb = dynamic_cast<NonPropertyBuilding*>(building);

        if (academic_building) {
            if (line_number == 0) {
                out << "+-------+";
            } else if (line_number == 1) {
                int total_improvements_to_be_printed = academic_building->getImprovementLevel();
                out << "|";
                for (int i = 0; i < total_improvements_to_be_printed && i < 7; ++i) {
                    out << "I";
                }
                out << string(7 - total_improvements_to_be_printed, ' ') << "|";
            } else if (line_number == 2) {
                out << "|" << academic_building->getName().substr(0, 7);
                out << string(7 - min((size_t)7, academic_building->getName().length()), ' ') << "|";
            } else if (line_number == 3) {
                out << "|";
                for (auto p : PlayersList) {
                    out << p->getIcon();
                }
                out << string(7 - PlayersList.size(), ' ') << "|";
            } else if (line_number == 4) {
                out << "+-------+";
            }
        } else if (residences || gym) {
            if (line_number == 0) {
                out << "+-------+";
            } else if (line_number == 1) {
                string name = building->getName().substr(0, 7);
                out << "|" << name << string(7 - name.length(), ' ') << "|";
            } else if (line_number == 2) {
                out << "|       |";
            } else if (line_number == 3) {
                out << "|";
                for (auto p : PlayersList) {
                    out << p->getIcon();
                }
                out << string(7 - PlayersList.size(), ' ') << "|";
            } else if (line_number == 4) {
                out << "+-------+";
            }
        } else if (npb) {
            if (line_number == 0) {
                out << "+-------+";
            } else if (line_number == 1) {
                string name = npb->getName().substr(0, 7);
                out << "|" << name << string(7 - name.length(), ' ') << "|";
            } else if (line_number == 2) {
                out << "|       |";
            } else if (line_number == 3) {
                out << "|";
                for (auto p : PlayersList) {
                    out << p->getIcon();
                }
                out << string(7 - PlayersList.size(), ' ') << "|";
            } else if (line_number == 4) {
                out << "+-------+";
            }
        }
    }

    return out.str();
}
