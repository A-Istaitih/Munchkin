//
// Created by Istaitih
//

#include "Mtmchkin.h"
#include "utilities.h"
#include "Exception.h"
#include "Players/Fighter.h"
#include "Players/Rogue.h"
#include "Players/Wizard.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Fairy.h"
#include "Cards/Goblin.h"
#include "Cards/Merchant.h"
#include "Cards/Pitfall.h"
#include "Cards/Treasure.h"
#include "Cards/Vampire.h"


/**
 * Adds a pointer for each card type to the cardTypes.
 * @param cardTypes - the map to add to.
 */
void fillCardsTypes(std::map<std::string, std::unique_ptr<Card>>& cardTypes);

/**
 * Adds a pointer for each job (class) to the playerJobs.
 * @param playerJobs - the map to add to.
 */
void fillPlayerJobs(std::map<std::string, std::unique_ptr<Player>>& playerJobs);

/**
 * Gets the cards from the source, and sets everything up so we can use them.
 * @param cards - the cards' deque.
 * @param cardTypes - the map that has the types of the cards.
 * @param gangs - a map for the gangs (we add every new gang there).
 * @param source - the file to read from.
 * @param numberOfGangs - the number of gangs that we make.
 */
void fillCards(std::deque<std::string>& cards, std::map<std::string, std::unique_ptr<Card>>& cardTypes,
               std::map<std::string, std::unique_ptr<Gang>>& gangs,
               std::ifstream& source, int& numberOfGangs);

/**
 * Gets the number of players from the user (std::cin).
 * @return the number of players.
 */
int getTeamSize();

/**
 * Gets the entered details of the player's name and job, and checks if they are valid names.
 * @param playerName - the name to check.
 * @param job - the job to check.
 * @return true if they are valid names, otherwise false.
 */
bool checkValidInput(const std::string& playerName, const std::string& job);

/**
 * Gets the data for the players.
 * @param currentPlayers - the deque of the players.
 * @param playerJobs - the available jobs.
 * @return the number of the players.
 */
int fillPlayers(std::deque<std::unique_ptr<Player>>& currentPlayers, const std::map<std::string,
                std::unique_ptr<Player>>& playerJobs);

/**
 * Adds a new card of the received card to the deque, if the card is a Gang card, it reads the entire gang's cards,
 * and adds them to a new gang, and adds it to the map of gangs.
 * @param cards - the deque of cards.
 * @param cardTypes - the map of the cards' types.
 * @param gangs - the map of the gangs.
 * @param source - the file to read from.
 * @param type - the inserted type.
 * @param numberOfGangs - the number of gangs.
 * @param numberOfLines - the line number (in the source).
 */
void addCard(std::deque<std::string>& cards, std::map<std::string, std::unique_ptr<Card>>& cardTypes,
             std::map<std::string, std::unique_ptr<Gang>>& gangs,
             std::ifstream& source, std::string type, int& numberOfGangs, int& numberOfLines, int& numberOfCards);

/**
 * Checks the validity of the data in line.
 * @param cardTypes - the map of the cards' types.
 * @param line - the input to check.
 * @return true if the input is valid, otherwise false.
 */
bool checkValidName(std::map<std::string, std::unique_ptr<Card>>& cardTypes, const char* line);


Mtmchkin::Mtmchkin(const std::string& fileName) : m_currentPlayers(), m_winners(), m_losers(), m_cards(),
                                                 m_finishedRounds(0), m_cardTypes(), m_gangs(), m_numberOfGangs(0)
{
    printStartGameMessage();
    fillCardsTypes(m_cardTypes);
    std::ifstream source(fileName);
    if(!source)
    {
        throw DeckFileNotFound();
    }
    try
    {
        fillCards(m_cards, m_cardTypes, m_gangs, source, m_numberOfGangs);
    }
    catch (const DeckFileFormatError& e)
    {
        throw e;
    }
    catch (const DeckFileInvalidSize& e)
    {
        throw e;
    }

    fillPlayerJobs(m_playerJobs);
    fillPlayers(m_currentPlayers, m_playerJobs);
}

