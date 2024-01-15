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
#include "Cheese.h"

using namespace sdds;

Cheese::Cheese()
{
    m_name = "NaC";
}

Cheese::Cheese(const std::string &str)
{
    std::string right = str;
    std::string tmp;

    right = right.substr(right.find_first_not_of(" \t"));    // strip leading whitespace
    tmp = right.substr(0, right.find_first_of(","));         // stop at comma
    m_name = tmp.substr(0, tmp.find_last_not_of(" \t") + 1); // strip trailing whitespace
    right = right.substr(right.find_first_of(",") + 1);      // remove left, keep right

    right = right.substr(right.find_first_not_of(" \t"));            // strip leading whitespace
    tmp = right.substr(0, right.find_first_of(","));                 // stop at comma
    m_weight = stoi(tmp.substr(0, tmp.find_last_not_of(" \t") + 1)); // strip trailing whitespace
    right = right.substr(right.find_first_of(",") + 1);              // remove left, keep right

    right = right.substr(right.find_first_not_of(" \t"));           // strip leading whitespace
    tmp = right.substr(0, right.find_first_of(","));                // stop at comma
    m_price = stod(tmp.substr(0, tmp.find_last_not_of(" \t") + 1)); // strip trailing whitespace
    right = right.substr(right.find_first_of(",") + 1);             // remove left, keep right

    m_features = "";
    int cnt = 0;
    right = right.substr(right.find_first_not_of(" \t")); // strip leading whitespace
    while (cnt < 4)
    {
        if (cnt++ > 0)
        {
            m_features += " ";
        }
        tmp = right.substr(0, right.find_first_of(","));              // stop at comma
        m_features += tmp.substr(0, tmp.find_last_not_of(" \t") + 1); // strip trailing whitespace
        std::string old = right;
        right = right.substr(right.find_first_of(",") + 1); // remove left, keep right
        if (old == right)
        {
            break;
        }

        right = right.substr(right.find_first_not_of(" \t")); // strip leading whitespace
    }
}

Cheese::Cheese(const Cheese &block)
{
    m_name = block.m_name;
    m_weight = block.m_weight;
    m_price = block.m_price;
    m_features = block.m_features;
}

Cheese Cheese::slice(size_t weight) {
    if (weight <= static_cast<size_t>(m_weight)) {
        Cheese piece(*this); // Use copy constructor to create a new Cheese object
        piece.m_weight = static_cast<int>(weight);
        m_weight -= static_cast<int>(weight);
        return piece;
    } else {
        // Return an empty Cheese object if the requested weight is invalid
        return Cheese();
    }
}

std::string Cheese::getName() const
{
    return m_name;
}
int Cheese::getWeight() const
{
    return m_weight;
}
double Cheese::getPrice() const
{
    return m_price;
}
std::string Cheese::getFeatures() const
{
    return m_features;
}

std::ostream &sdds::operator<<(std::ostream &out, const Cheese &cheese)
{
    out << "|" << std::setw(21) << std::setiosflags(std::ios::left) << cheese.getName()
        << "|" << std::setw(5) << cheese.getWeight()
        << "|" << std::setw(5) << std::setprecision(2) << std::setiosflags(std::ios::fixed) << cheese.getPrice()
        << "|" << std::setw(33) << std::setiosflags(std::ios::right) << cheese.getFeatures()
        << " |" << std::resetiosflags(std::ios::right) << std::endl;
    return out;
}