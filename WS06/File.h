/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NDD

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_FILE_H
#define SDDS_FILE_H

#include "Resource.h"
#include <string>

namespace sdds
{

    class File : public Resource
    {
        std::string m_name;       // Stores the name of the file.
        std::string m_content;    // Stores the content of the file.
        std::string m_parentPath; // Stores the parent directory path.

    public:
        // Using std::string instead of const char* for more C++ standard compliance
        File(const std::string &name, const std::string &content = "");

        // Override the base class method to set the parent path
        void update_parent_path(const std::string &new_path) override;

        // Getter methods to encapsulate the data members
        std::string get_content() const { return m_content; }
        std::string get_parent_path() const { return m_parentPath; }

        // Polymorphic methods from Resource interface
        NodeType type() const override;
        std::string path() const override;
        std::string name() const override;
        int count() const override;
        size_t size() const override;

        // Destructor, even default, should be declared virtual in base classes
        virtual ~File() = default;

        // Deleted copy constructor and assignment operator for resource management
        File(const File &) = delete;
        File &operator=(const File &) = delete;

        // Allow move semantics for efficiency
        File(File &&) = default;
        File &operator=(File &&) = default;
    };

} // namespace sdds

#endif // SDDS_FILE_H
