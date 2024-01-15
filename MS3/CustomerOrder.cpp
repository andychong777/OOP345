// Name: Andy Chong
// Seneca Student ID: 150558229
// Seneca email: achong11@gmail.com
// Date of completion: 11/17/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include "CustomerOrder.h"
#include "Utilities.h"

using namespace std;

namespace sdds
{
    size_t CustomerOrder::m_widthField = 0u;

    CustomerOrder::CustomerOrder(const CustomerOrder &source)
    {
        throw false;
    }

    CustomerOrder::CustomerOrder(CustomerOrder &&source) noexcept
    {
        *this = std::move(source);
    }

    CustomerOrder::~CustomerOrder()
    {
        if (m_lstItem)
        {
            for (auto i = 0u; i < m_cntItem; ++i)
                delete m_lstItem[i];

            delete[] m_lstItem;
            m_lstItem = nullptr;
        }
    }

    bool CustomerOrder::isOrderFilled() const
    {

        for (size_t i = 0; i < m_cntItem; i++)
        {

            if (!m_lstItem[i]->m_isFilled)
            {
                return false;
            }
        }
        return true;
    }

    bool CustomerOrder::isItemFilled(const std::string &itemName) const
    {
        for (size_t i = 0; i < m_cntItem; i++)
        {
            if (m_lstItem[i]->m_itemName == itemName && !m_lstItem[i]->m_isFilled)
            {
                return false;
            }
        }
        return true;
    }

    CustomerOrder::CustomerOrder(const std::string &source)
    {
        Utilities util;
        bool more = true;
        size_t point = 0u;
        size_t index = 0u;

        try
        {
            m_name = util.extractToken(source, point, more);
            m_product = util.extractToken(source, point, more);
            m_cntItem = std::count(source.begin(), source.end(),
                                   util.getDelimiter()) -
                        1;

            if (m_cntItem)
                m_lstItem = new Item *[m_cntItem];

            while (more && m_cntItem)
            {
                m_lstItem[index] = new Item(util.extractToken(source, point, more));
                ++index;
            }

            CustomerOrder::m_widthField = max(util.getFieldWidth(), CustomerOrder::m_widthField);
        }
        catch (std::string err)
        {
            cout << err;
        }
    }

    CustomerOrder &CustomerOrder::operator=(CustomerOrder &&source) noexcept
    {
        if (this != &source)
        {
            if (m_lstItem)
            {
                for (auto i = 0u; i < m_cntItem; ++i)
                    delete m_lstItem[i];

                delete[] m_lstItem;
            }

            m_name = source.m_name;
            m_product = source.m_product;
            m_cntItem = source.m_cntItem;
            m_lstItem = source.m_lstItem;

            source.m_name = "";
            source.m_product = "";
            source.m_cntItem = 0u;
            source.m_lstItem = nullptr;
        }

        return *this;
    }

    void CustomerOrder::fillItem(Station &station, std::ostream &os)
    {
        bool isSingle = true;

        for (size_t i = 0; i < m_cntItem; i++)
        {
            if (m_lstItem[i] && station.getItemName() == m_lstItem[i]->m_itemName && !m_lstItem[i]->m_isFilled && isSingle)
            {
                if (station.getQuantity() > 0)
                {

                    m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                    m_lstItem[i]->m_isFilled = true;
                    station.updateQuantity();
                    os << "    Filled " << m_name << ", " << m_product
                       << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;

                    isSingle = false;
                }
                else
                {
                    os << "    Unable to fill " << m_name << ", " << m_product //changed
                       << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
                }
            }
        }
    }

    void CustomerOrder::display(std::ostream &os) const
    {
        os << m_name << " - " << m_product << endl;

        for (auto i = 0u; i < m_cntItem; ++i)
        {
            os << "[" << right << setw(6) << setfill('0') << m_lstItem[i]->m_serialNumber << "] ";
            os << left << setw(CustomerOrder::m_widthField) << setfill(' ') << m_lstItem[i]->m_itemName;
            os << " - " << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << endl;
        }
    }
}