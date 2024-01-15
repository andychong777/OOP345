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
#include "CheeseParty.h"

using namespace sdds;

CheeseParty::CheeseParty()
{
    m_party = "No Name";
    m_maxCheeses = 0;
    m_numCheeses = 0;
    m_cheeses = nullptr;
}

CheeseParty::CheeseParty(const std::string &name)
{
    m_party = name;
    m_maxCheeses = 2;
    m_numCheeses = 0;
    m_cheeses = new const Cheese *[m_maxCheeses];
}
CheeseParty::~CheeseParty()
{ // destructor
    delete[] m_cheeses;
}

CheeseParty::CheeseParty(const CheeseParty &rhs)
{ // copy constructor
    m_party = rhs.m_party;
    m_maxCheeses = rhs.m_maxCheeses;
    m_numCheeses = rhs.m_numCheeses;
    m_cheeses = new const Cheese *[m_maxCheeses];
    for (int i = 0; i < m_numCheeses; i++)
    {
        m_cheeses[i] = rhs.m_cheeses[i];
    }
}

CheeseParty::CheeseParty(CheeseParty &&rhs)
{ // move constructor
    m_party = rhs.m_party;
    m_maxCheeses = rhs.m_maxCheeses;
    m_numCheeses = rhs.m_numCheeses;
    m_cheeses = rhs.m_cheeses;
    rhs.m_party = "no name";
    rhs.m_numCheeses = 0;
    rhs.m_cheeses = nullptr;
}

CheeseParty &CheeseParty::operator=(const CheeseParty &rhs)
{ // copy assignment
    m_party = rhs.m_party;
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

CheeseParty &CheeseParty::operator=(CheeseParty &&rhs)
{ // move assignment
    m_party = rhs.m_party;
    m_maxCheeses = rhs.m_maxCheeses;
    m_numCheeses = rhs.m_numCheeses;
    m_cheeses = rhs.m_cheeses;
    rhs.m_party = "no name";
    rhs.m_numCheeses = 0;
    rhs.m_cheeses = nullptr;
    return *this;
}

CheeseParty &CheeseParty::addCheese(const Cheese &cheese)
{
    for (int i = 0; i < m_numCheeses; i++)
    {
        if (cheese.getName() == m_cheeses[i]->getName())
        {
            return *this;
        }
    }
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
    m_cheeses[m_numCheeses++] = &cheese;
    return *this;
}

CheeseParty &CheeseParty::removeCheese()
{
    for (int i = 0; i < m_numCheeses; i++)
    {
        if (m_cheeses[i]->getWeight() == 0)
        {
            for (int j = i; j < m_numCheeses - 1; j++)
            {
                m_cheeses[j] = m_cheeses[j + 1];
            }
            m_numCheeses--;
        }
    }
    return *this;
}

std::string CheeseParty::getParty() const
{
    return m_party;
}

int CheeseParty::getNumCheeses() const
{
    return m_numCheeses;
}

Cheese CheeseParty::getCheese(int index) const
{
    return *(m_cheeses[index]);
}

std::ostream &sdds::operator<<(std::ostream &out, const CheeseParty &party)
{
    out << "--------------------------" << std::endl;
    out << party.getParty() << std::endl;
    out << "--------------------------" << std::endl;
    if (party.getNumCheeses() == 0)
    {
        out << "This party is getting started!" << std::endl;
        out << "--------------------------" << std::endl;
    }
    else
    {
        for (int i = 0; i < party.getNumCheeses(); i++)
        {
            out << party.getCheese(i);
        }
    }

    return out;
}