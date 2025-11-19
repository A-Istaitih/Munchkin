//
// Created by Waseem Ibraheem on 12/06/2022.
//

#include "Goblin.h"
#include "../utilities.h"


Goblin::Goblin() : BattleCard(GOBLIN_NAME, GOBLIN_FORCE, GOBLIN_LOOT, GOBLIN_HP_LOSS)
{
}

Card* Goblin::clone() const
{
    Goblin* result = new Goblin();
    return result;
}

