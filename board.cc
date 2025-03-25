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

    // someone double check this. seems super sus but is working somehow?
    else if (cmd == "trade") {
        std::string otherPlayerName, give, receive;
        iss >> otherPlayerName >> give >> receive;

        // sets other players pointer
        Player *other = nullptr;
        for (auto *pl : allPlayers) {
            if (pl->getName() == otherPlayerName) {
                other = pl;
                break;
            }
        }

        //validation rahhhhh
        if (!other || other == p) {
            std::cout << "Invalid trade target.\n";
            return;
        }
    
        bool giveIsMoney = std::all_of(give.begin(), give.end(), ::isdigit);
        bool receiveIsMoney = std::all_of(receive.begin(), receive.end(), ::isdigit);
    
        if (giveIsMoney && receiveIsMoney) {
            std::cout << "Trade must involve at least one property.\n";
            return;
        }

        // is accept/reject really worth it?
        std::cout << other->getName() << ", do you accept the trade (y/n)? ";
        char c;
        std::cin >> c;
        if (c != 'y' && c != 'Y') {
            std::cout << "Trade declined.\n";
            return;
        }
    
        // Execute trade
        if (giveIsMoney) {
            int money = std::stoi(give);
            if (p->getMoney() < money) {
                std::cout << "Not enough funds to trade.\n";
                return;
            }
            auto *prop = dynamic_cast<PropertyBuildingsNew *>(getBuildingByName(receive));
            if (!prop || prop->getOwner() != other) {
                std::cout << "They don't own the requested property.\n";
                return;
            }
            p->addMoney(-money);
            other->addMoney(money);
            prop->setOwner(p);
        } else if (receiveIsMoney) {
            int money = std::stoi(receive);
            if (other->getMoney() < money) {
                std::cout << "They don't have enough money.\n";
                return;
            }
            auto *prop = dynamic_cast<PropertyBuildingsNew *>(getBuildingByName(give));
            if (!prop || prop->getOwner() != p) {
                std::cout << "You don't own the given property.\n";
                return;
            }
            p->addMoney(money);
            other->addMoney(-money);
            prop->setOwner(other);
        } else {
            auto *propGive = dynamic_cast<PropertyBuildingsNew *>(getBuildingByName(give));
            auto *propReceive = dynamic_cast<PropertyBuildingsNew *>(getBuildingByName(receive));
            if (!propGive || !propReceive || propGive->getOwner() != p || propReceive->getOwner() != other) {
                std::cout << "Invalid ownership.\n";
                return;
            }
            propGive->setOwner(other);
            propReceive->setOwner(p);
        }
    
        std::cout << "Trade completed.\n";
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

    else if (cmd == "assets") {
        Buildings *current = allBuildings[p->getPosition()];
        if (current->getName() == "Tuition") {
            std::cout << "You cannot use 'assets' while on Tuition.\n";
            return;
        }
    
        std::cout << "\nAssets for " << p->getName() << ":\n";
        std::cout << "- Cash: $" << p->getMoney() << "\n";
        std::cout << "- Properties:\n";
    
        bool ownsSomething = false;
        for (auto *b : allBuildings) {
            auto *pb = dynamic_cast<PropertyBuildingsNew *>(b);
            if (pb && pb->getOwner() == p) {
                ownsSomething = true;
                std::cout << "  * " << b->getName();
                if (auto *aca = dynamic_cast<PBAcademicBuilding *>(pb)) {
                    std::cout << " [Improvements: " << aca->getImprovementLevel() << "]";
                }
                if (pb->isMortgaged()) std::cout << " [Mortgaged]";
                std::cout << "\n";
            }
        }
        if (!ownsSomething) std::cout << "  (None)\n";
    }
    
    

    else if (cmd == "all") {
        Buildings *current = allBuildings[p->getPosition()];
        if (current->getName() == "Tuition") {
            std::cout << "You cannot use 'all' while on Tuition.\n";
            return;
        }
    
        for (auto *pl : allPlayers) {
            std::cout << "\nAssets for " << pl->getName() << ":\n";
            std::cout << "- Cash: $" << pl->getMoney() << "\n";
            std::cout << "- Properties:\n";
    
            bool ownsSomething = false;
            for (auto *b : allBuildings) {
                auto *pb = dynamic_cast<PropertyBuildingsNew *>(b);
                if (pb && pb->getOwner() == pl) {
                    ownsSomething = true;
                    std::cout << "  * " << b->getName();
                    if (auto *aca = dynamic_cast<PBAcademicBuilding *>(pb)) {
                        std::cout << " [Improvements: " << aca->getImprovementLevel() << "]";
                    }
                    if (pb->isMortgaged()) std::cout << " [Mortgaged]";
                    std::cout << "\n";
                }
            }
            if (!ownsSomething) std::cout << "  (None)\n";
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
        if (!out) {
            std::cout << "Failed to open file.\n";
            return;
        }
    
        // 1. Number of players
        out << allPlayers.size() << "\n";
        
        // 2. Player info
        for (auto *pl : allPlayers) {
            out << pl->getName() << " "
                << pl->getIcon() << " "
                << pl->getTimCups() << " "
                << pl->getMoney() << " "
                << pl->getPosition();

            if (pl->getPosition() == 10) {
                int timsLine = pl->getTimsLine();  // Number of turns in DC Tims Line
                if (timsLine > 0) {
                    out << " 1 " << timsLine;  // In line
                } else {
                    out << " 0";  // On the square, not in line
                }
            }

            out << "\n";
        }

    
        // 3. Building info
        for (auto *b : allBuildings) {
            auto *pb = dynamic_cast<PropertyBuildingsNew *>(b);
            if (!pb) continue; // skip non-ownable buildings
    
            std::string ownerName = pb->getOwner() ? pb->getOwner()->getName() : "BANK";
            int improvements = 0;
    
            if (auto *aca = dynamic_cast<PBAcademicBuilding *>(pb)) {
                improvements = aca->getImprovementLevel();
            }
    
            if (pb->isMortgaged()) improvements = -1;
    
            out << pb->getName() << " " << ownerName << " " << improvements << "\n";
        }
    
        out.close();
        std::cout << "Game saved to '" << filename << "'.\n";
    }
    

    else {
        std::cout << "Unknown command: " << cmd << std::endl;
    }
}
