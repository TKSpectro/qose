#include "aufgabe3_sahm.h"

CCardColor2 CCardColor2::GetDiamond()
{
	return CCardColor2("diamond");
}

CCardColor2 CCardColor2::GetHeart()
{
	return CCardColor2("heart");
}

CCardColor2 CCardColor2::GetSpade()
{
	return CCardColor2("spade");
}

CCardColor2 CCardColor2::GetCross()
{
	return CCardColor2("cross");
}

CCardType2 CCardType2::GetSeven()
{
	return CCardType2(std::string("seven"));
}

CCardType2 CCardType2::GetEight()
{
	return CCardType2("eight");
}

CCard2::CCard2( CCardColor2& _rColor, CCardType2& _rType)
	: m_Color(_rColor)
	, m_Type(_rType)
{
}
