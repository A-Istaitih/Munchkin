//
// Created by Waseem Ibraheem on 12/06/2022.
//

#ifndef MATAM_EX4_FIGHTER_H
#define MATAM_EX4_FIGHTER_H

#include "Player.h"

const std::string FIGHTER_JOB = "Fighter";

class Fighter : public Player {

public:
    /**
     * Constructors + operator= + destructor for Fighter.
     */
    Fighter(Name name, int maxHP = DEFAULT_MAX_HP, int force = DEFAULT_FORCE);
    Fighter(const Fighter& other) = default;
    Fighter& operator=(const Fighter& Fighter) = default;
    ~Fighter() override = default;

    /**
     * "A virtual copy constructor" that returns a pointer for the new object.
     * @return - pointer of the new object.
     */
    Player* clone() const override;

    /**
     * A function that returns the strength of the fighter, calculated by the rules.
     * @return - attack strength of this.
     */
    int getAttackStrength() const override;

private:
    /**
     * Prints the details of this to os.
     * @param os - the output stream.
     */
    void printDetails(std::ostream& os) const override;
};


#endif //MATAM_EX4_FIGHTER_H
