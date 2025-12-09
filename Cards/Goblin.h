//
// Created by Istaitih
//

#ifndef MATAM_EX4_GOBLIN_H
#define MATAM_EX4_GOBLIN_H

#include "BattleCard.h"

const int GOBLIN_FORCE = 6;
const int GOBLIN_LOOT = 2;
const int GOBLIN_HP_LOSS = 10;
const Name GOBLIN_NAME = "Goblin";


class Goblin : public BattleCard {

public:
    /**
     * Constructors + operator= + destructor for Vampire.
     */
    Goblin();
    Goblin(const Goblin& other) = default;
    Goblin& operator=(const Goblin& other) = default;
    ~Goblin() override = default;

    /**
     * Makes a copy of the object and returns a pointer to it.
     * @return a pointer to the new copy.
     */
    Card* clone() const override;
};




#endif //MATAM_EX4_GOBLIN_H
