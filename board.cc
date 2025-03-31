#include "board.h"

Board::Board(bool testingMode) : testingMode(testingMode) { 
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
    cout << "Please select the number of players (2-6): " << endl;
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

        if (numPlayers < 2 || numPlayers > 6) {
            cout << "Invalid number of players. Please select a number between 2 and 6." << endl;
        } else {
            break;
        }
    }

    cout << "Please select the characters for each player: " << endl;

    int i = 0;
    while (i < numPlayers) {
        // Player Name Input
        cout << "Player " << i + 1 << " , please enter your name: " << endl;
        string realName;
        while (true) {
            cin >> realName;
            if (!cin) {
                if (cin.eof()) {
                    cout << "EOF DETECTED IN NAME INPUT. EXITING GAME." << endl;
                } else {
                    cout << "Invalid Input. Please enter a valid name." << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }
            }
            cin.ignore(1000, '\n'); // Make sure that the player only entered a single word for their name, ignore rest of line. 
            
            // Check if the name is already taken or is bank
            if (realName == "BANK") {
                cout << "Name can not be BANK. Please choose a different name." << endl;
                continue;
            } else {
                bool nameTaken = false;

                for (Player* player : allPlayers) {
                    if (player->getActualName() == realName) {
                        cout << "Name already taken. Please choose a different name." << endl;
                        nameTaken = true;
                        break;
                    }
                }

                if (nameTaken) {
                    continue;
                }
            }

            // Check if the name contains numeric characters
            if (std::any_of(realName.begin(), realName.end(), ::isdigit)) {
                cout << "Name cannot contain numbers. Please choose a different name." << endl;
                continue;
            }
            
            break;
        }

        
        // Character Selection
        cout << "Hello " << realName << "! Please select a character (Type 1-8): " << endl;
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
                allPlayers.emplace_back(new Player(character, realName));
                break;
            }
        }
        i++;
    }

    cout << "All players have been selected. Starting game..." << endl;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

}

