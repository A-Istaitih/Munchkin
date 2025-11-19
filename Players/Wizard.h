//
// Created by Waseem Ibraheem on 12/06/2022.
//

#ifndef MATAM_EX4_WIZARD_H
#define MATAM_EX4_WIZARD_H

#include "Player.h"


const std::string WIZARD_JOB = "Wizard";

class Wizard : public Player {

public:
    /**
    * Constructors + operator= + destructor for Wizard.
    */
    Wizard(Name name, int maxHP = DEFAULT_MAX_HP, int force = DEFAULT_FORCE);
    Wizard(const Wizard& other) = default;
    Wizard& operator=(const Wizard& Wizard) = default;
    ~Wizard() override = default;

    /**
    * "A virtual copy constructor" that returns a pointer for the new object.
    * @return - pointer of the new object.
    */
    Player* clone() const override;

    /**
     * Heals the player (adds to his current hp), since he is a wizard, he gets double the amount.
     * @param healAmount - the heal amount.
     */
    void heal(int healAmount) override;

private:
    /**
    * Prints the details of this to os.
    * @param os - the output stream.
    */
    void printDetails(std::ostream& os) const override;
};

#endif //MATAM_EX4_WIZARD_H
