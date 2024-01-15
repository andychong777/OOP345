/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #5
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NDD

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <string>
#include <stdexcept>
#include <iostream>

namespace sdds
{
	template <typename T>
	class Collection
	{
		std::string m_name{};
		T *m_items{};
		unsigned m_size{};
		void (*m_observer)(const Collection<T> &, const T &){};

	public:
		Collection() = default;
		Collection(const std::string &name) : Collection<T>()
		{
			m_name = name;
		}
		Collection(const Collection &other) = delete;
		Collection(const Collection &&other) = delete;
		Collection &operator=(const Collection &other) = delete;
		Collection &operator=(const Collection &&other) = delete;
		~Collection()
		{
			delete[] m_items;
		}
		operator bool() const
		{
			return (m_size > 0);
		}

		const std::string &name() const
		{
			return m_name;
		}

		size_t size() const
		{
			return m_size;
		}
		void setObserver(void (*observer)(const Collection<T> &, const T &))
		{
			m_observer = observer;
		}
		Collection<T> &operator+=(const T &item)
		{
			bool dupe = false;

			for (size_t i = 0; i < m_size && !dupe; i++)
				dupe = (m_items[i].title() == item.title());

			if (!dupe)
			{
				T *newArr = new T[m_size + 1];

				for (size_t i = 0; i < m_size; i++)
					newArr[i] = m_items[i];
				newArr[m_size] = item;

				delete[] m_items;
				m_items = newArr;
				m_size++;

				if (m_observer != nullptr)
					m_observer(*this, item);
			}
			return *this;
		}
		T &operator[](size_t idx) const
		{
			if (idx >= m_size)
			{
				throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.");
			}
			else
			{
				return m_items[idx];
			}
		}
		T *operator[](const char *title) const
		{
			T *item = nullptr;
			for (size_t i = 0; i < m_size; i++)
			{
				if (m_items[i].title() == title)
					item = &m_items[i];
			}
			return item;
		}

		std::ostream &print(std::ostream &out) const
		{
			for (size_t i = 0; i < m_size; i++)
			{
				out << m_items[i];
			}
			return out;
		}

		friend std::ostream &operator<<(std::ostream &out, Collection &call)
		{
			return call.print(out);
		}
	};
}

#endif // SDDS_COLLECTION_H
