//
// Created by Istaitih
//

#include "Vampire.h"
#include "../utilities.h"

Vampire::Vampire() : BattleCard(VAMPIRE_NAME, VAMPIRE_FORCE, VAMPIRE_LOOT, VAMPIRE_HP_LOSS)
{
}

Card* Vampire::clone() const
{
    Vampire* result = new Vampire();
    return result;
}

void Vampire::applyEncounter(Player& player) const
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

void Vampire::applyLoseEffect(Player &player) const
{
    player.damage(m_healthPointsLoss);
    player.nerf(VAMPIRE_NERF_AMOUNT);
    printLossBattle(player.getName(), m_name.getName());
}
