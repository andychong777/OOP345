// Name: Andy Chong
// Seneca Student ID: 150558229
// Seneca email: achong11@gmail.com
// Date of completion: 12/01/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "LineManager.h"

using namespace std;

namespace sdds
{
    LineManager::LineManager(const string &file, const vector<Workstation *> &stations)
    {
        ifstream f;
        f.open(file);
        if (f.is_open())
        {
            string line, token1, token2;
            vector<string> ones, twos;
            while (getline(f, line))
            {
                stringstream ss(line);
                getline(ss, token1, '|');
                getline(ss, token2);
                Workstation *ws = get_ws(token1, stations);
                m_activeLine.push_back(ws);
                ones.push_back(token1);
                if (token1.compare(token2) != 0)
                { // real token2
                    ws->setNextStation(get_ws(token2, stations));
                    twos.push_back(token2);
                }
                else
                {
                    twos.push_back("");
                }
            }
            f.close();
            int i = 0;
            int first = 0;
            // walk to first
            while (i != -1)
            {
                first = i;
                i = findNext(twos, ones[first]);
            }
            m_firstStation = get_ws(ones[first], stations);
            m_cntCustomerOrder = g_pending.size();
        }
        else
        {
            throw string("Failed to open file: " + file + "\n");
        }
    }

    Workstation *LineManager::get_ws(string token, const vector<Workstation *> &stations)
    {
        for (Workstation *ws : stations)
        {
            if (ws->getItemName() == token)
            {
                return ws;
            }
        }
        return NULL;
    }

    int LineManager::findNext(vector<string> vec, string token)
    {
        for (size_t i = 0; i < vec.size(); i++)
        {
            if (vec[i].compare(token) == 0)
            {
                return i;
            }
        }
        return -1;
    }

    void LineManager::reorderStations()
    {
        m_activeLine.clear();
        Workstation *next = m_firstStation;

        while (next)
        {
            m_activeLine.push_back(next);
            next = next->getNextStation();
        }
    }

    bool LineManager::run(std::ostream &os)
    {
        static size_t count = 0u;
        os << "Line Manager Iteration: " << ++count << endl;

        if (!g_pending.empty())
        {
            *m_activeLine.front() += move(g_pending.front());
            g_pending.pop_front();
        }

        for (auto ws : m_activeLine)
        {
            ws->fill(os);
        }

        for (auto ws : m_activeLine)
        {
            ws->attemptToMoveOrder();
        }

        return m_cntCustomerOrder == g_completed.size() + g_incomplete.size();
    }

    void LineManager::display(std::ostream &os) const
    { // inserts information about the current object into stream os
        for (auto ws : m_activeLine)
        {
            ws->display(os);
        }
    }
} // namespace sdds