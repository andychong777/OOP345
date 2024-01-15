// Name: Andy Chong
// Seneca Student ID: 150558229
// Seneca email: achong11@gmail.com
// Date of completion: 12/01/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include <iostream>
#include <deque>
#include "CustomerOrder.h"
#include "Station.h"

namespace sdds
{
    inline std::deque<CustomerOrder> g_pending;
    inline std::deque<CustomerOrder> g_completed;
    inline std::deque<CustomerOrder> g_incomplete;

    class Workstation : public Station
    {
    private:
        std::deque<CustomerOrder> m_orders;
        Workstation *m_pNextStation;

    public:
        Workstation(const std::string &src);

        void fill(std::ostream &os);

        bool attemptToMoveOrder();

        void setNextStation(Workstation *station);

        Workstation *getNextStation() const;

        void display(std::ostream &os) const; // inserts information about the current object into stream os

        Workstation &operator+=(CustomerOrder &&newOrder);
    };
}

#endif // !SDDS_WORKSTATION_H