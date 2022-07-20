#include "pk2aufgabe4.h"
#include <string.h>
#include <cassert>

SAdress& SAdress::operator=(const SAdress& _rOther)
{
	assert(_rOther.m_City != nullptr);
	assert(_rOther.m_Street != nullptr);

	char* LocalCity = nullptr;
	char* LocalStreet = nullptr;

	try
	{
		// Add +1 because of \0 at the end of c string
		size_t NumberOfCharsCity = strlen(_rOther.m_City) + 1;
		char* LocalCity = new char[NumberOfCharsCity];
		strcpy_s(LocalCity, NumberOfCharsCity, _rOther.m_City);

		// Add +1 because of \0 at the end of c string
		size_t NumberOfCharsStreet = strlen(_rOther.m_Street) + 1;
		char* LocalStreet = new char[NumberOfCharsStreet];
		strcpy_s(LocalStreet, NumberOfCharsStreet, _rOther.m_Street);

		// All the pointers and values can be copied so we can proceed
		// Cleanup old Strings
		delete[] m_City;
		delete[] m_Street;

		// Set the new pointer
		m_City = LocalCity;
		m_Street = LocalStreet;
	}
	catch(...)
	{
		delete[] LocalCity;
		delete[] LocalStreet;

		throw;
	}
	
	return *this;
}
