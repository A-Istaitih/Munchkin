//
// Created by Waseem Ibraheem on 12/06/2022.
//

#ifndef MATAM_EX4_TREASURE_H
#define MATAM_EX4_TREASURE_H

#include "Card.h"

const int COINS_AMOUNT = 10;
const std::string TREASURE_NAME= "Treasure";

class Treasure : public Card {


public:
    /**
     * Constructors + operator= + destructor for Treasure.
     */
    Treasure();
    Treasure(const Treasure& other) = default;
    Treasure& operator=(const Treasure& other) = default;
    ~Treasure() override = default;

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



#endif //MATAM_EX4_TREASURE_H
