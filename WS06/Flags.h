/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NDD

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_FLAGS_H
#define SDDS_FLAGS_H

namespace sdds
{
    // Options for displaying the files and directories
    enum class FormatFlags
    {
        LONG, // to display in long format
    };

    // Determine the type of filesystem resource
    enum class NodeType
    {
        DIR, // Directory
        FILE // Regular File
    };

    // Options for performing a filesystem operation
    enum class OpFlags
    {
        RECURSIVE, // run an operation recursively
    };
}

#endif