//
// Created by Waseem Ibraheem on 12/06/2022.
//

#ifndef MATAM_EX4_FAIRY_H
#define MATAM_EX4_FAIRY_H

#include "Card.h"


const std::string FAIRY_NAME = "Fairy";
const int FAIRY_HEAL_AMOUNT = 10;

class Fairy : public Card {

public:
    /**
     * Constructors + operator= + destructor for Fairy.
     */
    Fairy();
    Fairy(const Fairy& other) = default;
    Fairy& operator=(const Fairy& other) = default;
    ~Fairy() override = default;

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








#endif //MATAM_EX4_FAIRY_H
