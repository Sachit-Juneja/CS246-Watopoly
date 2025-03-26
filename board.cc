#include "board.h"

Board::Board(Controller * gc) : gc{gc} {
    // 0: OSAP
    allBuildings.emplace_back(new Osap()); 

    // 1: AL (Arts1) 
    allBuildings.emplace_back(new PBAcademicBuilding(
        "AL",    // name
        1,       // board index
        40,      // purchase cost
        "Arts1", // faculty
        50,      // improvement cost
        std::array<int,6>{2,10,30,90,160,250}
    ));

    // 2: SLC 
    allBuildings.emplace_back(new NPBSpecialsSLC(2));

    // 3: ML (Arts1) 
    allBuildings.emplace_back(new PBAcademicBuilding(
        "ML", 3, 60, "Arts1", 50,
        std::array<int,6>{4,20,60,180,320,450}
    ));

    // 4: Tuition
    allBuildings.emplace_back(new NPBTuition()); 
       // per header, hardcoded pos=4

    // 5: MKV (Residence) 
    allBuildings.emplace_back(new PBResidences(
        "MKV", 5, 200, "Residence"
    ));

    // 6: ECH (Arts2) 
    allBuildings.emplace_back(new PBAcademicBuilding(
        "ECH", 6, 100, "Arts2", 50,
        std::array<int,6>{6,30,90,270,400,550}
    ));

    // 7: Needles Hall 
    allBuildings.emplace_back(new NPBSpecialsNeedlesHall(7));


    // 8: PAS (Arts2) 
    allBuildings.emplace_back(new PBAcademicBuilding(
        "PAS", 8, 100, "Arts2", 50,
        std::array<int,6>{6,30,90,270,400,550}
    ));

    // 9: HH (Arts2) 
    allBuildings.emplace_back(new PBAcademicBuilding(
        "HH", 9, 120, "Arts2", 50,
        std::array<int,6>{8,40,100,300,450,600}
    ));

    // 10: DC Tims Line 
    allBuildings.emplace_back(new DCTimsLine()); 
       // sets pos=10 internally

    // 11: RCH (Eng) 
    allBuildings.emplace_back(new PBAcademicBuilding(
        "RCH", 11, 140, "Eng", 100,
        std::array<int,6>{10,50,150,450,625,750}
    ));

    // 12: PAC (Gym) 
    allBuildings.emplace_back(new PBGyms(
        "PAC", 12, 150, "Gym"
    ));

    // 13: DWE (Eng) 
    allBuildings.emplace_back(new PBAcademicBuilding(
        "DWE", 13, 140, "Eng", 100,
        std::array<int,6>{10,50,150,450,625,750}
    ));

    // 14: CPH (Eng) 
    allBuildings.emplace_back(new PBAcademicBuilding(
        "CPH", 14, 160, "Eng", 100,
        std::array<int,6>{12,60,180,500,700,900}
    ));

    // 15: UWP (Residence) 
    allBuildings.emplace_back(new PBResidences(
        "UWP", 15, 200, "Residence"
    ));

    // 16: LHI (Health) 
    allBuildings.emplace_back(new PBAcademicBuilding(
        "LHI", 16, 180, "Health", 100,
        std::array<int,6>{14,70,200,550,750,950}
    ));

    // 17: SLC 
    allBuildings.emplace_back(new NPBSpecialsSLC(17));


    // 18: BMH (Health) 
    allBuildings.emplace_back(new PBAcademicBuilding(
        "BMH", 18, 180, "Health", 100,
        std::array<int,6>{14,70,200,550,750,950}
    ));

    // 19: OPT (Health) 
    allBuildings.emplace_back(new PBAcademicBuilding(
        "OPT", 19, 200, "Health", 100,
        std::array<int,6>{16,80,220,600,800,1000}
    ));

    // 20: Goose Nesting 
    allBuildings.emplace_back(new NPBGooseNesting());

    // 21: EV1 (Env) 
    allBuildings.emplace_back(new PBAcademicBuilding(
        "EV1", 21, 220, "Env", 150,
        std::array<int,6>{18,90,250,700,875,1050}
    ));

    // 22: Needles Hall 
    allBuildings.emplace_back(new NPBSpecialsNeedlesHall(22));

    // 23: EV2 (Env) 
    allBuildings.emplace_back(new PBAcademicBuilding(
        "EV2", 23, 220, "Env", 150,
        std::array<int,6>{18,90,250,700,875,1050}
    ));

    // 24: EV3 (Env) 
    allBuildings.emplace_back(new PBAcademicBuilding(
        "EV3", 24, 240, "Env", 150,
        std::array<int,6>{20,100,300,750,925,1100}
    ));

    // 25: V1 (Residence) 
    allBuildings.emplace_back(new PBResidences(
        "V1", 25, 200, "Residence"
    ));

    // 26: PHYS (Sci1) 
    allBuildings.emplace_back(new PBAcademicBuilding(
        "PHYS", 26, 260, "Sci1", 150,
        std::array<int,6>{22,110,330,800,975,1150}
    ));

    // 27: B1 (Sci1) 
    allBuildings.emplace_back(new PBAcademicBuilding(
        "B1", 27, 260, "Sci1", 150,
        std::array<int,6>{22,110,330,800,975,1150}
    ));

    // 28: CIF (Gym) 
    allBuildings.emplace_back(new PBGyms(
        "CIF", 28, 150, "Gym"
    ));

    // 29: B2 (Sci1) 
    allBuildings.emplace_back(new PBAcademicBuilding(
        "B2", 29, 280, "Sci1", 150,
        std::array<int,6>{24,120,360,850,1025,1200}
    ));

    // 30: Go To Tims 
    allBuildings.emplace_back(new GoTims());

    // 31: EIT (Sci2) 
    allBuildings.emplace_back(new PBAcademicBuilding(
        "EIT", 31, 300, "Sci2", 200,
        std::array<int,6>{26,130,390,900,1100,1275}
    ));

    // 32: ESC (Sci2) 
    allBuildings.emplace_back(new PBAcademicBuilding(
        "ESC", 32, 300, "Sci2", 200,
        std::array<int,6>{26,130,390,900,1100,1275}
    ));

    // 33: SLC 
    allBuildings.emplace_back(new NPBSpecialsSLC(33));

    // 34: C2 (Sci2) 
    allBuildings.emplace_back(new PBAcademicBuilding(
        "C2", 34, 320, "Sci2", 200,
        std::array<int,6>{28,150,450,1000,1200,1400}
    ));
    
    // 35: REV (Residence) 
    allBuildings.emplace_back(new PBResidences(
        "REV", 35, 200, "Residence"
    ));

    // 36: Needles Hall 
    allBuildings.emplace_back(new NPBSpecialsNeedlesHall(36));

    // 37: MC (Math) 
    allBuildings.emplace_back(new PBAcademicBuilding(
        "MC", 37, 350, "Math", 200,
        std::array<int,6>{35,175,500,1100,1300,1500}
    ));

    // 38: Coop Fee 
    allBuildings.emplace_back(new NPBCoopFee());

    // 39: DC (Math) 
    allBuildings.emplace_back(new PBAcademicBuilding(
        "DC", 39, 400, "Math", 200,
        std::array<int,6>{50,200,600,1400,1700,2000}
    ));
}

