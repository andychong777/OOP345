#include <iostream>
#include <iomanip>
#include <algorithm>
#include "Station.h"
#include "Utilities.h"

using namespace std;

namespace sdds
{
    size_t Station::m_widthField = 0u;
    size_t Station::id_generator = 0u;

    Station::Station(const std::string &src)
    {
        Utilities util;
        size_t pos = 0;
        bool more = true;

        m_itemName = util.extractToken(src, pos, more);
        m_serialNumber = stoi(util.extractToken(src, pos, more));
        m_inStock = stoi(util.extractToken(src, pos, more));

        m_id = ++Station::id_generator;

        
        if (m_widthField < util.getFieldWidth())
        {

            m_widthField = util.getFieldWidth();
        }

        // Extract description
        m_desc = util.extractToken(src, pos, more);
    }

    const std::string &Station::getItemName() const
    {
        return m_itemName;
    }

    size_t Station::getNextSerialNumber()
    {
        return m_serialNumber++;
    }

    size_t Station::getQuantity() const
    {
        return m_inStock;
    }

    void Station::updateQuantity()
    {
        if (m_inStock > 0)
        {
            m_inStock--;
        }
    }

    void Station::display(std::ostream &os, bool full) const
    {
        os << std::right << std::setw(3) << std::setfill('0') << m_id << " | ";
        os << std::left << std::setw(Station::m_widthField) << std::setfill(' ') << m_itemName << " | ";
        os << std::right << std::setw(6) << std::setfill('0') << m_serialNumber << " | ";

        if (full)
        {
            os << std::right << std::setw(4) << std::setfill(' ') << m_inStock << " | ";
            os << m_desc;
        }

        os << std::endl;
    }

} // namespace sdds