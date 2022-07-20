#pragma once
#include <string>

class CCardColor2
{
	public:

	static CCardColor2 GetDiamond();
	static CCardColor2 GetHeart();
	static CCardColor2 GetSpade();
	static CCardColor2 GetCross();

	private:

	std::string m_Color;

	private:

	explicit CCardColor2(std::string _Color) : m_Color(_Color)
	{
	}

	private:

	CCardColor2& operator = (const CCardColor2&) = delete;
};

class CCardType2
{
	public:
		
		static CCardType2 GetSeven();
		static CCardType2 GetEight();
		static CCardType2 GetNine();
		static CCardType2 GetTen();
		static CCardType2 GetJack();
		static CCardType2 GetQueen();
		static CCardType2 GetKing();
		static CCardType2 GetAce();

	private:

		std::string m_Type;
	
	private:
		
		explicit CCardType2(std::string _Type) : m_Type(_Type) { }

	private:

		CCardType2& operator = (const CCardType2&) = delete;
};

class CCard2
{
	public:
		
		CCard2( CCardColor2& _rColor,  CCardType2& _rType);

	public:
		
		 CCardColor2& m_Color;
		 CCardType2& m_Type;
};