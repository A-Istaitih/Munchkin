//
// Created by Istaitih
//

#include "Barfight.h"
#include "../Players/Fighter.h"
#include "../utilities.h"


Barfight::Barfight() : Card(BARFIGHT_NAME)
{
}


Card* Barfight::clone() const
{
    Barfight* result = new Barfight();
    return result;
}



void Barfight::applyEncounter(Player& player) const
{
    Fighter* fighter = dynamic_cast<Fighter*>(&player);
    if(fighter == nullptr)
    {
        player.damage(BARFIGHT_DAMAGE_AMOUNT);
        printBarfightMessage(false);
    }
    else
    {
        printBarfightMessage(true);
    }
}
