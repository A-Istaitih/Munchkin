//
// Created by Waseem Ibraheem on 13/06/2022.
//

#ifndef MATAM_EX4_EXCEPTION_H
#define MATAM_EX4_EXCEPTION_H
#include <exception>
#include <string>

/**
 * An exception that gets thrown in case of an invalid name.
 */
class InvalidName : public std::exception {
public:
    const char * what() const noexcept override
    {
        return "Invalid Name";
    }
};


 /**
 * An exception that gets thrown in case of failing to find the input file.
 */
class DeckFileNotFound : public std::exception {
public:
    const char * what() const noexcept override
    {
        return "Deck File Error: File not found";
    }
};


/**
* An exception that gets thrown in case of wrong format in one of the lines in the input file.
*/
class DeckFileFormatError : public std::exception {
public:
    const char * what() const noexcept override
    {
        return m_whatMessage.c_str();
    }
    DeckFileFormatError(int line) : m_line(line),
                                    m_whatMessage("Deck File Error: File format error in line ")
    {
        m_whatMessage.append(std::to_string(line));
    }
private:
    int m_line;
    std::string m_whatMessage;
};


/**
* An exception that gets thrown in case of having less cards than required.
*/
class DeckFileInvalidSize : public std::exception {
public:
    const char * what() const noexcept override
    {
        return "Deck File Error: Deck size is invalid";
    }
};


#endif //MATAM_EX4_EXCEPTION_H
