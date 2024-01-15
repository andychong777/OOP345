/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #5
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NDD

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <iomanip>
#include <string>
#include "Movie.h"
#include "Book.h"

using namespace std;
namespace sdds
{
	Movie::Movie(const std::string &strMovie)
	{
		string temp{};
		string copy = strMovie;
		size_t delim{};

		delim = copy.find_first_of(',');
		temp = copy.substr(0, delim);
		m_title = cutSpaces(temp);
		copy.erase(0, delim + 1);

		delim = copy.find_first_of(',');
		temp = copy.substr(0, delim);
		temp = cutSpaces(temp);
		m_release = stoi(temp);
		copy.erase(0, delim + 1);

		temp = copy.substr(0, strMovie.length() - 1);
		m_description = cutSpaces(temp);
	}
	const std::string &sdds::Movie::title() const
	{
		return m_title;
	}
	std::ostream &Movie::print(std::ostream &out) const
	{
		out << setw(40) << m_title << " | "
			<< setw(4) << m_release << " | "
			<< setw(5) << m_description << endl;
		;
		return out;
	}
	std::ostream &operator<<(std::ostream &out, const Movie &movie)
	{
		return movie.print(out);
	}
}