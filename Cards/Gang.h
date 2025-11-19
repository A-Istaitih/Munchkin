//
// Created by Waseem Ibraheem on 19/06/2022.
//

#ifndef MATAM_EX4_GANG_H
#define MATAM_EX4_GANG_H

#include "BattleCard.h"
#include <deque>
#include <memory>

class Gang : public Card {

public:
    /**
     * Constructors + operator= + destructor for Card.
     */
    Gang();
    Gang(const Gang& other);
    Gang& operator=(const Gang& other);
    ~Gang() override = default;

    /**
     * Makes a copy of the object and returns a pointer to it.
     * @return a pointer to the new copy.
     */
    Card* clone() const override;

    /**
     * Applies the card encounter to the player.
     * @param player - the player to apply the encounter to.
     */
    void applyEncounter(Player &player) const override;

    /**
     * Adds card to the gang card and returns true. If card is not a BattleCard it doesn't add it and returns false.
     * @param card - the card to add.
     * @return true if card is a BattleCard, otherwise false.
     */
    bool addCard(std::unique_ptr<Card> card);


private:
    std::deque<std::unique_ptr<BattleCard>> m_gangCards;

    /**
     * Prints the details of the card to os.
     * @param os - where to print the details.
     */
    void printDetails(std::ostream &os) const override;

};






#endif //MATAM_EX4_GANG_H
