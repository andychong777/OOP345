// Name: Andy Chong
// Seneca Student ID: 150558229
// Seneca email: achong11@gmail.com
// Date of completion: 11/17/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H

#include <iostream>
#include "Station.h"

namespace sdds
{
    struct Item
    {
        std::string m_itemName;
        size_t m_serialNumber{0};
        bool m_isFilled{false};

        Item(const std::string &src) : m_itemName(src){};
    };

    class CustomerOrder
    {
        std::string m_name{""};    // name of customer
        std::string m_product{""}; // name of product
        size_t m_cntItem{0u};      // number of items in customer order
        Item **m_lstItem{nullptr}; // array of pointers

        static size_t m_widthField; // max width of a field

    public:
        CustomerOrder(){}; // defaut constructor
        CustomerOrder(const std::string &source);
        CustomerOrder(const CustomerOrder &source);
        CustomerOrder &operator=(const CustomerOrder &source) = delete;
        CustomerOrder(CustomerOrder &&source) noexcept;
        CustomerOrder &operator=(CustomerOrder &&source) noexcept;
        ~CustomerOrder();

        bool isOrderFilled() const; // returns true if order filled

        bool isItemFilled(const std::string &itemName) const; // check if by itemName is filled

        void fillItem(Station &station, std::ostream &os); // fills one item in current order

        void display(std::ostream &os) const; // display
    };
}
#endif // !SDDS_CUSTOMERORDER_H