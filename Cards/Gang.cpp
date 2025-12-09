//
// Created by Istaitih
//

#include "Gang.h"
#include "BattleCard.h"
#include "../utilities.h"

const std::string GANG_NAME = "Gang";


Gang::Gang() : Card(GANG_NAME), m_gangCards()
{
}

Gang::Gang(const Gang &other) : Card(other), m_gangCards()
{
    for(const std::unique_ptr<BattleCard>& card : other.m_gangCards)
    {
        BattleCard* copy = dynamic_cast<BattleCard*>(card->clone());
        std::unique_ptr<BattleCard> tmp(copy);
        m_gangCards.push_back(std::move(tmp));
    }
}

Gang& Gang::operator=(const Gang &other)
{
    if(this == &other)
    {
        return *this;
    }
    while(!m_gangCards.empty())
    {
        m_gangCards.pop_front();
    }
    for(const std::unique_ptr<BattleCard>& card : other.m_gangCards)
    {
        BattleCard* copy = dynamic_cast<BattleCard*>(card->clone());
        std::unique_ptr<BattleCard> tmp(copy);
        m_gangCards.push_back(std::move(tmp));
    }
    return *this;
}

Card* Gang::clone() const
{
    Gang* result = new Gang();
    for(const std::unique_ptr<BattleCard>& card : m_gangCards)
    {
        BattleCard* copy = dynamic_cast<BattleCard*>(card->clone());
        std::unique_ptr<BattleCard> tmp(copy);
        result->m_gangCards.push_back(std::move(tmp));
    }
    return result;
}

void Gang::applyEncounter(Player &player) const
{
    bool hasLost = false;
    for(const std::unique_ptr<BattleCard>& card : m_gangCards)
    {
        if(!hasLost)
        {
            if(player.getAttackStrength() >= card->getForce())
            {
                player.addCoins(card->getLoot());
            }
            else
            {
                hasLost = true;
            }
        }
        if(hasLost)
        {
            card->applyLoseEffect(player);
        }
    }
    if(!hasLost)
    {
        player.levelUp();
        printWinBattle(player.getName(), GANG_NAME);
    }
}

bool Gang::addCard(std::unique_ptr<Card> card)
{
    BattleCard* battleCard = dynamic_cast<BattleCard*>(card.get());
    if(battleCard == nullptr)
    {
        return false;
    }
    card.release();
    std::unique_ptr<BattleCard> cardPtr(battleCard);
    m_gangCards.push_back(std::move(cardPtr));
    return true;
}

void Gang::printDetails(std::ostream &os) const
{
    for(const std::unique_ptr<BattleCard>& card : m_gangCards)
    {
        os << *card;
    }
}
