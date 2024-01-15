/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NDD

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <string>
#include <iomanip>
#include "CheeseShop.h"

using namespace sdds;

CheeseShop::CheeseShop()
{
    m_shop = "No Name";
    m_maxCheeses = 0;
    m_numCheeses = 0;
    m_cheeses = nullptr;
}

CheeseShop::CheeseShop(const std::string &name)
{
    m_shop = name;
    m_maxCheeses = 2;
    m_numCheeses = 0;
    m_cheeses = new const Cheese *[m_maxCheeses];
}
CheeseShop::~CheeseShop()
{ // destructor
    delete[] m_cheeses;
}

CheeseShop::CheeseShop(const CheeseShop &rhs)
{ // copy constructor
    m_shop = rhs.m_shop;
    m_maxCheeses = rhs.m_maxCheeses;
    m_numCheeses = rhs.m_numCheeses;
    m_cheeses = new const Cheese *[m_maxCheeses];
    for (int i = 0; i < m_numCheeses; i++)
    {
        m_cheeses[i] = rhs.m_cheeses[i];
    }
}

CheeseShop::CheeseShop(CheeseShop &&rhs)
{ // move constructor
    m_shop = rhs.m_shop;
    m_maxCheeses = rhs.m_maxCheeses;
    m_numCheeses = rhs.m_numCheeses;
    m_cheeses = rhs.m_cheeses;
    rhs.m_shop = "";
    rhs.m_numCheeses = 0;
    rhs.m_cheeses = nullptr;
}

CheeseShop &CheeseShop::operator=(const CheeseShop &rhs)
{ // copy assignment
    m_shop = rhs.m_shop;
    m_maxCheeses = rhs.m_maxCheeses;
    m_numCheeses = rhs.m_numCheeses;
    delete[] m_cheeses;
    m_cheeses = new const Cheese *[m_maxCheeses];
    for (int i = 0; i < m_numCheeses; i++)
    {
        m_cheeses[i] = rhs.m_cheeses[i];
    }
    return *this;
}

CheeseShop &CheeseShop::operator=(CheeseShop &&rhs)
{ // move assignment
    m_shop = rhs.m_shop;
    m_maxCheeses = rhs.m_maxCheeses;
    m_numCheeses = rhs.m_numCheeses;
    m_cheeses = rhs.m_cheeses;
    rhs.m_shop = "";
    rhs.m_numCheeses = 0;
    rhs.m_cheeses = nullptr;
    return *this;
}

CheeseShop &CheeseShop::addCheese(const Cheese &cheese)
{
    if (m_numCheeses == m_maxCheeses)
    {
        if (m_maxCheeses == 0)
        {
            m_maxCheeses = 1;
        }
        m_maxCheeses *= 2;
        const Cheese **newCheeses = new const Cheese *[m_maxCheeses];
        for (int i = 0; i < m_numCheeses; i++)
        {
            newCheeses[i] = m_cheeses[i];
        }
        delete[] m_cheeses;
        m_cheeses = newCheeses;
    }
    m_cheeses[m_numCheeses++] = new Cheese(cheese); // need o change to copy
    return *this;
}

std::string CheeseShop::getShop() const
{
    return m_shop;
}

int CheeseShop::getNumCheeses() const
{
    return m_numCheeses;
}

Cheese CheeseShop::getCheese(int index) const
{
    return *(m_cheeses[index]);
}

std::ostream &sdds::operator<<(std::ostream &out, const CheeseShop &shop)
{
    out << "--------------------------" << std::endl;
    out << shop.getShop() << std::endl;
    out << "--------------------------" << std::endl;
    if (shop.getNumCheeses() == 0)
    {
        out << "This shop is out of cheese!" << std::endl;
        out << "--------------------------" << std::endl;
    }
    else
    {
        for (int i = 0; i < shop.getNumCheeses(); i++)
        {
            out << shop.getCheese(i);
        }
    }
    return out;
}