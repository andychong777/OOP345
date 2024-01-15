/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NDD

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#include "SpellChecker.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

namespace sdds
{
    sdds::SpellChecker::SpellChecker(const char *filename)
    {
        ifstream wordFile(filename);
        if (wordFile)
        {
            string line{};
            size_t count = 0u;
            while (wordFile && count < WORD_COUNT)
            {
                getline(wordFile, line);
                readWords(line, m_badWords[count], m_goodWords[count]);
                count++;
            }
        }
        else
        {
            throw "Bad file name!";
        }
    }
    void SpellChecker::operator()(std::string &text)
    {
        unsigned wordsTocheck = 0u;

        do
        {

            unsigned position{};
            bool foundBadWord{};
            do
            {
                position = text.find(m_badWords[wordsTocheck]);
                foundBadWord = position <= text.length();
                if (foundBadWord)
                {
                    text.replace(position, m_badWords[wordsTocheck].length(), m_goodWords[wordsTocheck]);

                    m_numFixed[wordsTocheck]++;
                }
            } while (foundBadWord);

            wordsTocheck++;
        } while (wordsTocheck < WORD_COUNT);
    }
    void SpellChecker::showStatistics(std::ostream &out) const
    {
        out << "Spellchecker Statistics" << endl;
        for (size_t i = 0; i < WORD_COUNT; i++)
        {
            out << setiosflags(ios::right) << setw(15) << m_badWords[i] << ": "
                << m_numFixed[i] << " replacements"
                << endl;
        }
    }
    void readWords(std::string line, std::string &bad, std::string &good)
    {
        size_t position = 0u;
        size_t lineSize = line.length();

        while (!isspace(line[position]) && position < lineSize)
        {
            bad += line[position];
            position++;
        }
        while (isspace(line[position]) && position < lineSize)
        {
            position++;
        }

        while (!isspace(line[position]) && position < lineSize)
        {
            good += line[position];
            position++;
        }
    }
}