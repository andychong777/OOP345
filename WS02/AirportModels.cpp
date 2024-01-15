/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NDD

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#include <iomanip>
#include <fstream>
#include "AirportModels.h"
using namespace std;
namespace sdds
{
    Airport::Airport() {}

    Airport::Airport(const char *code,
                     const char *name,
                     const char *city,
                     const char *state,
                     const char *country,
                     const double latitude,
                     const double longitude) : m_code(code), m_name(name), m_city(city), m_state(state),
                                               m_country(country), m_latitude(latitude), m_longitude(longitude) {}
    Airport::Airport(const Airport &source)
    {
        *this = source;
    }
    std::ostream &Airport::print(std::ostream &os) const
    {
        if (*this)
        {
            os.fill('.');
            os << right << setw(20) << "Airport Code"
               << " : " << left << setw(30) << m_code << "\n"
               << right << setw(20) << "Airport Name"
               << " : " << left << setw(30) << m_name << "\n"
               << right << setw(20) << "City"
               << " : " << left << setw(30) << m_city << "\n"
               << right << setw(20) << "State"
               << " : " << left << setw(30) << m_state << "\n"
               << right << setw(20) << "Country"
               << " : " << left << setw(30) << m_country << "\n"
               << right << setw(20) << "Latitude"
               << " : " << left << setw(30) << m_latitude << "\n"
               << right << setw(20) << "Longitude"
               << " : " << left << setw(30) << m_longitude << '\n';
        }
        else
            cout << "Empty Airport";

        return os;
    }
    istream &Airport::read(istream &is)
    {
        if (is)
        {
            getline(is, m_code, ',');
            getline(is, m_name, ',');
            getline(is, m_city, ',');
            getline(is, m_state, ',');
            getline(is, m_country, ',');
            is >> m_latitude;
            is.ignore();
            is >> m_longitude;
            is.ignore();
        }
        return is;
    }
    Airport::operator bool() const
    {
        return m_name[0] != '\0';
    }

    string Airport::getState() const
    {
        return m_state;
    }
    string Airport::getCountry() const
    {
        return m_country;
    }
    ostream &operator<<(ostream &os, const Airport &A)
    {
        return A.print(os);
    }
    istream &operator>>(istream &is, Airport &A)
    {
        return A.read(is);
    }

    Airport &Airport::operator=(const Airport &source)
    {
        if (this != &source)
        {
            m_code = source.m_code;
            m_name = source.m_name;
            m_city = source.m_city;
            m_state = source.m_state;
            m_country = source.m_country;
            m_latitude = source.m_latitude;
            m_longitude = source.m_longitude;
        }
        return *this;
    }

    AirportLog::AirportLog() {}
    AirportLog::AirportLog(const char *fName)
    {
        ifstream fptr(fName);
        string tempStr;

        if (fptr.is_open())
        {
            while (getline(fptr, tempStr))
                m_size++;
            m_size--;
            fptr.close();
        }

        if (m_size > 0)
        {
            fptr.open(fName);

            while (fptr.get() != '\n')
                ;

            m_airportArr = new Airport[m_size];
            for (size_t i = 0; i < m_size; i++)
                m_airportArr[i].read(fptr);

            fptr.close();
        }
    }
    AirportLog::AirportLog(const AirportLog &source)
    {
        *this = source;
    }
    AirportLog &AirportLog::operator=(const AirportLog &source)
    {
        if (this != &source)
        {
            m_size = source.m_size;

            delete[] m_airportArr;
            m_airportArr = new Airport[m_size];
            for (size_t i = 0; i < m_size; i++)
                m_airportArr[i] = source.m_airportArr[i];
        }
        return *this;
    }
    AirportLog::~AirportLog()
    {
        delete[] m_airportArr;
    }
    void AirportLog::addAirport(const Airport &newAirport)
    {
        Airport *temp = new Airport[m_size + 1];

        for (size_t i = 0; i < m_size; i++)
            temp[i] = m_airportArr[i];

        temp[m_size++] = newAirport;

        delete[] m_airportArr;
        m_airportArr = temp;
    }
    AirportLog AirportLog::findAirport(const char *state, const char *country) const
    {
        AirportLog foundAirports;

        for (size_t i = 0; i < m_size; i++)
            if (m_airportArr[i].getState() == state && m_airportArr[i].getCountry() == country)
                foundAirports.addAirport(m_airportArr[i]);

        return foundAirports;
    }
    Airport AirportLog::operator[](size_t i)
    {
        static Airport temp{};
        if (i < m_size)
            temp = m_airportArr[i];
        return temp;
    }
    AirportLog::operator size_t()
    {
        return m_size;
    }
}