void Board::newGame() {
    cout << "Please select the number of players (2-8): " << endl;
    int numPlayers;

    while (true) {
        cin >> numPlayers;
    
        // Check for non-integer input
        if (!cin) {
            if (cin.eof()) {
                cout << "Error - EOF detected on character number selection. Exiting game." << endl;
                exit(0);
            } else {
                cout << "Invalid input. Please enter a number between 1 and 8." << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }
        }

        if (numPlayers < 2 || numPlayers > 8) {
            cout << "Invalid number of players. Please select a number between 2 and 8." << endl;
        } else {
            break;
        }
    }

    cout << "Please select the characters for each player: " << endl;

    int i = 0;
    while (i < numPlayers) {
        cout << "Player " << i + 1 << " , please select a character (Type 1-8): " << endl;
        cout << "1. Goose" << endl;
        cout << "2. GRT Bus" << endl;
        cout << "3. Tim Hortons Doughnut" << endl;
        cout << "4. Professor" << endl;
        cout << "5. Student" << endl;
        cout << "6. Money" << endl;
        cout << "7. Laptop" << endl;
        cout << "8. Pink tie" << endl;
        
        int character;
        while (true) {
            cin >> character;

            // Check for non-integer input
            if (!cin) {
                if (cin.eof()) {
                    cout << "Error - EOF detected on character creation. Exiting game." << endl;
                    exit(0);
                } else {
                    cout << "Invalid input. Please enter a number between 1 and 8." << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }
            }

            bool alreadyChosen = false;
            
            for (Player* player : allPlayers) {
                if (player->getCharNum() == character) {
                    alreadyChosen = true;
                    break;
                }
            }

            if (character < 1 || character > 8) {
                cout << "Invalid character. Please select a number between 1 and 8." << endl;
            } else if (alreadyChosen) {
                cout << "Character already selected. Please select a different character." << endl;
            } else {
                allPlayers.emplace_back(new Player(character));
                break;
            }
        }
        i++;
    }

    cout << "All players have been selected. Starting game..." << endl;
    startGame();
    notifyObservers(); // Addition: for updating display.

}

void Board::loadGame(fstream& loadFile) {

}




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
