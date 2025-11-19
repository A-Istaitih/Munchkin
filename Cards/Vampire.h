//
// Created by Waseem Ibraheem on 12/06/2022.
//

#ifndef MATAM_EX4_VAMPIRE_H
#define MATAM_EX4_VAMPIRE_H

#include "BattleCard.h"

const int VAMPIRE_FORCE = 10;
const int VAMPIRE_LOOT = 2;
const int VAMPIRE_HP_LOSS = 10;
const int VAMPIRE_NERF_AMOUNT= 1;
const Name VAMPIRE_NAME = "Vampire";


class Vampire : public BattleCard {

public:
    /**
     * Constructors + operator= + destructor for Vampire.
     */
    Vampire();
    Vampire(const Vampire& other) = default;
    Vampire& operator=(const Vampire& other) = default;
    ~Vampire() override = default;

    /**
     * Makes a copy of the object and returns a pointer to it.
     * @return a pointer to the new copy.
     */
    Card* clone() const override;

    /**
     * Applies the card lose effect to the player.
     * @param player - the player to apply the effect to.
     */
    void applyLoseEffect(Player &player) const override;

    /**
     * Applies the card encounter to the player.
     * @param player - the player to apply the encounter to.
     */
    void applyEncounter(Player& player) const override;
};








#endif //MATAM_EX4_VAMPIRE_H
