//
// Created by Waseem Ibraheem on 12/06/2022.
//

#include "Dragon.h"
#include "../utilities.h"


Dragon::Dragon() : BattleCard(DRAGON_NAME, DRAGON_FORCE, DRAGON_LOOT, DRAGON_HP_LOSS)
{
}

Card* Dragon::clone() const
{
    Dragon* result = new Dragon();
    return result;
}

void Dragon::applyEncounter(Player& player) const
{
    if(player.getAttackStrength() >= m_force)
    {
        player.addCoins(m_loot);
        player.levelUp();
        printWinBattle(player.getName(), m_name.getName());
    }
    else
    {
        applyLoseEffect(player);
    }
}


void Dragon::printDetails(std::ostream &os) const
{
    printCardDetails(os, m_name.getName());
    printMonsterDetails(os, m_force, m_healthPointsLoss, m_loot, true);
    printEndOfCardDetails(os);
}

void Dragon::applyLoseEffect(Player &player) const
{
    player.kill();
    printLossBattle(player.getName(), m_name.getName());
}