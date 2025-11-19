//
// Created by Waseem Ibraheem on 12/06/2022.
//

#include "Rogue.h"
#include "../utilities.h"

Rogue::Rogue(Name name, int maxHP, int force) : Player(name, maxHP, force)
{
}

Player* Rogue::clone() const
{
    Rogue *result = new Rogue(m_name, m_maxHP, m_force);
    result->m_level = m_level;
    result->m_HP = m_HP;
    result->m_coins = m_coins;
    return result;
}
void Rogue::addCoins(int coinsAmount)
{
    if(coinsAmount <= 0)
    {
        return;
    }
    m_coins+= (2 * coinsAmount);
}
void Rogue::printDetails(std::ostream& os) const
{
    printPlayerDetails(os, m_name.getName(), ROGUE_JOB, m_level, m_force, m_HP, m_coins);
}