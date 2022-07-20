#pragma once

#include "overwrite.h"
#include <iostream>

CFile::CFile()
	: m_X(0)
	, m_Y(0)
{
}

CFile::CFile(const CFile& _rOther)
	: m_X(_rOther.m_X)
	, m_Y(_rOther.m_Y)
{
}

CFile::~CFile()
{
	std::cout << "File deconstructor called" << std::endl;
	Close();
}

CFile& CFile::operator=(const CFile& _rOther)
{
	m_X = _rOther.m_X;
	m_Y = _rOther.m_Y;

	// Zuweisungsoperator sollte immer *this zurueckgeben
	return *this;
}

void CFile::Open()
{
	std::cout << "File opened" << std::endl;
}

void CFile::Close()
{
	std::cout << "File closed" << std::endl;
}
