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

}

void Board::loadGame(fstream& loadFile) {

}