void Board::loadGame(fstream& loadFile) {
    // Load the number of players
    int numPlayers;
    loadFile >> numPlayers;

    // 1. Load basic player info
    for (int i = 0; i < numPlayers; i++) {

        string realName;
        char icon;
        int timCups;
        int money;
        int position;
        int timsLineBool;
        int timsLine;

        loadFile >> realName >> icon >> timCups >> money >> position;

        int charNum;
        if (icon == 'G') {
            charNum = 1;
        } else if (icon == 'B') {
            charNum = 2;
        } else if (icon == 'D') {
            charNum = 3;
        } else if (icon == 'P') {
            charNum = 4;
        } else if (icon == 'S') {
            charNum = 5;
        } else if (icon == '$') {
            charNum = 6;
        } else if (icon == 'L') {
            charNum = 7;
        } else if (icon == 'T') {
            charNum = 8;
        } else {
            cout << "LOAD ICON ERROR (LINE SHOULD NOT BE REACHED)" << endl;
            continue;
        }

        allPlayers.emplace_back(new Player(charNum, realName));
        Player* p = allPlayers.back();
        p->setTimCups(timCups);
        p->addMoney(money - 1500); // subtract the starting amount
        p->setPosition(position);

        // If in tims line
        if (position == 10) {
            loadFile >> timsLineBool;
            if (timsLineBool == 1) {
                loadFile >> timsLine;
                p->setTimsLine(timsLine + 1);
            } else {
                p->setTimsLine(0);
            }
        }  
        
        allBuildings[position]->addPlayer(p);
    }

    // 2. Load building info
    // loop through all property buildings using dynamic casting and then set building properties
    for (int i = 0; i < 40; i++) {

        auto *building = dynamic_cast<PropertyBuildingsNew *>(allBuildings[i]); // This is just to check type dynamically
        PropertyBuildingsNew *pb = dynamic_cast<PropertyBuildingsNew *>(allBuildings[i]); // Current building

        if (!building) {
            continue; // skip non-ownable buildings
        } else {
            string buildingName;
            string ownerName;
            int improvements;

            loadFile >> buildingName;
            
            // Since Player names can have spaces, we need to read until we find an integer (improvements)
            string tempOwnerName;
            while (true) {
                loadFile >> tempOwnerName;
                istringstream iss(tempOwnerName);
                
                if (iss >> improvements) {
                    break;
                } else {
                    if (ownerName.empty()) {
                        ownerName += tempOwnerName;
                    } else {
                        ownerName += " " + tempOwnerName;
                    }
                }
                
            }
            
            if (buildingName != pb->getName()) {
                cout << "LOAD BUILDING ERROR (LINE SHOULD NOT BE REACHED): " << buildingName <<  " DOES NOT MATCH WITH " << pb->getName() << endl;
                continue;
            }

            // Set owner and add building to owner
            if (ownerName == "BANK") {
                pb->setOwner(nullptr);
            } else {
                for (Player* p : allPlayers) {
                    if (p->getActualName() == ownerName) {
                        pb->setOwner(p);
                        p->addBuilding(pb);
                        break;
                    } else {
                        continue;
                        // THIS IS FOR TESTING PURPOSES ONLY, IT WILL ALWAYS RETURN AN ERROR IGNORE ERRORS: cout << ownerName << " OWNER MISMATCH DETECTED IN LOAD GAME WITH " << p->getActualName() << endl; 
                    }
                }
            }

            // Set improvements
            if (improvements == -1) {
                pb->mortgage();
            } else if (improvements == 0) {
                //do nothing
            } else {
                for (int i = 0; i < improvements; i++) {
                    // Since gyms and residences will never have improvements > 0, we can safely cast. 
                    dynamic_cast<PBAcademicBuilding *>(pb)->improve();
                }
            }
        }
    }

    // Print Out Load Success Function
    for (int i = 0; i < 99; i++) {
        cout << "-";
    }
    cout << endl;

    cout << "Game loaded successfully. Welcome back!" << endl;

    for (int i = 0; i < 99; i++) {
        cout << "-";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << endl << endl;
}

void Board::transferAssets(Player *from, Player *to) {
    for (Buildings *b : from->getBuildingsOwned()) {
        PropertyBuildingsNew *pb = dynamic_cast<PropertyBuildingsNew *>(b);
        pb->setOwner(to);
        to->addBuilding(b);
        std::cout << b->getName() << " transferred to " << to->getName() << "." << std::endl;
    }
    // Transfer TimCups
    while (from->getTimCups() > 0) {
        from->setTimCups(from->getTimCups()-1);
        to->setTimCups(to->getTimCups()+1);
    }

    to->addMoney(from->getMoney());
    from->addMoney(-from->getMoney());
    from->clearProperties();
}

void Board::returnAssetsToBank(Player *p) {
    Auction auction;
    for (auto *b : p->getBuildingsOwned()) {
        PropertyBuildingsNew *pb = dynamic_cast<PropertyBuildingsNew *>(b);
        pb->addPlayer(nullptr);
        std::cout << pb->getName() << " is now available for auction." << std::endl;
        auction.start(pb, allPlayers);
    }
    p->addMoney(-p->getMoney()); // Set money to zero
    p->clearProperties();
}

void Board::removePlayer(Player *p) {
    auto it = std::find(allPlayers.begin(), allPlayers.end(), p);
    if (it != allPlayers.end()) {
        std::cout << p->getName() << " has been removed from the game." << std::endl;
        allPlayers.erase(it);  // Remove the player from the list

        // Check if only one player remains after removal
        if (allPlayers.size() == 1) {
            std::cout << "🏆 The winner is " << allPlayers[0]->getName() << "! Congratulations! 🎉" << std::endl;
            exit(0);  // End the game immediately
        }
    }
}


void Board::displayCommands() {
    std::cout << "\nAvailable Commands:\n";
    std::cout << "----------------------------------------------------------------------------------\n";
    std::cout << "roll                          : Roll two dice and move your piece.\n";
    std::cout << "next                          : End your turn and give control to the next player.\n";
    std::cout << "trade <name> <give> <receive> : Offer a trade to another player.\n";
    std::cout << "    - name                    : Name of the player to trade with.\n";
    std::cout << "    - give                    : Property name or money amount to give.\n";
    std::cout << "    - receive                 : Property name or money amount to receive.\n";
    std::cout << "improve <property> buy/sell   : Buy or sell an improvement on a property.\n";
    std::cout << "    - property                : Name of the property.\n";
    std::cout << "    - buy/sell                : Buy to improve or sell to remove an improvement.\n";
    std::cout << "mortgage <property>           : Mortgage a property to gain cash.\n";
    std::cout << "unmortgage <property>         : Unmortgage a property by paying back.\n";
    std::cout << "bankrupt                      : Declare bankruptcy if you cannot pay your dues.\n";
    std::cout << "assets                        : Display the assets of the current player.\n";
    std::cout << "all                           : Display the assets of all players.\n";
    std::cout << "save <filename>               : Save the current game state to a file.\n";
    std::cout << "quit                          : Exit the game.\n";
    std::cout << "----------------------------------------------------------------------------------\n\n";
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
    hasRolled = false; // Reset the roll for the next player's turn
    std::cout << "It's now " << getCurrentPlayer()->getName() << "'s turn.\n";
}


void Board::forceMoveToDC(Player *p) {
    std::cout << p->getName() << " rolled 3 doubles in a row! Sent to DC Tims Line." << std::endl;
    p->setPosition(10);
    p->setTimsLine(1);
}

void Board::gameLoop() {
    std::string input;
    
    while (allPlayers.size() > 1) {  // Continue the game while more than one player is left
        displayCommands();
        if (getCurrentPlayer()->getMoney() < 0) {
            cout << "YOU ARE IN DEBT. YOU MUST declare bankruptcy or mortgage some properties." << endl;
        }
        std::cout << "\n[" << getCurrentPlayer()->getName() << "] > ";
        std::getline(std::cin, input);

        if (input == "quit") {
            std::cout << "Game ended manually. Goodbye!" << std::endl;
            break;
        }
        
        // If in debt, must declare bankruptcy or mortgage properties
        if (getCurrentPlayer()->getMoney() < 0) {
            getCurrentPlayer()->setBankruptcy(true);
            istringstream iss(input);
            string firstWord;
            iss >> firstWord;
            if (firstWord == "bankrupt") {
                
            } else if (firstWord == "mortgage") {
                
            } else if (firstWord == "improve") {
                
            } else if (firstWord == "assets") {
                
            } else if (firstWord == "all") {
                
            } else if (firstWord == "save") {

            } else {
                continue; // Skip the command if not valid
            }
        }
        // Handle the player's command
        handleCommand(input);

        // Check if only one player is left after each command
        if (allPlayers.size() == 1) {
            std::cout << "The winner is " << allPlayers[0]->getName() << "! Congratulations!" << std::endl;
            break;
        }
    }
}


void Board::handleCommand(const std::string &input) {
    std::istringstream iss(input);
    std::string cmd;
    iss >> cmd;
    Player *p = getCurrentPlayer();

    if (testingMode && cmd == "roll") {
        int die1, die2;
        if (iss >> die1 >> die2) {
            // Set dice values for testing
            dice.setTestRoll(die1, die2);
            int total = dice.roll();
            die1 = dice.getDie1();
            die2 = dice.getDie2();

            std::cout << "You rolled: " << die1 << " + " << die2 << " = " << total << std::endl;
            
            hasRolled = true; // Mark roll as done for this turn
    
            if (dice.checkDouble()) {
                ++doublesRolled;
    
                // If In DC Tims Line, we continue the turn.
                if (p->getPosition() == 10 && p->getTimsLine() >= 1 && p->getTimsLine() <= 3) {
                    p->setTimsLine(0);
                    std::cout << "You rolled doubles and escaped the DC Tims Line!\n";
                } else if (doublesRolled == 3) {
                    forceMoveToDC(p);
                    notifyObservers();
                    advanceTurn();
                    return;
                } else {
                    int newPos = p->move(total);
                    std::cout << "Landed on " << allBuildings[newPos]->getName()
                              << " (double rolled, will roll again)\n";
                    notifyObservers();
                    // Allow rolling again if doubles (still within turn)
                    hasRolled = false;
                    return;
                }
            }
            
            // If not a double, check for DC Tims Line or Move.
            doublesRolled = 0;
            int newPos = p->getPosition(); // Default value of new Position before moving
            Buildings *b = allBuildings[newPos]; // Default value of building before moving
    
            if (p->getPosition() == 10 && p->getTimsLine() >= 1 && p->getTimsLine() <= 3) {
                std::cout << "You did not roll doubles while in DC Tims Line. You are still in line.\n";
                b->event(p);
                if (p->getTimsLine() == 0) {
                    cout << "You have been released from the DC Tims Line!\n";
                } else {
                    return;
                }
            }
    
            newPos = p->move(total);
            b = allBuildings[newPos];
            std::cout << "You landed on: " << b->getName() << std::endl;
            notifyObservers();
            // Trigger building-specific effects
            if (auto *gym = dynamic_cast<PBGyms *>(b)) {
                gym->event(p, allPlayers, total);
            } else if (auto *res = dynamic_cast<PBResidences *>(b)) {
                res->event(p, allPlayers);
            } else if (auto *aca = dynamic_cast<PBAcademicBuilding *>(b)) {
                aca->event(p, allPlayers);
            } else {
                b->event(p);
                if (p->getTimsLine() == 1) {
                    notifyObservers(); // Notify observers only if just sent to tims line
                    cout << "You have been sent to DC Tims Line." << endl;
                }
            }
        }
    }


    if (cmd == "roll") {
        if (hasRolled) {
            cout << "You have already rolled! Please use 'next' to end your turn.\n" << endl;
            return;
        }
        
        int total = dice.roll();
        int die1 = dice.getDie1();
        int die2 = dice.getDie2();
        std::cout << "You rolled: " << die1 << " + " << die2 << " = " << total << std::endl;
    
        hasRolled = true; // Mark roll as done for this turn
    
        if (dice.checkDouble()) {
            ++doublesRolled;

            // If In DC Tims Line, we continue the turn.
            if (p->getPosition() == 10 && p->getTimsLine() >= 1 && p->getTimsLine() <= 3) {
                p->setTimsLine(0);
                std::cout << "You rolled doubles and escaped the DC Tims Line!\n";
            } else if (doublesRolled == 3) {
                forceMoveToDC(p);
                notifyObservers();
                advanceTurn();
                return;
            } else {
                int newPos = p->move(total);
                std::cout << "Landed on " << allBuildings[newPos]->getName()
                          << " (double rolled, will roll again)\n";
                notifyObservers();
                // Allow rolling again if doubles (still within turn)
                hasRolled = false;
                return;
            }
        }
        
        // If not a double, check for DC Tims Line or Move.
        doublesRolled = 0;
        int newPos = p->getPosition(); // Default value of new Position before moving
        Buildings *b = allBuildings[newPos]; // Default value of building before moving

        if (p->getPosition() == 10 && p->getTimsLine() >= 1 && p->getTimsLine() <= 3) {
            std::cout << "You did not roll doubles while in DC Tims Line. You are still in line.\n";
            b->event(p);
            if (p->getTimsLine() == 0) {
                cout << "You have been released from the DC Tims Line!\n";
            } else {
                return;
            }
        }

        newPos = p->move(total);
        b = allBuildings[newPos];
        std::cout << "You landed on: " << b->getName() << std::endl;
        notifyObservers();
        // Trigger building-specific effects
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
        if (!hasRolled) {
            std::cout << "You must roll before ending your turn. Use 'roll' to roll the dice.\n";
            return;
        }
        advanceTurn();
    }

    // someone double check this. seems super sus but is working somehow?
    else if (cmd == "trade") {
        std::string otherPlayerName, give, receive;
        iss >> otherPlayerName >> give >> receive;

        // sets other players pointer
        Player *other = nullptr;
        for (auto *pl : allPlayers) {
            if (pl->getActualName() == otherPlayerName) {
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
        std::cout << other->getActualName() << ", do you accept the trade (y/n)? ";
        char c;
        std::cin >> c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (c != 'y' && c != 'Y') {
            std::cout << "Trade declined.\n";
            return;
        }
    
        // Execute trade
        if (giveIsMoney) {
            int money = std::stoi(give);
            PropertyBuildingsNew *prop = dynamic_cast<PropertyBuildingsNew *>(getBuildingByName(receive));

            bool hasimprovement = false;
            
            // Check if the property an academic building
            PBAcademicBuilding *receiveAcademicBuilding = dynamic_cast<PBAcademicBuilding *>(prop);
            if (receiveAcademicBuilding && other->hasMonopoly(receiveAcademicBuilding->getFaculty())) {
                for (Buildings *b : other->getBuildingsOwned()) { // Pretty sure it's better if getBuildingsOwned() returns a propertyBuilding, but I'll keep it this way for now.
                    PBAcademicBuilding *iterateAcademicBuilding = dynamic_cast<PBAcademicBuilding *>(b);

                    if ((iterateAcademicBuilding->getImprovementLevel() > 0) && (iterateAcademicBuilding->getFaculty() == receiveAcademicBuilding->getFaculty())) {
                        hasimprovement = true;
                        break;
                    }
                }
            }

            if (p->getMoney() < money) {
                std::cout << "Not enough funds to trade.\n";
                return;
            }
            if (!prop || prop->getOwner() != other) {
                std::cout << "They don't own the requested property.\n";
                return;
            }
            if(hasimprovement){
                std::cout << "You trade a building in a monopoly that has improvements. Please sell all improvements on the monopoly first.\n";
                return;
            }
            p->addMoney(-money);
            other->addMoney(money);
            prop->setOwner(p);
        } else if (receiveIsMoney) { 
            // ----------------------------
            // Recieve Money, Give Property
            // ----------------------------
            int money = std::stoi(receive);
            auto *prop = dynamic_cast<PropertyBuildingsNew *>(getBuildingByName(give));

            bool hasimprovement = false;
            
            // Check if the property an academic building
            PBAcademicBuilding *receiveAcademicBuilding = dynamic_cast<PBAcademicBuilding *>(prop);
            if (receiveAcademicBuilding && p->hasMonopoly(receiveAcademicBuilding->getFaculty())) {
                for (Buildings *b : p->getBuildingsOwned()) { // Pretty sure it's better if getBuildingsOwned() returns a propertyBuilding, but I'll keep it this way for now.
                    PBAcademicBuilding *iterateAcademicBuilding = dynamic_cast<PBAcademicBuilding *>(b);

                    if ((iterateAcademicBuilding->getImprovementLevel() > 0) && (iterateAcademicBuilding->getFaculty() == receiveAcademicBuilding->getFaculty())) {
                        hasimprovement = true;
                        break;
                    }
                }
            }

            if (other->getMoney() < money) {
                std::cout << "They don't have enough money.\n";
                return;
            }
            if (!prop || prop->getOwner() != p) {
                std::cout << "You don't own the given property.\n";
                return;
            }
            if(hasimprovement){
                std::cout << "You cannot trade a building in a monopoly that has improvements. Please sell all improvements on the monopoly first.\n";
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
            if(b->getImprovementLevel() >= 5){
                cout << "Cannot add any more improvements for " << name << endl;
                return;
            }
            if(p->getMoney() >= cost) {
                b->improve();
                p->addMoney(-cost);
                std::cout << "Improved " << name << " for $" << cost << ".\n";
                notifyObservers();
            }else{
                std::cout << "Not enough money.\n";
            }
        } else if (action == "sell") {
            b->unimprove();
            p->addMoney(cost / 2);
            std::cout << "Sold improvement on " << name << ", refunded $" << cost / 2 << ".\n";
            notifyObservers();
        } else {
            std::cout << "Invalid action. Use buy/sell.\n";
        }
    }

    else if (cmd == "mortgage") {
        std::string name;
        iss >> name;
        PropertyBuildingsNew *pb = dynamic_cast<PropertyBuildingsNew *>(getBuildingByName(name));

        bool hasimprovement = false;
        // Check if the property an academic building
        PBAcademicBuilding *mortgageAcademicBuilding = dynamic_cast<PBAcademicBuilding *>(pb);
        if (mortgageAcademicBuilding && p->hasMonopoly(mortgageAcademicBuilding->getFaculty())) {
            for (Buildings *b : p->getBuildingsOwned()) { // Pretty sure it's better if getBuildingsOwned() returns a propertyBuilding, but I'll keep it this way for now.
                PBAcademicBuilding *iterateAcademicBuilding = dynamic_cast<PBAcademicBuilding *>(b);
                if ((iterateAcademicBuilding->getImprovementLevel() > 0) && (iterateAcademicBuilding->getFaculty() == mortgageAcademicBuilding->getFaculty())) {
                    hasimprovement = true;
                    break;
                }
            }
        }

        if (!pb || pb->getOwner() != p || pb->isMortgaged()) {
            std::cout << "Cannot mortgage this property.\n";
            return;
        }
        if(hasimprovement){
            std::cout << "You cannot mortgage a building in a monopoly that has improvements. Please sell all improvements on the monopoly first.\n";
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
    
        std::cout << "\nAssets for " << p->getActualName() << " (" << p->getName() << "):\n";
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
            std::cout << "\nAssets for " << pl->getActualName() << " (" << pl->getName() << "):\n";
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
        if (!p->getBankruptcy()) {
            std::cout << "You cannot declare bankruptcy at this time. You must be unable to pay a debt." << std::endl;
            return;
        }

        // Determine creditor if applicable
        Player *creditor = nullptr;
        for (auto *b : allBuildings) {
            PropertyBuildingsNew *pb = dynamic_cast<PropertyBuildingsNew *>(b);
            if (pb && pb->getOwner() != p && p->getPosition() == pb->getPosition()) {
                creditor = pb->getOwner();
                break;
            }
        }
    
        // Handle bankruptcy: Transfer assets or return to bank
        std::cout << p->getName() << " has declared bankruptcy!" << std::endl;
        if (creditor) {
            std::cout << "Assets transferred to " << creditor->getName() << "." << std::endl;
            transferAssets(p, creditor);
        } else {
            std::cout << "All assets returned to the bank." << std::endl;
            returnAssetsToBank(p);
        }
    
        // Remove the player from the game
        removePlayer(p);
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
            out << pl->getActualName() << " "
                << pl->getIcon() << " "
                << pl->getTimCups() << " "
                << pl->getMoney() << " "
                << pl->getPosition();

            if (pl->getPosition() == 10) {
                int timsLine = pl->getTimsLine();  // Number of turns in DC Tims Line
                if (timsLine > 0) {
                    out << " 1 " << (timsLine - 1);  // In line
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
    
            std::string ownerName = pb->getOwner() ? pb->getOwner()->getActualName() : "BANK";
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
