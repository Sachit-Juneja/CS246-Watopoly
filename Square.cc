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

void Square::clearPlayers(){
    PlayersList.clear();
}
