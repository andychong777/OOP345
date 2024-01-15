/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #1
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NDD

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H
#include <chrono>
namespace sdds
{
    class Timer
    {
    private:
        std::chrono::steady_clock::time_point startTime;

    public:
        void start();
        long long stop();
    };
}
#endif // !SDDS_TIMER_H
