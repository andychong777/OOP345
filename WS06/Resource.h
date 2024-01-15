/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NDD

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_RESOURCE_H
#define SDDS_RESOURCE_H

#include <iostream>
#include <string>
#include "Flags.h"

namespace sdds
{
    class Resource
    {
    protected:
        // Stores the name of the resource
        std::string m_name{};
        // Stores the absolute path of the folder where the resource is located
        std::string m_parent_path = "/";

    public:
        virtual void update_parent_path(const std::string &) = 0;
        virtual std::string name() const = 0;
        virtual int count() const = 0;
        virtual std::string path() const = 0;
        virtual size_t size() const = 0;
        virtual NodeType type() const = 0;
        virtual ~Resource() = default;
    };
} // namespace sdds

#endif