void fillPlayerJobs(std::map<std::string, std::unique_ptr<Player>>& playerJobs)
{
    std::unique_ptr<Rogue> rogue(new Rogue("Dummy"));
    std::unique_ptr<Fighter> fighter(new Fighter("Dummy"));
    std::unique_ptr<Wizard> wizard(new Wizard("Dummy"));

    playerJobs["Rogue"] = std::move(rogue);
    playerJobs["Fighter"] = std::move(fighter);
    playerJobs["Wizard"] = std::move(wizard);
}



void fillCardsTypes(std::map<std::string, std::unique_ptr<Card>>& cardTypes)
{
    std::unique_ptr<Barfight> barfight(new Barfight());
    std::unique_ptr<Dragon> dragon(new Dragon());
    std::unique_ptr<Fairy> fairy(new Fairy());
    std::unique_ptr<Goblin> goblin(new Goblin());
    std::unique_ptr<Merchant> merchant(new Merchant());
    std::unique_ptr<Pitfall> pitfall(new Pitfall());
    std::unique_ptr<Treasure> treasure(new Treasure());
    std::unique_ptr<Vampire> vampire(new Vampire());
    std::unique_ptr<Gang> gang(new Gang());

    cardTypes["Barfight"] = std::move(barfight);
    cardTypes["Dragon"] = std::move(dragon);
    cardTypes["Fairy"] = std::move(fairy);
    cardTypes["Goblin"] = std::move(goblin);
    cardTypes["Merchant"] = std::move(merchant);
    cardTypes["Pitfall"] = std::move(pitfall);
    cardTypes["Treasure"] = std::move(treasure);
    cardTypes["Vampire"] = std::move(vampire);
    cardTypes["Gang"] = std::move(gang);
}



void fillCards(std::deque<std::string>& cards, std::map<std::string, std::unique_ptr<Card>>& cardTypes,
               std::map<std::string, std::unique_ptr<Gang>>& gangs,
               std::ifstream& source, int& numberOfGangs)
{
    std::string line("");
    int currentLine = 0;
    int numberOfCards = 0;
    Name name("");

    while(std::getline(source, line))
    {
        currentLine++;
        numberOfCards++;
        if(checkValidName(cardTypes, line.c_str()))
        {
            name.setName(line);
        }
        else
        {
            throw(DeckFileFormatError(currentLine));
        }
        addCard(cards, cardTypes, gangs, source, name.getName(), numberOfGangs, currentLine, numberOfCards);
    }
    if(numberOfCards < MINIMUM_CARDS)
    {
        throw DeckFileInvalidSize();
    }
}

int fillPlayers(std::deque<std::unique_ptr<Player>>& currentPlayers,
                const std::map<std::string, std::unique_ptr<Player>>& playerJobs)
{
    printEnterTeamSizeMessage();
    int answer = getTeamSize();
    std::string input;
    bool hasPrinted = false;
    for(int i=0; i < answer; i++)
    {
        if(!hasPrinted)
        {
            printInsertPlayerMessage();
            hasPrinted = true;
        }

        std::getline(std::cin, input);
        int spaceIndex = (int)input.find(' ');
        if(spaceIndex == (int)std::string::npos)
        {
            printInvalidName();
            i--;
            continue;
        }
        std::string playerName = input.substr(0, spaceIndex);
        std::string playerJob = input.substr(spaceIndex + 1);
        if(!checkValidInput(playerName, playerJob))
        {
            i--;
            continue;
        }
        Name editedPlayerName(playerName);
        Name editedPlayerJob(playerJob);
        if(playerJobs.find(editedPlayerJob.getName()) == playerJobs.end())
        {
            printInvalidClass();
            i--;
            continue;
        }
        Player *player = playerJobs.at(editedPlayerJob.getName())->clone();
        player->setName(editedPlayerName.getName());
        std::unique_ptr<Player> playerPtr(player);
        currentPlayers.push_back(std::move(playerPtr));
        hasPrinted = false;
    }
    return answer;
}


int getTeamSize()
{
    std::string input;
    std::getline(std::cin, input);
    int answer;
    while(true)
    {
        try
        {
            answer = std::stoi(input);
        }
        catch(...)
        {
            printInvalidTeamSize();
            printEnterTeamSizeMessage();
            std::getline(std::cin, input);
            continue;
        }
        if(answer < MINIMUM_TEAM_SIZE || answer > MAXIMUM_TEAM_SIZE)
        {
            printInvalidTeamSize();
            printEnterTeamSizeMessage();
            std::getline(std::cin, input);
            continue;
        }
        break;
    }
    return answer;
}

