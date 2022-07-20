#pragma once

#include <assert.h>

bool g_Buffer[10];

void Swap(int* _pA, int* _pB)
{
	assert(_pA != nullptr);
	int Tmp = *_pA;

	assert(_pB != nullptr);
	* _pA = *_pB;

	* _pB = Tmp;

	int SizeOfArray = sizeof(g_Buffer) / sizeof(g_Buffer[0]);
	assert(Tmp > 0 && Tmp < SizeOfArray);
	g_Buffer[Tmp] = true;
}