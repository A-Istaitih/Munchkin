//
// Created by Istaitih
//

#ifndef MATAM_EX4_DRAGON_H
#define MATAM_EX4_DRAGON_H

#include "BattleCard.h"

const int DRAGON_FORCE = 25;
const int DRAGON_LOOT = 1000;
const int DRAGON_HP_LOSS = 100;
const Name DRAGON_NAME = "Dragon";


class Dragon : public BattleCard {

public:
    /**
     * Constructors + operator= + destructor for Dragon.
     */
    Dragon();
    Dragon(const Dragon& other) = default;
    Dragon& operator=(const Dragon& other) = default;
    ~Dragon() override = default;

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

    /**
     * Applies the card lose effect to the player.
     * @param player - the player to apply the effect to.
     */
    void applyLoseEffect(Player &player) const override;

private:
    /**
     * Prints the details of the card to os.
     * @param os - where to print the details.
     */
    void printDetails(std::ostream &os) const override;
};









#endif //MATAM_EX4_DRAGON_H
