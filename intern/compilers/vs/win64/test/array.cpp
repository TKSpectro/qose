#include "array.h"
#include <cassert>

CArray::CArray()
	: m_NumberOfEntries(0)
{
	for(int Index = 0; Index < m_MaxNumberOfEntries; ++ Index)
	{
		m_ppEntries[Index] = nullptr;
	}
}

CArray::~CArray()
{
	for(int Index = 0; Index < m_MaxNumberOfEntries; ++ Index)
	{
		delete m_ppEntries[Index];
	}
}

bool CArray::IsEmpty()
{
	return m_NumberOfEntries == 0;
}

int CArray::Size()
{
	return m_NumberOfEntries;
}

void CArray::PushFront(SPerson& _rPerson)
{
	// Cant push if the array is already full
	assert(m_NumberOfEntries < m_MaxNumberOfEntries);

	SPerson* pCurrentPerson = &_rPerson;
	for(int Index = 0; Index <= m_NumberOfEntries; ++ Index)
	{
		SPerson* pNextPerson = m_ppEntries[Index];
		m_ppEntries[Index] = pCurrentPerson;
		pCurrentPerson = pNextPerson;
	}

	++ m_NumberOfEntries;
}

// This could also mean that we push out the first element
void CArray::PushBack(SPerson& _rPerson)
{
	// Cant push if the array is already full
	assert(m_NumberOfEntries < m_MaxNumberOfEntries);

	m_ppEntries[m_NumberOfEntries] = &_rPerson;

	++m_NumberOfEntries;
}

SPerson* CArray::At(int _Index)
{
	assert(_Index >= 0 && _Index < m_MaxNumberOfEntries);

	return m_ppEntries[_Index];
}

SPerson* CArray::operator[](int _Index)
{
	assert(_Index >= 0 && _Index < m_MaxNumberOfEntries);

	return m_ppEntries[_Index];
}
