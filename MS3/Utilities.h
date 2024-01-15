// Name: Andy Chong
// Seneca Student ID: 150558229
// Seneca email: achong11@gmail.com
// Date of completion: 11/17/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include <iostream>

namespace sdds
{
    class Utilities
    {
    private:
        size_t m_widthField{1u}; // specifies the length of the token, default is 1

        static char m_delimiter; // separates the tokens in any given std::string object

    public:
        void setFieldWidth(size_t newWidth); // sets the field width of the current object

        size_t getFieldWidth() const; // returns the field width of the current object

        std::string extractToken(const std::string &str, size_t &next_pos, bool &more); // extracts a token from string

        // class functions
        static void setDelimiter(char newDelimiter); // returns the delimiter for this class.

        static char getDelimiter(); // returns the delimiter for this class
    };

}
#endif // !SDDS_UTILITIES_H