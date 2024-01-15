/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NDD

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_ORDERED_COLLECTION_H
#define SDDS_ORDERED_COLLECTION_H

#include "Collection.h"

namespace sdds
{
	template <typename T>
	class OrderedCollection : public Collection<T, 72u>
	{
	public:
		OrderedCollection() : Collection<T, 72u>() {};

		OrderedCollection(const OrderedCollection& oc) = delete;

		~OrderedCollection() = default;
		
		bool operator+=(const T& objectT)
		{
			if (this->size() < this->capacity())
			{
				this->incrSize();
				
				if (objectT > this->getLargestItem())
				{
					this->operator[](this->size()-1) = objectT;
					this->setLargestItem(objectT);
				}
				else
				{
					unsigned int targetIndex = 0u;
					bool foundTarget = false;
					for (unsigned i = 0u; i < this->size() && !foundTarget; i++)
					{
						if (this->operator[](i) > objectT)
						{
							targetIndex = i;
							foundTarget = true;
						}
					}

					for (unsigned i = (this->size() - 1); i > targetIndex; i--)
					{
						this->operator[](i) = this->operator[](i - 1);
					}
					this->operator[](targetIndex) = objectT;
					
				}
				this->setSmallestItem(objectT);
				return true;
			}
			else
			{
				return false;
			}
		}
	};
}

#endif // !SDDS_ORDERED_COLLECTION_H