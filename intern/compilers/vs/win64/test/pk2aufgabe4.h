#pragma once

struct SAdress
{
	SAdress& operator = (const SAdress& _rOther);

	char* m_Street;
	char* m_City;
	int	  m_Housenumber;
	int   m_Postcode;
};