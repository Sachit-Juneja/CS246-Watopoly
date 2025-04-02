#include "npb-dctimsline.h"
#include <limits>

DCTimsLine::DCTimsLine(): NonPropertyBuilding{"DC Tims Line", 10} {

}

void DCTimsLine::event(Player * p) {
    // If not in line
    if (p->getTimsLine() == 0) {
        cout << "You arrive at the DC Tims Line but you are not hungry. Nothing else occurs." << endl;
        return;
    }

    cout << "You are in the DC Tims Line. Please pay $50 to exit or use a Roll Up the Rim cup\n";
    cout << "Enter 'pay' to exit\n";
    cout << "Enter 'cup' to exit\n";
    cout << "Enter 'skip' to skip your turn" << endl;

    string playerInput;
    
    while (true) {
        cin >> playerInput;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear buffer
        
        // If player pays, deduct money and exit line
        if (playerInput == "pay") {
            p->addMoney(-50);
            p->setTimsLine(0);
            break;

            // If player uses Roll Up the Rim Cup, deduct cup and exit.
        } else if (playerInput == "cup") {
            int numCups = p->getTimCups();

            if (numCups >= 1) {
                p->setTimCups(numCups - 1);
                NPBSpecials::removecup(); // Remove a cup from global count
                p->setTimsLine(0);
                break;
            } else {
                cout << "You don't have any Roll Up the Rim cups. Select another option:" << endl;
                continue;
            }
            
            // If any other input, skip the turn. 
        } else if (playerInput == "skip") {
            if (p->getTimsLine() >= 3) {
                cout << "You have been in line for 3 turns and can not skip. Select another option:" << endl;
                continue;
            } else {
                p->setTimsLine(p->getTimsLine() + 1); // Increment how many turns they have been in line. 
                cout << "You have decided to skip your turn." << endl;
                break;
            }
        } else {
            cout << "Invalid input. Please enter 'pay', 'cup', or 'skip'." << endl;
            continue;
        }

    }
    
}
