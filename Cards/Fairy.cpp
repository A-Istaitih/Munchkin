//
// Created by Waseem Ibraheem on 12/06/2022.
//

#include "Fairy.h"
#include "../Players/Wizard.h"
#include "../utilities.h"

Fairy::Fairy() : Card(FAIRY_NAME)
{
}


Card* Fairy::clone() const
{
    Fairy* result = new Fairy();
    return result;
}



void Fairy::applyEncounter(Player& player) const
{
    Wizard* wizard = dynamic_cast<Wizard*>(&player);
    if(wizard == nullptr)
    {
        printFairyMessage(false);
    }
    else
    {
        player.heal(FAIRY_HEAL_AMOUNT);
        printFairyMessage(true);
    }
}