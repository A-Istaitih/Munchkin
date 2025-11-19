#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <string>
#include <deque>
#include <map>
#include <memory>
#include <fstream>

#include "Cards/Card.h"
#include "Cards/Gang.h"

const int MINIMUM_CARDS = 5;
const int MINIMUM_TEAM_SIZE = 2;
const int MAXIMUM_TEAM_SIZE = 6;
const std::string ENDGANG_NAME = "EndGang";
const std::string GANG_NAME = "Gang";



class Mtmchkin{

public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string& fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

private:
    std::deque<std::unique_ptr<Player>> m_currentPlayers;
    std::deque<std::unique_ptr<Player>> m_winners;
    std::deque<std::unique_ptr<Player>> m_losers;
    std::deque<std::string> m_cards;

    int m_finishedRounds;

    std::map<std::string, std::unique_ptr<Card>> m_cardTypes;
    std::map<std::string, std::unique_ptr<Player>> m_playerJobs;
    std::map<std::string, std::unique_ptr<Gang>> m_gangs;

    int m_numberOfGangs;

    Mtmchkin(const Mtmchkin&) = delete;
    Mtmchkin& operator=(Mtmchkin&) = delete;
};



#endif /* MTMCHKIN_H_ */
