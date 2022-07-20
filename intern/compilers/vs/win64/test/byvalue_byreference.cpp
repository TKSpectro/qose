#include <cassert>

class CCar
{
	CCar()
		: m_Weight(0.0f)
		, m_Power(0.0f)
		, m_Length(0.0f){ }

	public:
		float m_Weight;
		float m_Power;
		float m_Length;
};

// Call-by-value -> Wird komplett kopiert -> sehr schlecht -> bei Komplexen Typen in Komplexen Typ ist RIP
void RepairV(CCar _Car)
{
	float test = _Car.m_Length;
}

// Call-by-reference -> Pointer wird kopiert -> Kann aber nullptr sein, wäre schlecht -> Adresse wird von Aufrufendem erzeugt
void RepairP(CCar* _pCar)
{
	assert(_pCar != nullptr);

	float test = _pCar->m_Length;
}

// Call-by-reference -> Pointer wird kopiert -> KEIN nullptr moeglich -> Adresse wird von Methode selber erzeugt
void RepairR(CCar& _rCar)
{
	float test = _rCar.m_Length;
}



int ByValue()
{
	//CCar Car = Car();

	//RepairV(Car);

	//RepairP(nullptr);
	//RepairP(&Car);

	//RepairR(Car); 

	return 0;
}