#pragma once

class CCard
{
	private:

		enum CardType
		{
			SEVEN,
			EIGHT,
			NINE,
			TEN,
			JACK,
			QUEEN,
			KING,
			ACE
		};

		enum CardColor
		{
			DIAMOND,
			HEART,
			SPADES,
			CROSS
		};

	public:
		
		CCard();
		CCard(CardColor _color, CardType _type);

		CCard(const CCard& _rOther);	// Kopierkonstruktor

	public:
		
		static CardType Get7();
		static CardType Get8();
		static CardColor GetDiamond();
		static CardColor GetHeart();

	public:

		CardType m_CardType;
		CardColor m_CardColor;

};