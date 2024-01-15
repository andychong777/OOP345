/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NDD

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_FILESYSTEM_H
#define SDDS_FILESYSTEM_H

#include <string>
#include "Directory.h"

namespace sdds
{
	class Filesystem
	{
		Directory* m_root{};
		Directory* m_current{};

		void addResource(std::string&,const std::string& = "");
	public:
		Filesystem(const char*, const std::string& = std::string());

		Filesystem& operator=(Filesystem&) = delete;
		Filesystem(Filesystem&) = delete;

		Filesystem(Filesystem&&) noexcept;
		Filesystem& operator=(Filesystem&&) noexcept;

		Filesystem& operator+=(Resource*);

		Directory* change_directory(const std::string& = "");

		Directory* get_current_directory() const;

		~Filesystem();
	};

	void trimString(std::string&);
}

#endif