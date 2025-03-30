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
string Square::render(int line_number) {
    const int WIDTH = 13;
    string result;

    if (!building) {
        result = string(WIDTH + 2, ' ');
        return result;
    }

    auto* aca = dynamic_cast<PBAcademicBuilding*>(building);
    string name = building->getName();
    if (name.length() > WIDTH) name = name.substr(0, WIDTH);

    if (line_number == 0 || line_number == 7) {
        // Top and bottom borders
        result = "+" + string(WIDTH, '-') + "+";
    }
    else if (line_number == 1) {
        // Improvement line for academic buildings
        result = "|";
        if (aca) {
            int level = std::min(aca->getImprovementLevel(), WIDTH);
            result += string(level, 'I') + string(WIDTH - level, ' ');
        } else {
            result += name + string(WIDTH - name.length(), ' ');
        }
        result += "|";
    }
    else if (line_number == 2) {
        // Divider or blank
        if (aca) {
            result = "|" + string(WIDTH, '-') + "|";
        } else {
            result = "|" + string(WIDTH, ' ') + "|";
        }
    }
    else if (line_number == 3) {
        // Academic building name line
        if (aca) {
            result = "|" + name + string(WIDTH - name.length(), ' ') + "|";
        } else {
            result = "|" + string(WIDTH, ' ') + "|";
        }
    }
    else if (line_number == 4 || line_number == 5) {
        // Empty padding lines
        result = "|" + string(WIDTH, ' ') + "|";
    }
    else if (line_number == 6) {
        // Player icons line
        result = "|";
        string icons;
        for (auto* p : PlayersList) {
            icons += p->getIcon();
        }
        if (icons.length() > WIDTH) icons = icons.substr(0, WIDTH);
        result += icons + string(WIDTH - icons.length(), ' ') + "|";
    }

    return result;
}

// string Square::render(int line_number) {
//     ostringstream result;

//     // If no building is assigned, return 9 spaces
//     if (!building) {
//         result << "         ";
//         return result.str();
//     }

//     // Casts
//     auto* aca = dynamic_cast<PBAcademicBuilding*>(building);

//     switch (line_number) {
//         case 0:
//         case 4:
//             result << "+-------+";
//             break;
//         case 1: {
//             result << "|";
//             if (aca) {
//                 int level = aca->getImprovementLevel();
//                 for (int i = 0; i < level && i < 7; ++i)
//                     result << "I";
//                 result << string(7 - min(level, 7), ' ');
//             } else {
//                 result << "       ";
//             }
//             result << "|";
//             break;
//         }
//         case 2: {
//             result << "|";
//             string name = building->getName();
//             if (name.length() > 7) name = name.substr(0, 7);
//             result << name << string(7 - name.length(), ' ') << "|";
//             break;
//         }
//         case 3: {
//             result << "|";
//             string icons;
//             for (auto* p : PlayersList) icons += p->getIcon();
//             result << icons << string(7 - icons.length(), ' ') << "|";
//             break;
//         }
//     }

//     return result.str();
// }


void Square::clearPlayers(){
    PlayersList.clear();
}
