//
// Created by Istaitih
//

#include "Pitfall.h"
#include "../Players/Rogue.h"
#include "../utilities.h"

Pitfall::Pitfall() : Card(PITFALL_NAME)
{
}


Card* Pitfall::clone() const
{
    Pitfall* result = new Pitfall();
    return result;
}



void Pitfall::applyEncounter(Player& player) const
{
    Rogue* rogue = dynamic_cast<Rogue*>(&player);
    if(rogue == nullptr)
    {
        player.damage(PITFALL_DAMAGE_AMOUNT);
        printPitfallMessage(false);
    }
    else
    {
        printPitfallMessage(true);
    }
}
