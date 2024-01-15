/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NDD

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_COVIDCOLLECTION_H
#define SDDS_COVIDCOLLECTION_H
#include <string>
#include <vector>
#include <list>

namespace sdds
{
    const size_t EARLY_DEATHS = 50;
    const size_t EPIDEMIC_DEATHS = 300;
    
    struct Covid
    {
        std::string m_country{}; // Country
        std::string m_city{};    //City
        std::string m_variant{}; // Variant
        int m_year{};            // Year
        size_t m_cases{};        // Number of Cases
        size_t m_deaths{};       // Number of Deaths
        std::string m_severity{"General"}; //severity of infection
    };

    class CovidCollection
    {
        std::vector<Covid> m_coll{};

        void trimString(std::string &src);

    public:
        CovidCollection() = default;
        CovidCollection(const char *nameFile); // Custom Constructor
        
        void display(std::ostream &out, const std::string &country = "ALL") const; // Display
        void sort(const std::string &field = "country"); // Sort covid objects in ascending order

        // Search for a city in the specified country
        bool inCollection(const std::string &variant, const std::string &country, unsigned int deaths) const; 

        std::list<Covid> getListForDeaths(unsigned int deaths) const; //List of deaths
        void updateStatus(); //Updates the status of each city
    };
    std::ostream &operator<<(std::ostream &out, const Covid &theCovid); // Helper

}

#endif // !SDDS_COVIDCOLLECTION_H