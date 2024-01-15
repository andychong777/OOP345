/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #1
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NDD

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <cstring>
#include <iomanip>
#include <string>

#include "RideRequest.h"

using namespace std;

double g_taxrate = 0;
double g_discount = 0;

namespace sdds
{

    RideRequest::operator bool() const
    {
        return customerName && customerName[0] != '\0';
    }

    void RideRequest::copyAndAllocate(char *&destination, const char *source)
    {
        delete[] destination;
        destination = nullptr;

        if (source && source[0] != '\0')
        {
            destination = new char[strlen(source) + 1];
            strcpy(destination, source);
        }
    }

    RideRequest::RideRequest()
    {
    }

    RideRequest::~RideRequest()
    {
        delete[] description;
    }

    RideRequest::RideRequest(const RideRequest &request)
    {
        *this = request;
    }

    RideRequest &RideRequest::operator=(const RideRequest &request)
    {
        if (this != &request)
        {
            strcpy(customerName, request.customerName);

            discount = request.discount;
            price = request.price;

            copyAndAllocate(description, request.description);
        }
        return *this;
    }

    istream &RideRequest::read(istream &istream)
    {
        if (istream)
        {
            char rideDesc[256]{};
            char discountStatus;

            istream.getline(customerName, 11, ',');
            istream.getline(rideDesc, 256, ',');

            if (rideDesc)
            {
                copyAndAllocate(description, rideDesc);
            }

            istream >> price;
            istream.ignore(1);
            istream >> discountStatus;
            discount = (discountStatus == 'Y');
            istream.ignore(2000, '\n');
        }
        else
        {
            delete[] description;
            description = nullptr;
        }

        return istream;
    }

    ostream &RideRequest::display(ostream &ostream) const
    {
        int counter = 1;
        cout << left << setw(2) << counter++ << ". ";

        if (*this)
        {
            cout << setw(10) << customerName << '|';
            cout << setw(25) << description;
            cout << '|' << fixed << setprecision(2) << setw(12)
                 << price * (1 + g_taxrate)
                 << '|' << right << setw(13);

            if (discount)
            {
                cout << price * (1 + g_taxrate) - g_discount;
            }
            cout << "\n";
        }
        else
        {
            cout << "No Ride Request" << "\n";
        }
        return ostream;
    }
}
