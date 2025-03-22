#ifndef DICE_H
#define DICE_H

class Dice {
private:
    int die1;
    int die2;
    bool testingMode;
    int testDie1;
    int testDie2;

public:
    Dice(bool testing = false);           // Constructor
    void seed(unsigned int seedVal);     // Seed PRNG for reproducibility
    int roll();                           // Rolls two dice, returns sum
    bool checkDouble() const;            // Returns true if die1 == die2
    int checkNumber() const;             // Sum of die1 and die2
    void setTestRoll(int d1, int d2);     // For testing mode
    int getDie1() const;
    int getDie2() const;
};

#endif // DICE_H
