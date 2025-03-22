#include "dice.h"
#include "PRNG.h"
#include <iostream>

PRNG prng;  // Define global PRNG instance

int main() {
    Dice dice;
    for (int i = 0; i < 10; ++i) {
        int sum = dice.roll();
        std::cout << "Rolled: " << dice.getDie1() << " + " << dice.getDie2();
        if (dice.checkDouble()) std::cout << " (Double!)";
        std::cout << " = " << sum << std::endl;
    }

    // Testing mode
    Dice testDice1(true);
    testDice1.setTestRoll(3, 3); // Set fixed dice values
    int testSum1 = testDice1.roll();
    std::cout << "Testing Roll: " << testDice1.getDie1() << " + " << testDice1.getDie2();
    if (testDice1.checkDouble()) std::cout << " (Double!)";
    std::cout << " = " << testSum1 << std::endl;
    Dice testDice2(true);
    testDice2.setTestRoll(2, 5);  // Not a double
    int testSum2 = testDice2.roll();
    std::cout << "Testing Roll: " << testDice2.getDie1() << " + " << testDice2.getDie2();
    if (testDice2.checkDouble()) std::cout << " (Double!)";
    std::cout << " = " << testSum2 << std::endl;
}
