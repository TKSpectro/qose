#include "asserttest.h"
#include <cassert>
#include <iostream>
#include <array>
#include <vector>

void AssertTest(SFoo* _pFoo)
{
	// 1. nullptr
	assert(_pFoo != nullptr);
	std::cout << "Value of _pFoo: " << _pFoo->m_Value << std::endl;

	// 2. index-out-of-bounds
	float Values[20] = {0.0f,1.0f,2.0f,3.0f,4.0f,5.0f,6.0f,7.0f,8.0f,9.0f,10.0f,11.0f,12.0f,13.0f,14.0f,15.0f,16.0f,17.0f,18.0f,19.0f};
	for(int Index = 0; Index < 20; ++ Index)
	{
		assert((Index >= 0) && (Index <= 20));

		std::cout << Values[Index] << std::endl;
	}

	// std::array hat direkt index-out-of-bounds check mit drinnen
	std::array<float, 20> ValueArray;

	// Braucht kein out-of-bounds-check
	for(float Value : Values)
	{
		std::cout << Value << std::endl;
	}


	// 3. Wertebereiche von Variablen und Ergebnissen
	{
		float _A = 1.0f;
		//float _B = 0.0f;
		float _B = 1.0f;

		assert(_B != 0.0f);
		assert(fabs(_B) > 0.0000001f);
		float Result =_A / _B;
	}
}