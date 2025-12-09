//
// Created byIstaitih
//

#ifndef MATAM_EX4_BATTLECARD_H
#define MATAM_EX4_BATTLECARD_H

#include "Card.h"

class BattleCard : public Card {

public:
    /**
     * Constructors + operator= + destructor for BattleCard.
     */
    BattleCard(Name name, int force, int loot, int healthPointsLoss);
    BattleCard(const BattleCard& other) = default;
    BattleCard& operator=(const BattleCard& other) = default;
    ~BattleCard() override = default;

    /**
     * Applies the card lose effect to the player.
     * @param player - the player to apply the effect to.
     */
    virtual void applyLoseEffect(Player& player) const;

    /**
     * Applies the card encounter to the player.
     * @param player - the player to apply the encounter to.
     */
    void applyEncounter(Player &player) const override;

    /**
     * A getter for the force.
     * @return the card's force.
     */
    int getForce() const;

    /**
     * A getter for the loot.
     * @return the card's loot.
     */
    int getLoot() const;

protected:
    int m_force;
    int m_loot;
    int m_healthPointsLoss;

    /**
     * Prints the details of the card to os.
     * @param os - where to print the details.
     */
    void printDetails(std::ostream &os) const override;
};



#endif //MATAM_EX4_BATTLECARD_H
