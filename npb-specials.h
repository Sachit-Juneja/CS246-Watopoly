#ifndef NPB_SPECIALS_H
#define NPB_SPECIALS_H

class Player;

class NPBSpecials {
    static int activeCups; // Global count of Roll Up the Rim cups (max 4)

public:
    NPBSpecials();

    // Generate random number between [min, max] using global PRNG
    int randomnumgen(int min, int max);

    // Try to award a cup with 1% chance to a player.
    // Returns true if the player receives a cup.
    bool tryAwardCup(Player *p);

    // Manually adds a cup to the global count (if < 4). Used internally.
    static bool addcup();

    // Can more cups be issued? (Check active < 4)
    bool checkcups() const;

    // Remove a cup from the global count (when player uses it)
    static void removecup();
};

#endif
