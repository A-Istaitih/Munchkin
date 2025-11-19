//
// Created by Waseem Ibraheem on 12/06/2022.
//

#ifndef MATAM_EX4_PLAYER_H
#define MATAM_EX4_PLAYER_H



#include <string>
#include "../Name.h"


const int DEFAULT_MAX_HP = 100;
const int DEFAULT_FORCE = 5;
const int MAX_LEVEL = 10;
const int STARTING_LEVEL = 1;
const int STARTING_COINS = 10;


class Player {
public:


    /**
     * A constructor that receives a name, maxHp, force.
     * @param name - The player's name.
     * @param maxHP - The player's maxHp.
     * @param force - The player's force.
     */
    Player(Name name, int maxHP = DEFAULT_MAX_HP, int force = DEFAULT_FORCE);

    /**
     * Here we are explicitly telling the compiler to use the default methods.
     */
    Player(const Player&) = default;
    virtual ~Player() = default;
    Player& operator=(const Player&) = default;

    /**
     * "A virtual copy construnctor".
     * @return a pointer to the new object.
     */
    virtual Player* clone() const = 0;

    /**
     * levelUp: Increases the players level by 1.
     */
    void levelUp();

    /**
     * getLevel: Returns the player's level.
     * @return player's level.
     */
    int getLevel() const;

    /**
     * buff: Increases the player's force by "buffAmount".
     * @param buffAmount - The buff's amount.
     */
    virtual void buff(int buffAmount);

    /**
     * nerf: Decreases the player's force by "nerfAmount".
     * @param nerfAmount - The nerf's amount.
     */
    void nerf(int nerfAmount);

    /**
     * heal: Increases the player's heal by "healAmount".
     * @param healAmount - The heal increase value.
     */
    virtual void heal(int healAmount);

    /**
     * damage: Decrease the player's HP by "damageAmount"
     * @param damageAmount - The damage amount / Heal decrease.
     */
    void damage(int damageAmount);

    /**
     * isKnockedOut: Checks if the player is knocked out or not.( Checks if a player's HP is over )
     * @return true if the player's HP is lower\ equal to zero,else returns false.
     */
    bool isKnockedOut() const;

    /**
     * addCoins: Increases the player's coins by "coinsAmount"
     * @param coinsAmount - The coins' amount to be increased.
     */
    virtual void addCoins(int coinsAmount);

    /**
     * pay: Pays (Decreases the player's coins) by given "amount".
     * @param amount -
     * @return
     */
    bool pay(int amount);

    /**
     * kill: Kills the player (decreases his current hp to 0)
     */
    void kill();

    /**
     * hasWon: Checks if the player hasWon (reached Max level).
     * @return true if the level of the player is max level, otherwise false.
     */
    bool hasWon();

    /**
     * getAttackStrength: gets the strength of the player.
     * @return the strength of the player.
     */
    virtual int getAttackStrength() const;

    /**
     * getName: a getter for the name.
     * @return the player name.
     */
    std::string getName() const;

    /**
     * setName: changes the player name, if the name is invalid throws an exception.
     * @param name - the new name.
     */
    void setName(Name name);

    /**
     * getCoins: gets the amount of coins the player has.
     * @return the amount of coins the player has.
     */
    int getCoins() const;

    /**
     * getCurrentHealthPoints: gets the amount of health the player has.
     * @return the amount of health the player has.
     */
    int getCurrentHealthPoints() const;

protected:
    Name m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;

    /**
     * printDetails: prints the details of the player to os;
     * @param os - the os to print to.
     */
    virtual void printDetails(std::ostream& os) const = 0;

private:
    friend std::ostream& operator<<(std::ostream& os, const Player& player);

};




#endif //MATAM_EX4_PLAYER_H
