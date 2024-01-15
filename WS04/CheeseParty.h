/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NDD

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_CHEESEPARTY_H
#define SDDS_CHEESEPARTY_H

#include <iostream>
#include <string>
#include "Cheese.h"

namespace sdds
{
    class CheeseParty
    {
    private:
        std::string m_party;
        int m_maxCheeses;
        int m_numCheeses;
        const Cheese **m_cheeses;

    public:
        CheeseParty();
        CheeseParty(const std::string &name);
        ~CheeseParty(); // destructor

        CheeseParty(const CheeseParty &rhs);            // copy constructor
        CheeseParty(CheeseParty &&rhs);                 // move constructor
        CheeseParty &operator=(const CheeseParty &rhs); // copy assignment
        CheeseParty &operator=(CheeseParty &&rhs);      // move assignment

        CheeseParty &addCheese(const Cheese &);
        CheeseParty &removeCheese();

        std::string getParty() const;
        int getNumCheeses() const;
        Cheese getCheese(int index) const;
    };

    std::ostream &operator<<(std::ostream &out, const CheeseParty &party);
}
#endif