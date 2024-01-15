/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NDD

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "Book.h"

using namespace std;
namespace sdds
{
    Book::Book() {}

    Book::Book(const std::string &title, unsigned nChapters, unsigned nPages)
    {
        m_title = title;
        m_numChapters = nChapters;
        m_numPages = nPages;
    }

    Book::operator bool() const
    {
        return m_title.length();
    }

    bool sdds::Book::operator<(const Book &otherBook) const
    {
        return ((double)m_numPages / m_numChapters) < ((double)otherBook.m_numPages / otherBook.m_numChapters);
    }

    bool sdds::Book::operator>(const Book &otherBook) const
    {
        return ((double)m_numPages / m_numChapters) > ((double)otherBook.m_numPages / otherBook.m_numChapters);
    }

    std::ostream &operator<<(std::ostream &os, const Book &bk)
    {
        return bk.print(os);
    }

    std::ostream &Book::print(std::ostream &os) const
    {
        if (*this)
        {
            stringstream ss;
            ss << m_title << "," << m_numChapters << "," << m_numPages << " | (";
            os << setw(60) << setiosflags(ios::right) << ss.str();
            os << setprecision(6) << resetiosflags(ios::right)
               << setiosflags(ios::left) << setiosflags(ios::fixed)
               << ((double)m_numPages / m_numChapters) << ")    ";
            os << resetiosflags(ios::fixed);
        }
        else
        {
            os << "| Invalid book data";
        }

        return os;
    }
}
