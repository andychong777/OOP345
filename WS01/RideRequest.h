/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #1
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NDD

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_RIDEREQUEST_H
#define SDDS_RIDEREQUEST_H

extern double g_discount;
extern double g_taxrate;

namespace sdds {
    static const int NAME_LENGTH = 10;

    class RideRequest {
        char customerName[NAME_LENGTH]{};
        char* description{};
        double price{};

        operator bool()const;
        bool discount = false;

        void copyAndAllocate(char*& destination, const char* source);
    public:
		RideRequest();
		~RideRequest();
		RideRequest(const RideRequest& request);

		RideRequest& operator=(const RideRequest& request);
		std::istream& read(std::istream& istream);
		std::ostream& display(std::ostream& ostream = std::cout) const;

    };
}

#endif // !SDDS_RIDEREQUEST_H_