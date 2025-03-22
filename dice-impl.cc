#include "dice.h"
#include "PRNG.h"

extern PRNG prng;  // Use global PRNG instance (defined elsewhere)

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

int Dice::roll() { 
    if (testingMode) {
        die1 = testDie1;
        die2 = testDie2;
    } else {
        die1 = prng(1, 6);
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

void Dice::setTestRoll(int d1, int d2) { // purely for testing purposes and call this function to set fixed dice values
    testingMode = true;
    testDie1 = d1;
    testDie2 = d2;
}

int Dice::getDie1() const {
    return die1;
}

int Dice::getDie2() const {
    return die2;
}
