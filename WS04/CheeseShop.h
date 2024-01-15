/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NDD

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_CHEESESHOP_H
#define SDDS_CHEESESHOP_H

#include <iostream>
#include <string>
#include "Cheese.h"

namespace sdds
{
    class CheeseShop
    {
    private:
        std::string m_shop;
        int m_maxCheeses;
        int m_numCheeses;
        const Cheese **m_cheeses;

    public:
        CheeseShop();
        CheeseShop(const std::string &name);
        ~CheeseShop(); // destructor

        CheeseShop(const CheeseShop &rhs);            // copy constructor
        CheeseShop(CheeseShop &&rhs);                 // move constructor
        CheeseShop &operator=(const CheeseShop &rhs); // copy assignment
        CheeseShop &operator=(CheeseShop &&rhs);      // move assignment

        CheeseShop &addCheese(const Cheese &);

        std::string getShop() const;
        int getNumCheeses() const;
        Cheese getCheese(int index) const;
    };

    std::ostream &operator<<(std::ostream &out, const CheeseShop &shop);
}

#endif