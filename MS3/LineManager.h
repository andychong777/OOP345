// Name: Andy Chong
// Seneca Student ID: 150558229
// Seneca email: achong11@gmail.com
// Date of completion: 12/01/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H

#include <iostream>
#include <vector>
#include "Workstation.h"

namespace sdds
{

    class LineManager
    {
    private:
        std::vector<Workstation *> m_activeLine;
        size_t m_cntCustomerOrder;
        Workstation *m_firstStation;

        Workstation *get_ws(std::string token, const std::vector<Workstation *> &stations);
        int findNext(std::vector<std::string> vec, std::string token);

    public:
        LineManager(const std::string &file, const std::vector<Workstation *> &stations);

        void reorderStations();

        bool run(std::ostream &os);

        void display(std::ostream &os) const; // inserts information about the current object into stream os
    };
}

#endif // !SDDS_WORKSTATION_H