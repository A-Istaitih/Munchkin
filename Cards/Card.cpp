//
// Created by Waseem Ibraheem on 12/06/2022.
//

#include "Card.h"
#include "../Exception.h"
#include "../utilities.h"

Card::Card(Name name) : m_name(name)
{
}

std::ostream& operator<<(std::ostream& os, const Card& card)
{
    card.printDetails(os);
    return os;
}

void Card::printDetails(std::ostream& os) const
{
    printCardDetails(os, m_name.getName());
    printEndOfCardDetails(os);
}