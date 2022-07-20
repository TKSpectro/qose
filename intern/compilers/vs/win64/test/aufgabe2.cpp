#include <cassert>
#include "aufgabe2.h"

void Aufgabe2(int _Index, int* _pResult)
{
	
	int* pData = new int[10];
	
	// Index between 0 and last Index
	assert(_Index >= 0 && _Index < 10);
	pData[_Index] = 0;
	
	// Division by zero (Index is int so no > 0.00000f needed)
	assert(_Index != 0);
	*_pResult = 10 / _Index;
	
	// *_pResult between 0 and last index
	assert(*_pResult >= 0 && *_pResult < 10);
	pData[*_pResult] = -1;
	
	delete[] pData;
}