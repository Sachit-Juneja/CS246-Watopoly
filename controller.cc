#include <iostream>
#include <unistd.h> // getpid
#include <cstring>
#include <string>
#include "PRNG.h"
#include "board.h"
#include "display.h"

using namespace std;

PRNG prng1, prng2, prng3;
extern PRNG prng1;

int main(int argc, char *argv[]) {
    uint32_t seed = getpid(); // start with a pseudo random-number
    prng1.seed( seed );
    std::string input;
    Board b = Board();
    Display d(&b, b.allBuildings);
    b.attachObservers(&d);

    cout << "Welcome to Watopoly!" << endl; 
    cout << "Please select how you want to start the game! (Enter 1 - 2)\n";
    cout << "1. New Game\n";
    cout << "2. Load Game" << endl;
    
    // Select new game or load game
    while (true) {
        cin >> input;

        if (input == "1") {
            b.newGame();
            break;
        } else if (input == "2") {
            if (argc == 3 && std::string(argv[1]) == "-load") {
                fstream loadFile = fstream(argv[2]);
                b.loadGame(loadFile);
            } else {
                cout << "No load file detected. Starting a new game..." << endl;
                b.newGame();
            }
            break;
        } else {
            cout << "Invalid input. Please enter '1' to start a new game or '2' to load a save file." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }

    // Start Game
    b.notifyObservers();
    b.gameLoop();
}

