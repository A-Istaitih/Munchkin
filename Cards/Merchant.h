//
// Created by Istaitih
//

#ifndef MATAM_EX4_MERCHANT_H
#define MATAM_EX4_MERCHANT_H

#include "Card.h"


const int MERCHANT_BOOST_AMOUNT = 1;
const int MERCHANT_HEAL_AMOUNT = 1;

const int PRICE_FOR_BOOST = 10;
const int PRICE_FOR_POTION = 5;

const int LEAVE_TAG = 0;
const int HEAL_TAG = 1;
const int BOOST_TAG = 2;

const std::string MERCHANT_NAME = "Merchant";

class Merchant : public Card {

public:
    /**
     * Constructors + operator= + destructor for Merchant.
     */
    Merchant();
    Merchant(const Merchant& other) = default;
    Merchant& operator=(const Merchant& other) = default;
    ~Merchant() override = default;

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
#endif //MATAM_EX4_MERCHANT_H
