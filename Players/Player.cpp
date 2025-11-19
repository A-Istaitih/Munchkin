//
// Created by Waseem Ibraheem on 12/06/2022.
//

#include "Player.h"



Player::Player(Name name, int maxHP, int force) : m_name(name), m_level(STARTING_LEVEL), m_force(force),
                                                         m_maxHP(maxHP), m_HP(maxHP), m_coins(STARTING_COINS)
{
    if(m_force < 0)
    {
        m_force = DEFAULT_FORCE;
    }
    if(m_maxHP <= 0)
    {
        m_maxHP = DEFAULT_MAX_HP;
        m_HP = DEFAULT_MAX_HP;
    }
}

void Player::levelUp()
{
    if(m_level < MAX_LEVEL)
    {
        m_level++;
    }
}

int Player::getLevel() const
{
    return m_level;
}

void Player::buff(int buffAmount)
{
    if(buffAmount <= 0)
    {
        return;
    }
    m_force+= buffAmount;
}

void Player::nerf(int nerfAmount)
{
    if(nerfAmount <= 0)
    {
        return;
    }
    m_force-= nerfAmount;
    if(m_force < 0)
    {
        m_force = 0;
    }
}

void Player::heal(int healAmount)
{
    if(healAmount <= 0)
    {
        return;
    }
    m_HP += healAmount;
    if(m_HP > m_maxHP)
    {
        m_HP = m_maxHP;
    }
}

void Player::damage(int damageAmount)
{
    if(damageAmount <= 0)
    {
        return;
    }
    m_HP-=damageAmount;
    if(m_HP < 0)
    {
        m_HP = 0;
    }
}

bool Player::isKnockedOut() const
{
    return (m_HP <= 0);
}

void Player::addCoins(int coinsAmount)
{
    if(coinsAmount <= 0)
    {
        return;
    }
    m_coins+=coinsAmount;
}

bool Player::pay(int amount)
{
    if(amount > m_coins)
    {
        return false;
    }
    if(amount >= 0)
    {
        m_coins-=amount;
    }
    return true;
}

int Player::getAttackStrength() const
{
    return (m_level + m_force);
}

void Player::kill()
{
    m_HP = 0;
}

std::string Player::getName() const
{
    return m_name.getName();
}

int Player::getCoins() const
{
    return m_coins;
}

void Player::setName(Name name)
{
    m_name = name;
}

std::ostream& operator<<(std::ostream& os, const Player& player)
{
    player.printDetails(os);
    return os;
}

bool Player::hasWon()
{
    return m_level == MAX_LEVEL;
}

int Player::getCurrentHealthPoints() const
{
    return m_HP;
}