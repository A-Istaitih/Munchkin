//
// Created by Waseem Ibraheem on 21/06/2022.
//

#include <string>
#include "../Mtmchkin.h"
#include <exception>
#include <iostream>

int main()
{
    std::string deckFileName("deck.txt");
    try
    {
        Mtmchkin game(deckFileName);
        while(!game.isGameOver())
        {
            game.playRound();
        }
        game.printLeaderBoard();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what();
    }
}