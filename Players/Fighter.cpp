//
// Created by Istaitih
//

#include "Fighter.h"
#include "../utilities.h"

Fighter::Fighter(Name name, int maxHP, int force) : Player(name, maxHP, force)
{
}

Player* Fighter::clone() const
{
    Fighter *result = new Fighter(m_name, m_maxHP, m_force);
    result->m_level = m_level;
    result->m_HP = m_HP;
    result->m_coins = m_coins;
    return result;
}

int Fighter::getAttackStrength() const
{
    return 2 * m_force + m_level;
}

void Fighter::printDetails(std::ostream& os) const
{
    printPlayerDetails(os, m_name.getName(), FIGHTER_JOB, m_level, m_force, m_HP, m_coins);
}
