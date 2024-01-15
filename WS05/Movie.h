/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #5
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NDD

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <iostream>
#include <string>

namespace sdds
{
	class Movie
	{
		std::string m_title{};
		size_t m_release{};
		std::string m_description{};

	public:
		Movie() = default;
		Movie(const std::string &strMovie);
		const std::string &title() const;
		std::ostream &print(std::ostream &out) const;

		template <typename T>
		void fixSpelling(T &spellChecker)
		{
			spellChecker(m_title);
			spellChecker(m_description);
		}

		friend std::ostream &operator<<(std::ostream &out, const Movie &movie);
	};
}

#endif // !SDDS_MOVIE_H