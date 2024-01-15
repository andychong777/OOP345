/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NDD

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <vector>
#include <sstream>
#include <numeric>
#include "CovidCollection.h"

using namespace std;

namespace sdds
{
    bool operator<(const std::string &a, const std::string &b)
    {
        return false;
    }

    sdds::CovidCollection::CovidCollection(const char *nameFile)
    {
        fstream file(nameFile);

        if (file)
        {
            while (file.peek() != EOF)
            {
                Covid newCovid{};
                string tempYear{};
                string tempCases{};
                string tempDeaths{};

                char temp[26]{};
                char tempNumber[6]{};

                file.read(temp, 25);
                newCovid.m_country = temp;
                trimString(newCovid.m_country);

                file.read(temp, 25);
                newCovid.m_city = temp;
                trimString(newCovid.m_city);

                file.read(temp, 25);
                newCovid.m_variant = temp;
                trimString(newCovid.m_variant);

                file.read(tempNumber, 5);
                tempYear = tempNumber;
                trimString(tempYear);
                newCovid.m_year = stoi(tempYear);

                file.read(tempNumber, 5);
                tempCases = tempNumber;
                trimString(tempCases);
                newCovid.m_cases = stoul(tempCases);

                file >> tempDeaths;
                trimString(tempDeaths);
                newCovid.m_deaths = stoul(tempDeaths);

                file.ignore(numeric_limits<std::streamsize>::max(), '\n');

                m_coll.push_back(newCovid);
            }
        }
        else
        {
            throw "File could not be reached";
        }
    }

    bool CovidCollection::inCollection(const std::string &variant, const std::string &country, unsigned int deaths) const
    {
        return any_of(m_coll.begin(), m_coll.end(), [=](const Covid &cov)
                      { return cov.m_variant == variant && cov.m_country == country && cov.m_deaths > deaths; });
    }

    std::list<Covid> CovidCollection::getListForDeaths(unsigned int deaths) const
    {
        list<Covid> list{};
        copy_if(m_coll.begin(), m_coll.end(), std::back_inserter(list), [=](const Covid &cov) -> bool
                { return cov.m_deaths >= deaths; });
        return list;
    }

    void CovidCollection::updateStatus()
    {
        transform(m_coll.begin(), m_coll.end(), m_coll.begin(), [](const Covid &cov)
                  {
			Covid newCov = cov;
			if (cov.m_deaths > EPIDEMIC_DEATHS)
				newCov.m_severity = "EPIDEMIC";
			else if(cov.m_deaths < EARLY_DEATHS)
				newCov.m_severity = "EARLY";
			else
				newCov.m_severity = "MILD";
			return newCov; });
    }

    void CovidCollection::trimString(std::string &src)
    {
        size_t begin = src.find_first_not_of(" \t\n");
        size_t end = src.find_last_not_of(" \t\n");
        string res{};
        if (begin != string::npos && end != string::npos)
        {
            res = src.substr(begin, end - begin + 1);
        }
        else
        {
            res = "";
        }
        src = res;
    }

    void CovidCollection::display(std::ostream &out, const std::string &country) const
    {
        const size_t totalCases = accumulate(m_coll.begin(), m_coll.end(), 0, [](size_t sum, const Covid &cov)
                                             { return sum + cov.m_cases; });
        const size_t totalDeaths = accumulate(m_coll.begin(), m_coll.end(), 0, [](size_t sum, const Covid &cov)
                                              { return sum + cov.m_deaths; });

        if (country == "ALL")
        {
            for_each(m_coll.begin(), m_coll.end(), [=, &out](Covid cov)
                     { out << cov << endl; }); // print all covids
            out << "|" << setw(80) << setiosflags(ios::right) << "Total cases around the world: " << totalCases << " |\n"
                << "|" << setw(80) << "Total deaths around the world: " << totalDeaths << " |\n"
                << resetiosflags(ios::right);
        }
        else
        {
            const size_t localCases = accumulate(m_coll.begin(), m_coll.end(), 0, [country](size_t sum, const Covid &cov)
                                                 {
				if (cov.m_country == country)
					return sum + cov.m_cases;
				else
					return sum; });
            const size_t localDeaths = accumulate(m_coll.begin(), m_coll.end(), 0, [country](size_t sum, const Covid &cov)
                                                  {
				if (cov.m_country == country)
					return sum + cov.m_deaths;
				else
					return sum; });

            stringstream TotCases{};
            stringstream TotDeaths{};
            stringstream TotPercent{};

            out << "Displaying information of country = " << country << "\n";
            for_each(m_coll.begin(), m_coll.end(), [=, &out, &localCases, &localDeaths](Covid cov) // print all covids for given country
                     {
					if (cov.m_country == country)
						out << cov << endl;; });

            out << setfill('-') << setw(89) << '\n'
                << setfill(' ');
            TotCases << "Total cases in " << country << ": " << localCases;
            out << "|" << setw(85) << setiosflags(ios::right) << TotCases.str() << " |\n";
            TotDeaths << "Total deaths in " << country << ": " << localDeaths;
            out << "|" << setw(85) << TotDeaths.str() << " |\n";
            TotPercent << country << " has " << setprecision(6) << setiosflags(ios::fixed) << ((double)localCases / totalCases) * 100 << "% of global cases and " << ((double)localDeaths / totalDeaths) * 100 << "% of global deaths";
            out << "|" << setw(85) << TotPercent.str() << " |\n"
                << resetiosflags(ios::right);
        }
    }

