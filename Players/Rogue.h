//
// Created by Istaitih
//

#ifndef MATAM_EX4_ROGUE_H
#define MATAM_EX4_ROGUE_H

#include "Player.h"

const std::string ROGUE_JOB = "Rogue";

class Rogue : public Player {

public:
    /**
    * Constructors + operator= + destructor for Rogue.
    */
    Rogue(Name name, int maxHP = DEFAULT_MAX_HP, int force = DEFAULT_FORCE);
    Rogue(const Rogue& other) = default;
    Rogue& operator=(const Rogue& Fighter) = default;
    ~Rogue() override = default;

    /**
     * "A virtual copy constructor" that returns a pointer for the new object.
     * @return - pointer of the new object.
     */
    Player* clone() const override;

    /**
     * Adds coins for this, since this is an object of type Rogue, it adds double the amount.
     * @param coinsAmount - the coins amount to add.
     */
    void addCoins(int coinsAmount) override;

private:
    /**
    * Prints the details of this to os.
    * @param os - the output stream.
    */
    void printDetails(std::ostream& os) const override;
};


#endif //MATAM_EX4_ROGUE_H
