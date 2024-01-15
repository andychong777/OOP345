#include <iostream>
#include <string>
#include <algorithm>
#include "Utilities.h"

using namespace std;

namespace sdds
{
    char Utilities::m_delimiter = ',';

    void Utilities::setFieldWidth(size_t newWidth)
    {
        m_widthField = newWidth;
    }

    size_t Utilities::getFieldWidth() const
    {
        return m_widthField;
    }

    std::string Utilities::extractToken(const std::string &str, size_t &next_pos, bool &more)
    {
       
        size_t first_pos = next_pos;
        size_t end_pos = str.find(m_delimiter, next_pos);

        if (first_pos == end_pos)
        {
            more = false;
            throw "Error!: No token was found!";
        }

        if (end_pos == std::string::npos)
        {
            end_pos = str.length();
            more = false;
        }
        else
        {
            more = true;
        }

        std::string token = str.substr(next_pos, end_pos - next_pos);

        next_pos = end_pos + 1;

        size_t firstNonSpace = token.find_first_not_of(" \t");

        size_t lastNonSpace = token.find_last_not_of(" \t");

        if (firstNonSpace != std::string::npos && lastNonSpace != std::string::npos)
        {
            token = token.substr(firstNonSpace, lastNonSpace - firstNonSpace + 1);
        }
        else
        {
            token.clear(); 
        }

        if (m_widthField < token.length())
        {
            m_widthField = token.length();
        }

        return token;
    }

    void Utilities::setDelimiter(char newDelimiter)
    {
        m_delimiter = newDelimiter;
    }

    char Utilities::getDelimiter()
    {
        return m_delimiter;
    }
}