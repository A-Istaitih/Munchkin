//
// Created by Waseem Ibraheem on 13/06/2022.
//

#include "BattleCard.h"
#include "../utilities.h"

BattleCard::BattleCard(Name name, int force, int loot, int healthPointsLoss) : Card(name), m_force(force),
                                                                               m_loot(loot),
                                                                               m_healthPointsLoss(healthPointsLoss)
{
}

void BattleCard::printDetails(std::ostream &os) const
{
    printCardDetails(os, m_name.getName());
    printMonsterDetails(os, m_force, m_healthPointsLoss, m_loot, false);
    printEndOfCardDetails(os);
}

void BattleCard::applyLoseEffect(Player& player) const
{
    player.damage(m_healthPointsLoss);
    printLossBattle(player.getName(), m_name.getName());
}

void BattleCard::applyEncounter(Player& player) const
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

int BattleCard::getForce() const
{
    return m_force;
}

int BattleCard::getLoot() const
{
    return m_loot;
}