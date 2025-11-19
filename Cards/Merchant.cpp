//
// Created by Waseem Ibraheem on 12/06/2022.
//

#include "Merchant.h"
#include "../utilities.h"

/**
 * A function that gets the input from the user (from std::cin), converts it to int and then returns it.
 * @return user's input as an int.
 */
int getAnswerFromUser();


Merchant::Merchant() : Card(MERCHANT_NAME)
{
}


Card* Merchant::clone() const
{
    Merchant* result = new Merchant();
    return result;
}



void Merchant::applyEncounter(Player& player) const
{
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    int answer = getAnswerFromUser();
    if(answer == LEAVE_TAG)
    {
        printMerchantSummary(std::cout, player.getName(), LEAVE_TAG, 0);
    }
    if(answer == HEAL_TAG)
    {
        if(player.pay(PRICE_FOR_POTION))
        {
            player.heal(MERCHANT_HEAL_AMOUNT);
            printMerchantSummary(std::cout, player.getName(), HEAL_TAG, PRICE_FOR_POTION);
        }
        else
        {
            printMerchantInsufficientCoins(std::cout);
            printMerchantSummary(std::cout, player.getName(), HEAL_TAG, 0);
        }
    }
    if(answer == BOOST_TAG)
    {
        if(player.pay(PRICE_FOR_BOOST))
        {
            player.buff(MERCHANT_BOOST_AMOUNT);
            printMerchantSummary(std::cout, player.getName(), BOOST_TAG, PRICE_FOR_BOOST);
        }
        else
        {
            printMerchantInsufficientCoins(std::cout);
            printMerchantSummary(std::cout, player.getName(), BOOST_TAG, 0);
        }
    }
}


int getAnswerFromUser()
{
    std::string input;
    std::getline(std::cin, input);
    int answer = 0;
    while(true)
    {
        try
        {
            answer = std::stoi(input);
        }
        catch(...)
        {
            printInvalidInput();
            std::getline(std::cin, input);
            continue;
        }
        if(answer != LEAVE_TAG && answer != HEAL_TAG && answer != BOOST_TAG)
        {
            printInvalidInput();
            std::getline(std::cin, input);
            continue;
        }
        break;
    }
    return answer;
}