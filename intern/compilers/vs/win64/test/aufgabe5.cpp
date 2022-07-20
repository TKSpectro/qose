#include "aufgabe5.h"
#include <cassert>
#include <string.h>

CPerson::CPerson()
	: m_Age(-1)
	, m_pFirstname(nullptr)
	, m_pLastname(nullptr)
{
}

void CPerson::SetFirstname(char* _pFirstname)
{
	assert(_pFirstname != nullptr);

	// Add + 1 for the \0 at the end of c strings
	size_t NumberOfChars = strlen(_pFirstname) + 1;
	char* LocalFirstname = new char[NumberOfChars];
	strcpy_s(LocalFirstname, NumberOfChars, _pFirstname);

	// Cleanup the parameter string
	delete[] _pFirstname;

	// Write the pointer which we control to the member
	m_pFirstname = LocalFirstname;
}

void CPerson::SetLastname(char* _pLastname)
{
	assert(_pLastname != nullptr);

	// Add + 1 for the \0 at the end of c strings
	size_t NumberOfChars = strlen(_pLastname) + 1;
	char* LocalLastname = new char[NumberOfChars];
	strcpy_s(LocalLastname, NumberOfChars, _pLastname);

	// Cleanup the parameter string
	delete[] _pLastname;

	// Write the pointer which we control to the member
	m_pLastname = LocalLastname;
}

// -----------------------------------------------
// Can pass value directly as its a primitive type
// -----------------------------------------------
void CPerson::SetAge(int _Age)
{
	// The max age could technically be wrong in the future
	assert(_Age >= 0 && _Age < 200);

	m_Age = _Age;
}

char* CPerson::GetFirstname()
{
	return m_pFirstname;
}

char* CPerson::GetLastname()
{
	return m_pLastname;
}

int CPerson::GetAge()
{
	return m_Age;
}
