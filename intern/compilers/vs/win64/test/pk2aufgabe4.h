#pragma once

struct SAdress
{
	SAdress& operator = (const SAdress& _rOther);

	char* mStreet;
	char* mCity;
	int	  mHousenumber;
	int   mPostcode;
};