//
// Created by Waseem Ibraheem on 12/06/2022.
//

#ifndef MATAM_EX4_BARFIGHT_H
#define MATAM_EX4_BARFIGHT_H

#include "Card.h"


const std::string BARFIGHT_NAME = "Barfight";
const int BARFIGHT_DAMAGE_AMOUNT = 10;

class Barfight : public Card {

public:
    /**
     * Constructors + operator= + destructor for Barfight.
     */
    Barfight();
    Barfight(const Barfight& other) = default;
    Barfight& operator=(const Barfight& other) = default;
    ~Barfight() override = default;

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


#endif //MATAM_EX4_BARFIGHT_H
