#include "unittest/ut_test.h"
#include "pk2aufgabe5.h"
#include <iostream>

int g_Values[] = { 19, 73, 102, 1, 23, 45};

UT_TEST(IsEmptyBeforePush)
{
	CDoubleLinkedList List;
	UT_CHECK(List.IsEmpty() == true);
}

UT_TEST(GetElementCountBeforePush)
{
	CDoubleLinkedList List;
	UT_CHECK(List.GetElementCount() == 0);
}

UT_TEST(GetFrontBeforePush)
{
	CDoubleLinkedList List;
	UT_CHECK(List.GetFront() == nullptr);
}

UT_TEST(PushBack)
{
	CDoubleLinkedList List;

	UT_CHECK(List.IsEmpty() == true);
	UT_CHECK(List.GetElementCount() == 0);
	UT_CHECK(List.GetFront() == nullptr);


	for(int Index = 0; Index < std::size(g_Values); ++ Index)
	{
		List.PushBack(g_Values[Index]);

		UT_CHECK(List.IsEmpty() == false);
		// Could write GetElemntCount into a tmp variable for saving some calls to GetElementCount
		UT_CHECK(List.GetElementCount() == Index + 1);

		//std::cout << Index << std::endl;;
		
		CDoubleLinkedList::SNode* TmpNode = List.GetFront();
		for(int ListIndex = 0; ListIndex < List.GetElementCount(); ++ ListIndex)
		{
			// The current value can always be checked
			UT_CHECK(TmpNode->m_Value == g_Values[ListIndex]);

			// For checking previous and next we need to differentiate first, last and inbetween nodes
			if(ListIndex == 0)
			{
				//std::cout << "first elm" << std::endl;

				// The previous of the first should be the last element
				UT_CHECK(TmpNode->m_pPrevious->m_Value == g_Values[List.GetElementCount() - 1]);
				
				// If there is just one element the next element should be the same element
				if(List.GetElementCount() == 1)
				{
					UT_CHECK(TmpNode->m_pNext->m_Value == g_Values[ListIndex]);
				}
				else
				{
					UT_CHECK(TmpNode->m_pNext->m_Value == g_Values[ListIndex + 1]);
				}

			}
			else if(ListIndex == List.GetElementCount() - 1)
			{
				//std::cout << "last elm" << std::endl;

				UT_CHECK(TmpNode->m_pPrevious->m_Value == g_Values[ListIndex - 1]);
				// The next of the last should be the first element
				UT_CHECK(TmpNode->m_pNext->m_Value == g_Values[0]);
			}
			else
			{
				//std::cout << "elm" << std::endl;

				UT_CHECK(TmpNode->m_pPrevious->m_Value == g_Values[ListIndex - 1]);
				UT_CHECK(TmpNode->m_pNext->m_Value == g_Values[ListIndex + 1]);
			}

			// Increase the "iterator"
			TmpNode = TmpNode->m_pNext;
		}
		//std::cout << std::endl;
	}

	UT_CHECK(List.IsEmpty() == false);
	UT_CHECK(List.GetElementCount() == std::size(g_Values));
}

UT_TEST(PopBack)
{
	CDoubleLinkedList List;
	// Dont check running sizes etc. as it was tested in the PushBack test
	for(int Index = 0; Index < std::size(g_Values); ++ Index)
	{
		List.PushBack(g_Values[Index]);
	}

	UT_CHECK(List.GetElementCount() == std::size(g_Values));

	for(int Index = std::size(g_Values) - 1; Index >= 0; -- Index)
	{
		List.PopBack();

		UT_CHECK(List.GetElementCount() == Index);
		if(Index > 0)
		{
			UT_CHECK(List.IsEmpty() == false);
			// Check if the first elms previous is having the value of the new last element (Index - 1)
			UT_CHECK(List.GetFront()->m_pPrevious->m_Value == g_Values[Index - 1]);
		}
	}

	// List should be completely cleared out
	UT_CHECK(List.IsEmpty() == true);
	UT_CHECK(List.GetElementCount() == 0);
	UT_CHECK(List.GetFront() == nullptr);
}