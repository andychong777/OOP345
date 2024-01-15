/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NDD

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#include "File.h"
#include <string>

namespace sdds
{

    File::File(const std::string &name, const std::string &content)
        : m_name(name), m_content(content)
    {
    }

    void File::update_parent_path(const std::string &new_path)
    {
        m_parentPath = new_path;
    }

    NodeType File::type() const
    {
        return NodeType::FILE;
    }

    std::string File::path() const
    {
        return m_parentPath.empty() ? m_name : m_parentPath + "/" + m_name;
    }

    std::string File::name() const
    {
        return m_name;
    }

    int File::count() const
    {
        return -1;
    }

    size_t File::size() const
    {
        return m_content.size();
    }

}