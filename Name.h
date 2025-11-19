//
// Created by Waseem Ibraheem on 13/06/2022.
//

#ifndef MATAM_EX4_NAME_H
#define MATAM_EX4_NAME_H

#include <string>

const int MAX_NAME_LENGTH = 15;

class Name {

public:

    /**
     * Constructors + operator= + destructor for Name.
     * If name isn't valid, they throw an exception of type InvalidName.
     */
    Name(const std::string& name);
    Name(const char* name);
    Name(const Name& other) = default;
    Name& operator=(const Name& other) = default;
    ~Name() = default;

    /**
     * Getter for name
     * @return name
     */
    std::string getName() const;

    /**
     * Setter for name, if name isn't valid throws InvalidName.
     * @param name - the name to set.
     */
    void setName(std::string name);

private:
    std::string m_name;
};



#endif //MATAM_EX4_NAME_H
