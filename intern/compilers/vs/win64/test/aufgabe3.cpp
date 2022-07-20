#include "aufgabe3.h"

CCard::CCard()
{
}

CCard::CCard(CardColor _color, CardType _type)
	: m_CardColor(_color)
	, m_CardType(_type)
{
}

CCard::CCard(const CCard& _rOther)
	: m_CardColor(_rOther.m_CardColor)
	, m_CardType(_rOther.m_CardType)
{
}

CCard::CardType CCard::Get7()
{
	return SEVEN;
}

CCard::CardType CCard::Get8()
{
	return EIGHT;
}

CCard::CardColor CCard::GetDiamond()
{
	return DIAMOND;
}

CCard::CardColor CCard::GetHeart()
{
	return HEART;
}
