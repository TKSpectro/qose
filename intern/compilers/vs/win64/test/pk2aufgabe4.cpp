#include "pk2aufgabe4.h"
#include <string.h>
#include <cassert>

SAdress& SAdress::operator=(const SAdress& _rOther)
{
	assert(_rOther.mCity != nullptr);
	assert(_rOther.mStreet != nullptr);

	char* LocalCity = nullptr;
	char* LocalStreet = nullptr;

	try
	{
		// Add +1 because of \0 at the end of c string
		size_t NumberOfCharsCity = strlen(_rOther.mCity) + 1;
		char* LocalCity = new char[NumberOfCharsCity];
		strcpy_s(LocalCity, NumberOfCharsCity, _rOther.mCity);

		// Add +1 because of \0 at the end of c string
		size_t NumberOfCharsStreet = strlen(_rOther.mStreet) + 1;
		char* LocalStreet = new char[NumberOfCharsStreet];
		strcpy_s(LocalStreet, NumberOfCharsStreet, _rOther.mStreet);

		// All the pointers and values can be copied so we can proceed
		// Cleanup old Strings
		delete[] mCity;
		delete[] mStreet;

		// Set the new pointer
		mCity = LocalCity;
		mStreet = LocalStreet;
	}
	catch(...)
	{
		delete[] LocalCity;
		delete[] LocalStreet;

		throw;
	}
	
	return *this;
}
