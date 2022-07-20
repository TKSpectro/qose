#include "person.h"
#include <string.h>
#include <cassert>

CPerson& CPerson::operator=(const CPerson& _rOther)
{
	// Einfacher Ansatz ohne Exception Safety -> 
	// m_pFirstName = _rOther.m_pFirstName;
	// m_pLastName = _rOther.m_pLastName;

	// Schonmal besser aber keine Zustandskonsistenz weil eins koennte klappen aber nicht das andere
	// SetFirstName(_rOther.m_pFirstName);
	// SetLastName(_rOther.m_pLastName);

	assert(_rOther.m_pFirstName != nullptr);
	assert(_rOther.m_pLastName != nullptr);

	char* pFirstName = nullptr;
	char* pLastName = nullptr;

	// Da im zweiten Teil was schief gehen kann muessen wir das catchen und den pLastName speicher wieder aufraeumen
	try
	{
		// Wieder alles erstmal lokal machen
		size_t NumberOfCharsFirst = strlen(_rOther.m_pFirstName) + 1;
		pFirstName = new char[NumberOfCharsFirst];
		strcpy_s(pFirstName, NumberOfCharsFirst, _rOther.m_pFirstName);

		size_t NumberOfCharsLast = strlen(_rOther.m_pLastName) + 1;
		pLastName = new char[NumberOfCharsLast];
		strcpy_s(pLastName, NumberOfCharsLast, _rOther.m_pLastName);

		// Alles hat geklappt. Jetzt sind wir safe und koennen aufraeument und den Pointer setzen
		delete[] m_pFirstName;
		delete[] m_pLastName;

		m_pFirstName = pFirstName;
		m_pLastName = pLastName;
	}
	catch(...)
	{
		delete[] pFirstName;
		delete[] pLastName;

		// Exception die geschmissen wurde weiter throwen
		throw;
	}

	return *this;
}

// Strong Exception Safety
void CPerson::SetFirstName(char* _pFirstName)
{
	// Einfacher Weg ohne Exception Safety
	//m_pFirstName = _pFirstName;

	// 1. m_pFirstName zeigt auf einen alten Namen und der Pointer wird überschrieben
	//	  -> Pointer auf alten Namen geht verloren -> Memory Leak
	// 2. m_pFirstName zeigt auf aktuellen Namen
	//    -> Anderer Softwareteil loescht den aktuellen Namen
	//    -> Pointer wird ungueltig (Invalid pointer) -> Ownership Problem

	assert(_pFirstName != nullptr);

	// Fuer nur 1. , delete loescht nur Speicherbereich nicht aber den Pointer darauf deshalb = nullptr machen
	// delete m_pFirstName;
	// m_pFirstName = nullptr;

	// + 1 weil bei nativen c strings am ende ein nullterminator ist \0
	size_t NumberOfChars = strlen(_pFirstName) + 1;
	// Besser alles erstmal mit lokalen Variablen und dann swap
	char* pFirstName = new char[NumberOfChars];
	strcpy_s(pFirstName, NumberOfChars, _pFirstName);
	
	// Wieder alten Speicherbereich aufraeumen
	delete[] m_pFirstName;

	m_pFirstName = pFirstName;
}

char* CPerson::GetFirstName() const
{
	return m_pFirstName;
}

void CPerson::SetLastName(char* _pLastName)
{
	assert(_pLastName != nullptr);

	size_t NumberOfChars = strlen(_pLastName) + 1;

	char* pLastName = new char[NumberOfChars];
	strcpy_s(pLastName, NumberOfChars, _pLastName);

	delete[] m_pLastName;

	m_pLastName = pLastName;
}

char* CPerson::GetLastName() const
{
	return m_pLastName;
}
