//
// Created by Istaitih
//

#ifndef MATAM_EX4_PITFALL_H
#define MATAM_EX4_PITFALL_H

#include "Card.h"


const int PITFALL_DAMAGE_AMOUNT = 10;
const std::string PITFALL_NAME = "Pitfall";

class Pitfall : public Card {

public:
    /**
     * Constructors + operator= + destructor for Pitfall.
     */
    Pitfall();
    Pitfall(const Pitfall& other) = default;
    Pitfall& operator=(const Pitfall& other) = default;
    ~Pitfall() override = default;

    /**
     * Makes a copy of the object and returns a pointer to it.
     * @return a pointer to the new copy.
     */
    Card* clone() const override;

    /**
     * Applies the card encounter to the player.
     * @param player - the player to apply the encounter to.
     */
    void applyEncounter(Player& player) const override;

};








#endif //MATAM_EX4_PITFALL_H
