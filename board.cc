#include "board.h"
#include "pb-gyms.h"
#include "pb-residences.h"
#include "pb-academicbuilding.h"
#include "npb-dctimsline.h"
#include <sstream>
#include <fstream>

std::vector<Buildings *> Board::allBuildings;
std::vector<Player *> Board::allPlayers;

Board::Board(Controller *gc) : gc{gc} {}

void Board::notifyObservers() {}

Player* Board::getCurrentPlayer() {
    return allPlayers[currentPlayerIndex];
}

Buildings* Board::getBuildingByName(const std::string &name) {
    for (auto *b : allBuildings) {
        if (b->getName() == name) return b;
    }
    return nullptr;
}

void Board::advanceTurn() {
    doublesRolled = 0;
    currentPlayerIndex = (currentPlayerIndex + 1) % allPlayers.size();
}

void Board::forceMoveToDC(Player *p) {
    std::cout << p->getName() << " rolled 3 doubles in a row! Sent to DC Tims Line." << std::endl;
    p->setPosition(10);
    p->setTimsLine(1);
}

void Board::gameLoop() {
    std::string input;
    while (true) {
        std::cout << "\n[" << getCurrentPlayer()->getName() << "] > ";
        std::getline(std::cin, input);
        if (input == "quit") break;
        handleCommand(input);
    }
}

void Board::handleCommand(const std::string &input) {
    std::istringstream iss(input);
    std::string cmd;
    iss >> cmd;
    Player *p = getCurrentPlayer();

    if (cmd == "roll") {
        int total = dice.roll();
        int die1 = dice.getDie1();
        int die2 = dice.getDie2();
        std::cout << "You rolled: " << die1 << " + " << die2 << " = " << total << std::endl;

        if (dice.checkDouble()) {
            ++doublesRolled;
            if (doublesRolled == 3) {
                forceMoveToDC(p);
                advanceTurn();
                return;
            }
            int newPos = p->move(total);
            std::cout << "Landed on " << allBuildings[newPos]->getName()
                      << " (double rolled, will roll again)\n";
            handleCommand("roll");
            return;
        }

        doublesRolled = 0;
        int newPos = p->move(total);
        Buildings *b = allBuildings[newPos];
        std::cout << "You landed on: " << b->getName() << std::endl;

        if (auto *gym = dynamic_cast<PBGyms *>(b)) {
            gym->event(p, allPlayers, total);
        } else if (auto *res = dynamic_cast<PBResidences *>(b)) {
            res->event(p, allPlayers);
        } else if (auto *aca = dynamic_cast<PBAcademicBuilding *>(b)) {
            aca->event(p, allPlayers);
        } else {
            b->event(p);
        }
    }

    else if (cmd == "next") {
        advanceTurn();
    }

    else if (cmd == "improve") {
        std::string name, action;
        iss >> name >> action;
        auto *b = dynamic_cast<PBAcademicBuilding *>(getBuildingByName(name));
        if (!b || b->getOwner() != p) {
            std::cout << "Invalid building or not yours.\n";
            return;
        }

        // Check monopoly
        std::string faculty = b->getFaculty();

        if (p->hasMonopoly(faculty)) {
            std::cout << "You have a monopoly on " << faculty << ".\n";
        } else {
            std::cout << "You do not have a monopoly on " << faculty << ".\n";
            return;
        }

        int cost = b->getImprovementCost();

        if (action == "buy") {
            if (p->getMoney() >= cost) {
                b->improve();
                p->addMoney(-cost);
                std::cout << "Improved " << name << " for $" << cost << ".\n";
            } else {
                std::cout << "Not enough money.\n";
            }
        } else if (action == "sell") {
            b->unimprove();
            p->addMoney(cost / 2);
            std::cout << "Sold improvement on " << name << ", refunded $" << cost / 2 << ".\n";
        } else {
            std::cout << "Invalid action. Use buy/sell.\n";
        }
    }

    else if (cmd == "mortgage") {
        std::string name;
        iss >> name;
        auto *pb = dynamic_cast<PropertyBuildingsNew *>(getBuildingByName(name));
        if (!pb || pb->getOwner() != p || pb->isMortgaged()) {
            std::cout << "Cannot mortgage this property.\n";
            return;
        }
        pb->mortgage();
        int amount = pb->getCost() / 2;
        p->addMoney(amount);
        std::cout << name << " mortgaged. You receive $" << amount << ".\n";
    }

    else if (cmd == "unmortgage") {
        std::string name;
        iss >> name;
        auto *pb = dynamic_cast<PropertyBuildingsNew *>(getBuildingByName(name));
        if (!pb || pb->getOwner() != p || !pb->isMortgaged()) {
            std::cout << "Cannot unmortgage this property.\n";
            return;
        }
        int amount = pb->getCost() * 0.6;
        if (p->getMoney() < amount) {
            std::cout << "Not enough money to unmortgage.\n";
            return;
        }
        p->addMoney(-amount);
        pb->unmortgage();
        std::cout << name << " unmortgaged. Paid $" << amount << ".\n";
    }

    else if (cmd == "assets") { //Awaiting Ms. Caroline
        std::cout << p->getName() << "'s money: $" << p->getMoney() << std::endl;
    }

    else if (cmd == "all") { //Awaiting Ms. Caroline
        for (auto *pl : allPlayers) {
            std::cout << pl->getName() << ": $" << pl->getMoney() << std::endl;
        }
    }

    else if (cmd == "bankrupt") {
        // GG. work on it
        std::cout << "You cannot declare bankruptcy manually. It occurs automatically when needed.\n";
    }

    else if (cmd == "save") {
        std::string filename;
        iss >> filename;
        if (filename.empty()) {
            std::cout << "Please provide a filename.\n";
            return;
        }
        std::ofstream out(filename);
        out << "Save logic not yet implemented.\n";
        out.close();
        std::cout << "Game saved to " << filename << ".\n";
    }

    else {
        std::cout << "Unknown command: " << cmd << std::endl;
    }
}
