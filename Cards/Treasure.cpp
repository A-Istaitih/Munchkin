//
// Created by Waseem Ibraheem on 12/06/2022.
//

#include "Treasure.h"
#include "../utilities.h"

Treasure::Treasure() : Card(TREASURE_NAME)
{
}


Card* Treasure::clone() const
{
    Treasure* result = new Treasure();
    return result;
}



void Treasure::applyEncounter(Player& player) const
{
    player.addCoins(COINS_AMOUNT);
    printTreasureMessage();
}