//
// Created by Waseem Ibraheem on 12/06/2022.
//

#include "Wizard.h"
#include "../utilities.h"

Wizard::Wizard(Name name, int maxHP, int force) : Player(name, maxHP, force)
{
}

Player* Wizard::clone() const
{
    Wizard *result = new Wizard(m_name, m_maxHP, m_force);
    result->m_level = m_level;
    result->m_HP = m_HP;
    result->m_coins = m_coins;
    return result;
}
void Wizard::heal(int healAmount)
{
    if(healAmount <= 0)
    {
        return;
    }
    m_HP += (2 * healAmount);
    if(m_HP > m_maxHP)
    {
        m_HP = m_maxHP;
    }
}

void Wizard::printDetails(std::ostream& os) const
{
    printPlayerDetails(os, m_name.getName(), WIZARD_JOB, m_level, m_force, m_HP, m_coins);
}