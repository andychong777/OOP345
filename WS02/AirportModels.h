/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NDD

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_AIRPORTMODELS_H
#define SDDS_AIRPORTMODELS_H
#include <iostream>
#include <string>

namespace sdds
{
    struct Airport
    {
        std::string m_code = "";    // Default empty string
        std::string m_name = "";    // Default empty string
        std::string m_city = "";    // Default empty string
        std::string m_state = "";   // Default empty string
        std::string m_country = ""; // Default empty string
        double m_latitude = 0.0;    // Default 0.0
        double m_longitude = 0.0;   // Default 0.0

    public:
        Airport();
        Airport(const char *code,
                const char *name,
                const char *city,
                const char *state,
                const char *country,
                const double latitude,
                const double longitude);
        Airport(const Airport &source);
        Airport &operator=(const Airport &source);

        std::ostream &print(std::ostream &os) const;
        std::istream &read(std::istream &is);
        operator bool() const;

        std::string getState() const;
        std::string getCountry() const;
    };
    std::ostream &operator<<(std::ostream &os, const Airport &A);
    std::istream &operator>>(std::istream &is, Airport &A);

    class AirportLog
    {
        Airport *m_airportArr{};
        size_t m_size{};

    public:
        AirportLog();
        AirportLog(const char *fName);
        AirportLog(const AirportLog &source);
        AirportLog &operator=(const AirportLog &source);
        ~AirportLog();

        void addAirport(const Airport &newAirport);
        AirportLog findAirport(const char *state, const char *country) const;

        Airport operator[](size_t i);
        operator size_t();
    };
}

#endif // !SDDS_AIRPORTMODELS_H