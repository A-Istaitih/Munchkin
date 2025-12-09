//
// Created by Istaitih
//

#include "Name.h"
#include "Exception.h"


/**
 * Checks if name is a valid name.
 * @param name - The name to check.
 * @return true if name is valid, otherwise false.
 */
bool checkValidName(std::string name);

/**
 * Checks if letter is a letter from a-z (lower/upper case).
 * @param letter - the letter to check.
 * @return true if letter is indeed a letter, otherwise false.
 */
bool isLetter(char letter);


const char LOWER_CASE_A = 'a';
const char LOWER_CASE_Z = 'z';
const char UPPER_CASE_A = 'A';
const char UPPER_CASE_Z = 'Z';


Name::Name(const std::string& name) : m_name(name)
{
    if(!checkValidName(name))
    {
        throw InvalidName();
    }
    m_name.resize(m_name.size());
}

Name::Name(const char* name) : m_name(name)
{
    if(!checkValidName(name))
    {
        throw InvalidName();
    }
    m_name.resize(m_name.size());
}

std::string Name::getName() const
{
    return m_name;
}

void Name::setName(std::string name)
{
    if(!checkValidName(name))
    {
        throw InvalidName();
    }
    m_name = name;
    m_name.resize(m_name.size());
}

bool checkValidName(std::string name)
{
    if(name.length() > MAX_NAME_LENGTH)
    {
        return false;
    }

    for(int i = 0; i < (int)name.length(); i++)
    {
        if(!isLetter(name[i]))
        {
            return false;
        }
    }
    return true;
}

bool isLetter(char letter)
{
    if(letter >= LOWER_CASE_A && letter <= LOWER_CASE_Z)
    {
        return true;
    }
    if(letter >= UPPER_CASE_A && letter <= UPPER_CASE_Z)
    {
        return true;
    }
    return false;
}
