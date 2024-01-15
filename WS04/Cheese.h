/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NDD

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_CHEESE_H
#define SDDS_CHEESE_H

#include <iostream>
#include <string>

namespace sdds
{
    class Cheese
    {
    private:
        std::string m_name;
        int m_weight;
        double m_price;
        std::string m_features;

    public:
        Cheese();
        Cheese(const std::string &str);
        Cheese(const Cheese &block); // not specified in instructions but needed to be public in Part 2
        Cheese slice(size_t weight);

        std::string getName() const;
        int getWeight() const;
        double getPrice() const;
        std::string getFeatures() const;
    };

    std::ostream &operator<<(std::ostream &out, const Cheese &cheese);
}

#endif