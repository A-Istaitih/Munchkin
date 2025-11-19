//
// Created by Waseem Ibraheem on 12/06/2022.
//

#ifndef MATAM_EX4_CARD_H
#define MATAM_EX4_CARD_H


#include "../Name.h"
#include "../Players/Player.h"


class Card {
public:

    /**
     * Constructors + operator= + destructor for Card.
     */
    Card(Name name);
    Card(const Card& other) = default;
    Card& operator=(const Card& other) = default;
    virtual ~Card() = default;

    /**
     * Makes a copy of the object and returns a pointer to it.
     * @return a pointer to the new copy.
     */
    virtual Card* clone() const = 0;

    /**
     * Applies the card encounter to the player.
     * @param player - the player to apply the encounter to.
     */
    virtual void applyEncounter(Player& player) const = 0;



protected:
    Name m_name;

    /**
     * Prints the details of the card to os.
     * @param os - where to print the details.
     */
    virtual void printDetails(std::ostream& os) const;

private:
    friend std::ostream& operator<<(std::ostream& os, const Card& card);
};







#endif //MATAM_EX4_CARD_H
