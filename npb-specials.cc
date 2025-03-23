#include "npb-specials.h"
#include "PRNG.h"
#include "player.h"  // Needed to modify player's cup count

extern PRNG prng;  // Use global PRNG instance

int NPBSpecials::activeCups = 0; // Initialize static variable

NPBSpecials::NPBSpecials() {}

// Generate random number between min and max using PRNG
int NPBSpecials::randomnumgen(int min, int max) {
    return prng(min, max);
}

// Try to award a cup (1% chance). Returns true if successful.
bool NPBSpecials::tryAwardCup(Player *p) {
    if (!checkcups()) return false; // All 4 cups already active

    int chance = randomnumgen(1, 100); // Range 1 to 100
    if (chance == 1) { // 1% chance
        if (addcup()) {
            int currentCups = p->getTimCups();
            p->setTimCups(currentCups + 1); // Give cup to player
            return true;
        }
    }
    return false;
}

// Increments active cup count if < 4. Returns true if successful.
bool NPBSpecials::addcup() {
    if (activeCups < 4) {
        ++activeCups;
        return true;
    }
    return false;
}

// Check if new cups can still be issued (active < 4)
bool NPBSpecials::checkcups() const {
    return activeCups < 4;
}

// Decrease active cup count when a cup is used/discarded
void NPBSpecials::removecup() {
    if (activeCups > 0) {
        --activeCups;
    }
}
