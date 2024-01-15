// Workshop 8 - Smart Pointers
// 2019/11 - Cornel
/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #7
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NDD

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#include <memory>
#include <utility>
#include "DataBase.h"
#include "Profile.h"
#include "Utilities.h"

using namespace std;

namespace sdds
{
	DataBase<Profile> excludeRaw(const DataBase<Profile> &allProfiles, const DataBase<Profile> &bannedProfiles)
	{
		DataBase<Profile> result;
		// TODO: Add your code here to build a collection of Profiles.
		//		   The result should contain only profiles from `allProfiles`
		//         which are not in `bannedProfiles` using Raw Pointers.
		for (size_t i = 0; i < allProfiles.size(); ++i)
		{
			bool banned = false;

			for (size_t j = 0; j < bannedProfiles.size() && !banned; ++j)
			{
				banned = (allProfiles[i].m_name.first_name == bannedProfiles[j].m_name.first_name) && (allProfiles[i].m_name.last_name == bannedProfiles[j].m_name.last_name) && (allProfiles[i].m_age == bannedProfiles[j].m_age);
			}
			if (!banned)
			{
				Profile *prof = new Profile(allProfiles[i].m_name, allProfiles[i].m_address, allProfiles[i].m_age);
				try
				{
					prof->validateAddress();
				}
				catch (...)
				{
					delete prof;
					throw;
				}

				result += prof;

				delete prof;
			}
		}
		return result;
	}

	DataBase<Profile> excludeSmart(const DataBase<Profile> &allProfiles, const DataBase<Profile> &bannedProfiles)
	{
		DataBase<Profile> result;
		// TODO: Add your code here to build a collection of Profiles.
		//		   The result should contain only profiles from `allProfiles`
		//         which are not in `bannedProfiles` using Smart Pointers.
		for (size_t i = 0; i < allProfiles.size(); ++i)
		{
			bool banned = false;

			for (size_t j = 0; j < bannedProfiles.size() && !banned; ++j)
			{
				banned = (allProfiles[i].m_name.first_name ==
							  bannedProfiles[j].m_name.first_name &&
						  (allProfiles[i].m_age == bannedProfiles[j].m_age));
			}
			if (!banned)
			{
				std::shared_ptr<Profile> p(new Profile(allProfiles[i].m_name, allProfiles[i].m_address, allProfiles[i].m_age));

				p->validateAddress();

				result += p;
			}
		}

		return result;
	}
}