    void CovidCollection::sort(const std::string &field)
    {
        if (field == "city")
        {
            std::sort(m_coll.begin(), m_coll.end(), [=](const Covid &a, const Covid &b)
                      {
				if (a.m_city.compare(b.m_city) < 0)
				{
					return true;
				}
				else if (a.m_city.compare(b.m_city) > 0)
				{
					return false;
				}
				else 
				{
					if (a.m_deaths < b.m_deaths)
					{
						return true;
					}
					else
					{
						return false;
					}
				} });
        }
        else if (field == "variant")
        {
            std::sort(m_coll.begin(), m_coll.end(), [=](const Covid &a, const Covid &b)
                      {
				if (a.m_variant.compare(b.m_variant) < 0)
				{
					return true;
				}
				else if (a.m_variant.compare(b.m_variant) > 0)
				{
					return false;
				}
				else 
				{
					if (a.m_deaths < b.m_deaths)
					{
						return true;
					}
					else if (a.m_deaths > b.m_deaths)
					{
						return false;
					}
					else 
					{
						return a.m_year < b.m_year;
					}
				} });
        }
        else if (field == "year")
        {
            std::sort(m_coll.begin(), m_coll.end(), [=](const Covid &a, const Covid &b)
                      {
				if (a.m_year < b.m_year)
				{
					return true;
				}
				else if (a.m_year > b.m_year)
				{
					return false;
				}
				else
				{
					if (a.m_deaths < b.m_deaths)
					{
						return true;
					}
					else
					{
						return false;
					}
				} });
        }
        else if (field == "cases")
        {
            std::sort(m_coll.begin(), m_coll.end(), [=](const Covid &a, const Covid &b)
                      {
				if (a.m_cases > b.m_cases)
				{
					return true;
				}
				else if (a.m_cases < b.m_cases)
				{
					return false;
				}
				else
				{
					if (a.m_deaths < b.m_deaths)
					{
						return true;
					}
					else
					{
						return false;
					}
				} });
        }
        else if (field == "deaths")
        {
            std::sort(m_coll.begin(), m_coll.end(), [=](const Covid &a, const Covid &b)
                      {
				if (a.m_deaths > b.m_deaths)
				{
					return true;
				}
				else
				{
					return false;
				} });
        }
        else if (field == "severity")
        {
            std::sort(m_coll.begin(), m_coll.end(), [=](const Covid &a, const Covid &b)
                      {
				if (a.m_severity.compare(b.m_severity) < 0)
				{
					return true;
				}
				else if (a.m_severity.compare(b.m_severity) > 0)
				{
					return false;
				}
				else 
				{
					if (a.m_deaths < b.m_deaths)
					{
						return true;
					}
					else
					{
						return false;
					}
				} });
        }
        else
        {
            std::sort(m_coll.begin(), m_coll.end(), [=](const Covid &a, const Covid &b)
                      {
				if (a.m_country.compare(b.m_country) < 0)
				{
					return true;
				}
				else if (a.m_country.compare(b.m_country) > 0)
				{
					return false;
				}
				else 
				{
					if (a.m_deaths < b.m_deaths)
					{
						return true;
					}
					else 
					{
						return false;
					}
				} });
        }
    }

    std::ostream &operator<<(std::ostream &out, const Covid &theCovid)
    {
        out << "| " << setw(21) << std::left << theCovid.m_country << " | "
            << setw(15) << theCovid.m_city << " | "
            << setw(20) << theCovid.m_variant << " | " << resetiosflags(ios::left)
            << setw(6);
        if (theCovid.m_year > 0)
            out << theCovid.m_year << " | ";
        else
            out << " "
                << " | ";

        out << setw(4) << theCovid.m_cases << " | "
            << setw(3) << theCovid.m_deaths << " | "
            << "| " << setw(8) << theCovid.m_severity << " |";

        return out;
    }

}