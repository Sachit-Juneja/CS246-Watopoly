#include "dice.h"
#include "PRNG.h"

extern PRNG prng;  // Use global PRNG instance (defined elsewhere)
PRNG prng;  // Define global PRNG instance

#include <unistd.h>  // getpid()

Dice::Dice(bool testing) : die1(0), die2(0), testingMode(testing), testDie1(0), testDie2(0) {
    // Automatically seed with PID unless in testing mode
    if (!testingMode) {
        unsigned int seedVal = getpid();
        prng.seed(seedVal);
    }
}

void Dice::seed(unsigned int seedVal) {
    prng.seed(seedVal);
}

// Roll dice: Uses test values in testing mode, otherwise random values
int Dice::roll() { 
    if (testingMode) {
        die1 = testDie1;  // Use set test values
        die2 = testDie2;
    } else {
        die1 = prng(1, 6);  // Roll between 1 and 6 for regular mode
        die2 = prng(1, 6);
    }
    return die1 + die2;
}

bool Dice::checkDouble() const {
    return die1 == die2;
}

int Dice::checkNumber() const {
    return die1 + die2;
}

// Set test values for testing mode
void Dice::setTestRoll(int d1, int d2) {
    testingMode = true;  // Enable testing mode
    testDie1 = d1;
    testDie2 = d2;
}

int Dice::getDie1() const {
    return die1;
}

int Dice::getDie2() const {
    return die2;
}