bool checkValidInput(const std::string& playerName, const std::string& job)
{
    try
    {
        Name tmp(playerName);
    }
    catch(const InvalidName& e)
    {
        printInvalidName();
        return false;
    }
    try
    {
        Name tmp(job);
    }
    catch (const InvalidName& e)
    {
        printInvalidClass();
        return false;
    }
    return true;
}

int Mtmchkin::getNumberOfRounds() const
{
    return m_finishedRounds;
}

bool Mtmchkin::isGameOver() const
{
    return m_currentPlayers.empty();
}

void Mtmchkin::printLeaderBoard() const
{
    int i = 0;
    printLeaderBoardStartMessage();
    for(const std::unique_ptr<Player>& player : m_winners)
    {
        i++;
        printPlayerLeaderBoard(i, *player);
    }
    for(const std::unique_ptr<Player>& player : m_currentPlayers)
    {
        i++;
        printPlayerLeaderBoard(i, *player);
    }
    for(const std::unique_ptr<Player>& player : m_losers)
    {
        i++;
        printPlayerLeaderBoard(i, *player);
    }
}

void Mtmchkin::playRound()
{
    printRoundStartMessage(m_finishedRounds + 1);
    int queueSize = (int)m_currentPlayers.size();
    for(int i = 0; i < queueSize; i++)
    {
        std::unique_ptr<Player> tmp = std::move(m_currentPlayers.front());
        m_currentPlayers.pop_front();
        m_currentPlayers.push_back(std::move(tmp));
        std::unique_ptr<Player>& player = m_currentPlayers.back();

        std::string currentCard = m_cards.front();
        m_cards.pop_front();
        m_cards.push_back(currentCard);

        printTurnStartMessage(player->getName());

        if(m_cardTypes.find(currentCard) == m_cardTypes.end())
        {
            (*m_gangs[currentCard]).applyEncounter(*player);
        }
        else
        {
            (*m_cardTypes[currentCard]).applyEncounter(*player);
        }


        if(player->hasWon())
        {
            m_winners.push_back(std::move(player));
            m_currentPlayers.pop_back();
        }
        else if(player->isKnockedOut())
        {
            m_losers.push_front(std::move(player));
            m_currentPlayers.pop_back();
        }
    }
    if(isGameOver())
    {
        printGameEndMessage();
    }
    m_finishedRounds++;
}


void addCard(std::deque<std::string>& cards, std::map<std::string, std::unique_ptr<Card>>& cardTypes,
             std::map<std::string, std::unique_ptr<Gang>>& gangs,
             std::ifstream& source, std::string type, int& numberOfGangs, int& numberOfLines, int& numberOfCards)
{
    if(type != GANG_NAME)
    {
        cards.push_back(type);
        return;
    }
    std::string name = type;
    name.append(std::to_string(numberOfGangs++));

    std::unique_ptr<Gang> gang(new Gang());

    bool foundEndGang = false;
    std::string line("");
    while(std::getline(source, line))
    {
        numberOfLines++;
        Name cardName("");
        if(line == ENDGANG_NAME)
        {
            foundEndGang = true;
            break;
        }
        if(!checkValidName(cardTypes, line.c_str()))
        {
            throw(DeckFileFormatError(numberOfLines));
        }
        cardName.setName(line);
        std::unique_ptr<Card> card(cardTypes[cardName.getName()]->clone());
        if(!gang->addCard(std::move(card)))
        {
            throw(DeckFileFormatError(numberOfLines));
        }
    }
    if(!foundEndGang)
    {
        throw DeckFileFormatError(numberOfLines + 1);
    }
    cards.push_back(name);
    gangs[name] = std::move(gang);
}

bool checkValidName(std::map<std::string, std::unique_ptr<Card>>& cardTypes, const char* line)
{
    Name name("");
    try
    {
        name.setName(line);
    }
    catch(const InvalidName& e)
    {
        return false;
    }
    if(cardTypes.find(name.getName()) == cardTypes.end())
    {
        return false;
    }
    return true;
}
