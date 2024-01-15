/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NDD

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Book.h"

namespace sdds
{

    template <typename T, const unsigned C>
    class Collection
    {
    private:
        T m_items[C];
        unsigned m_size;

        static T m_smallestItem;
        static T m_largestItem;
        const unsigned m_capacity = C;

    protected:
        void setSmallestItem(const T &item)
        {
            if (item < m_smallestItem)
            {
                m_smallestItem = item;
            }
        }

        void setLargestItem(const T &item)
        {
            if (m_largestItem < item)
            {
                m_largestItem = item;
            }
        }

    public:
        Collection() : m_items{}
        {
            m_size = 0;
        }

        Collection(const Collection &) = delete;

        ~Collection() = default;

        static T getSmallestItem()
        {
            return m_smallestItem;
        }

        static T getLargestItem()
        {
            return m_largestItem;
        }

        unsigned size() const
        {
            return m_size;
        }

        unsigned capacity() const
        {
            return m_capacity;
        }

        bool operator+=(const T &objectT)
        {
            if (m_size < m_capacity)
            {
                setSmallestItem(objectT);
                setLargestItem(objectT);
                m_items[m_size] = objectT;
                m_size++;
                return true;
            }
            else
            {
                return false;
            }
        }

        void print(std::ostream &out) const
        {
            if (*this)
            {
                out << '[';

                for (size_t i = 0u; i < m_size; i++)
                {
                    out << m_items[i] << ((i == (m_size - 1)) ? ']' : ',');
                }

                out << std::endl;
            }
        }

        operator bool() const
        {
            return m_size;
        }

        T &operator[](const unsigned aIndex)
        {
            if (aIndex < m_size)
            {
                return m_items[aIndex];
            }
            else
            {
                return m_items[0];
            }
        }

        void incrSize()
        {
            if (m_size < m_capacity)
            {
                m_size++;
            }
        }
    };

    template <typename T, const unsigned C>
    T Collection<T, C>::m_smallestItem = 9999;
    template <typename T, const unsigned C>
    T Collection<T, C>::m_largestItem = -9999;

    template <>
    Book Collection<Book, 10>::m_smallestItem("", 1, 1000);
    template <>
    Book Collection<Book, 10>::m_largestItem("", 10000, 1);

    template <>
    Book Collection<Book, 72>::m_smallestItem("", 1, 10000);
    template <>
    Book Collection<Book, 72>::m_largestItem("", 10000, 1);

    template <>
    void Collection<Book, 10>::print(std::ostream &out) const
    {
        if (*this)
        {
            out << std::setfill('-') << std::setw(77) << "| " << '|' << std::endl;
            out << std::setfill(' ');
            for (size_t i = 0; i < m_size; i++)
            {
                out << "| ";
                m_items[i].print(out) << " |" << std::endl;
            }
            out << std::setfill('-') << std::setw(77) << "| " << '|' << std::endl;
            out << std::setfill(' ');
        }
    }

    template <>
    void Collection<Book, 72>::print(std::ostream &out) const
    {
        if (*this)
        {
            out << std::setfill('-') << std::setw(77) << "| " << '|' << std::endl;
            out << std::setfill(' ');
            for (size_t i = 0; i < m_size; i++)
            {
                out << "| ";
                m_items[i].print(out) << " |" << std::endl;
            }
            out << std::setfill('-') << std::setw(77) << "| " << '|' << std::endl;
            out << std::setfill(' ');
        }
    }
}
#endif // !SDDS_COLLECTIONS_H