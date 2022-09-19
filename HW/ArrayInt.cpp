#include <cassert>
#include "ArrayInt.h"
#include <iostream>


ArreyInt::ArreyInt()
	:m_length(0), m_data(nullptr)
{
}

ArreyInt::~ArreyInt()
{
		delete[] m_data;
}

ArreyInt::ArreyInt(int legth)
	:m_length(legth)
{
	assert(legth > 0);

	if (legth > 0)
	{
		m_data = new int[legth];
	}
	else
	{
		m_data = nullptr;
	}
}
	

void ArreyInt::erase()
{
	delete[] m_data;
	m_data = nullptr;
	m_length = 0;
}

int ArreyInt::getLegth() { return m_length; }

int& ArreyInt::operator[](int index)
{
	assert(index >= 0 && index < m_length);
	return m_data[index];
}// перезагрузили оператор индексации чтоб иметь доступ к элементам мапссива 

void ArreyInt::resize(int newLength)
{
	if (newLength == m_length)
	{
		return;
	}
	if (newLength <= 0)
	{
		erase();
		return;
	}
	int* data = new int[newLength];

	if (m_length > 0)
	{
		int elementsToCope = (newLength > m_length) ? m_length : newLength;

		for (int index = 0; index < elementsToCope; ++index)
		{
			data[index] = m_data[index];
		}
	}

	delete[] m_data;

	m_data = data;
	m_length = newLength;
}

void ArreyInt::insertBefort(int value, int index)
{
	assert(index >= 0 && index <= m_length);

	int* data = new int[m_length + 1 ];

	for (int i = 0; i < index;i++)
	{
		data[i] = m_data[i];
	}
	data[index] = value;

	for (int i = index; i < m_length; i++)
	{
		data[i + 1] = m_data[i];
	}
	delete[] m_data;
	m_data = data;
	++m_length;
	}

void ArreyInt::push_back(int value)
{
	insertBefort(value, m_length);
}

int ArreyInt::pop_back()
{
	assert(m_length > 0);

	int item = m_data[m_length - 1];
	resize(m_length - 1);

	return item;
}

int ArreyInt::pop_front()
{
	assert(m_length > 0);

	int item = m_data[0];

	if (m_length == 1)
	{
		erase();
		return item;
	}

	int* data = new int[m_length - 1];

	for (size_t i = 1; i != m_length; i++)
	{
		data[i - 1] = m_data[i];
	}
	delete[] m_data;

	m_data = data;
	m_length--;

	return item;
};

void ArreyInt::sort()
{
	for (size_t i = 0; i != m_length; i++) {
		bool Flag = true;

		for (size_t j = 0; j < m_length - (i + 1); j++) {
			if (m_data[j] > m_data[j + 1]) 
			{
				Flag = false;
				Swap(m_data[j], m_data[j + 1]);
			}
		}
		if (Flag) 
		{
			break;
		}
	}
};

void ArreyInt::print()
{
	std::cout << " Arrey = ( " << m_length << " ) = ( ";
	for (size_t i = 0; i < m_length; i++)
	{
		std::cout << m_data[i] << " ";
	}
	std::cout << ") " << std::endl;
};


