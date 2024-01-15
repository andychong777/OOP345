// Name: Andy Chong
// Seneca Student ID: 150558229
// Seneca email: achong11@gmail.com
// Date of completion: 12/01/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include "Workstation.h"

using namespace std;

namespace sdds
{
    Workstation::Workstation(const string &src) : Station(src)
    {
        m_pNextStation = NULL;
    }

    void Workstation::fill(std::ostream &os)
    {
        if (!m_orders.empty())
        {
            m_orders.front().fillItem(*this, os);
        }
    }

    bool Workstation::attemptToMoveOrder()
    {
        if (!m_orders.empty())
        {
            if (!m_orders.front().isItemFilled(getItemName()) && this->getQuantity() > 0)
            {
                return false; // do nothing
            }
            else if (!m_orders.front().isItemFilled(getItemName()) && this->getQuantity() <= 0)
            {
                if (m_pNextStation)
                {
                    *m_pNextStation += move(m_orders.front());
                }
                else
                {
                    g_incomplete.push_back(move(m_orders.front()));
                }
                m_orders.pop_front();
                return true;
            }
            else if (m_orders.front().isItemFilled(getItemName()))
            {
                if (m_pNextStation)
                {
                    *m_pNextStation += move(m_orders.front());
                }
                else
                {
                    if (m_orders.front().isOrderFilled())
                    {
                        g_completed.push_back(move(m_orders.front()));
                    }
                    else
                    {
                        g_incomplete.push_back(move(m_orders.front()));
                    }
                }
                m_orders.pop_front();
                return true;
            }
        }
        return false;
    }

    void Workstation::setNextStation(Workstation *station)
    {
        m_pNextStation = station;
    }

    Workstation *Workstation::getNextStation() const
    {
        return m_pNextStation;
    }

    void Workstation::display(std::ostream &os) const
    {
        if (m_pNextStation)
        {
            os << getItemName() << " --> " << m_pNextStation->getItemName() << endl;
        }
        else
        {
            os << getItemName() << " --> "
               << "End of Line" << endl;
        }
    }

    Workstation &Workstation::operator+=(CustomerOrder &&newOrder)
    {
        m_orders.push_back(move(newOrder));
        return *this;
    }

} // namespace sdds