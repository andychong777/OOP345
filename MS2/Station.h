// Name: Andy Chong
// Seneca Student ID: 150558229
// Seneca email: achong11@gmail.com
// Date of completion: 11/17/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <iostream>

namespace sdds{
    class Station
    {
    private:
        int m_id {0};
        std::string m_itemName {""};
        std::string m_desc {""};
        size_t m_serialNumber {0u};
        size_t m_inStock {0u};

        static size_t m_widthField;
        static size_t id_generator;
        
    public:
        Station(const std::string& src);

        const std::string& getItemName() const; //returns the name of the current Station object

        size_t getNextSerialNumber(); //returns the next serial number to be used

        size_t getQuantity() const; //returns the remaining quantity of items

        void updateQuantity(); //subtracts 1 from the available quantity

        void display(std::ostream& os, bool full) const; //inserts information about the current object into stream os

    };
}

#endif // !SDDS_STATION_H