#include "unittest/ut_test.h"
#include "array.h"

UT_TEST(ArrayPushFront)
{
	CArray Array = CArray();
	
	UT_CHECK(Array.Size() == 0);
	UT_CHECK(Array.IsEmpty() == true);

	SPerson* pPerson = new SPerson("Tom", "Kaeppler", 22);
	SPerson* pPerson2 = new SPerson("Jon", "Doe", 54);
	SPerson* pPerson3 = new SPerson("Jane", "Doe", 22);
	SPerson* pPerson4 = new SPerson("Test", "Test", 22);

	Array.PushFront(*pPerson);

	UT_CHECK(Array.Size() == 1);
	UT_CHECK(Array.IsEmpty() == false);

	Array.PushFront(*pPerson2);

	UT_CHECK(Array.Size() == 2);
	UT_CHECK(Array.IsEmpty() == false);

	Array.PushFront(*pPerson3);

	UT_CHECK(Array.Size() == 3);
	UT_CHECK(Array.IsEmpty() == false);

	Array.PushFront(*pPerson4);

	UT_CHECK(Array.Size() == 4);
	UT_CHECK(Array.IsEmpty() == false);
}


UT_TEST(ArrayAt)
{
	CArray Array = CArray();

	SPerson* pPerson = new SPerson("Tom", "Kaeppler", 22);
	SPerson* pPerson2 = new SPerson("Jon", "Doe", 54);
	SPerson* pPerson3 = new SPerson("Jane", "Doe", 33);
	SPerson* pPerson4 = new SPerson("Test", "Test", 44);

	Array.PushFront(*pPerson);
	Array.PushFront(*pPerson2);
	Array.PushFront(*pPerson3);
	Array.PushFront(*pPerson4);

	UT_CHECK(strcmp(Array.At(3)->m_pFirstname, "Tom") == 0);
	UT_CHECK(strcmp(Array.At(3)->m_pLastname, "Kaeppler") == 0);
	UT_CHECK(Array.At(3)->m_Age == 22);

	UT_CHECK(strcmp(Array.At(2)->m_pFirstname, "Jon") == 0);
	UT_CHECK(strcmp(Array.At(2)->m_pLastname, "Doe") == 0);
	UT_CHECK(Array.At(2)->m_Age == 54);

	UT_CHECK(strcmp(Array.At(1)->m_pFirstname, "Jane") == 0);
	UT_CHECK(strcmp(Array.At(1)->m_pLastname, "Doe") == 0);
	UT_CHECK(Array.At(1)->m_Age == 33);

	UT_CHECK(strcmp(Array.At(0)->m_pFirstname, "Test") == 0);
	UT_CHECK(strcmp(Array.At(0)->m_pLastname, "Test") == 0);
	UT_CHECK(Array.At(0)->m_Age == 44);
}

UT_TEST(ArrayAtOperator)
{
	CArray Array = CArray();

	SPerson* pPerson = new SPerson("Tom", "Kaeppler", 22);
	SPerson* pPerson2 = new SPerson("Jon", "Doe", 54);
	SPerson* pPerson3 = new SPerson("Jane", "Doe", 33);
	SPerson* pPerson4 = new SPerson("Test", "Test", 44);

	Array.PushFront(*pPerson);
	Array.PushFront(*pPerson2);
	Array.PushFront(*pPerson3);
	Array.PushFront(*pPerson4);

	UT_CHECK(strcmp(Array[3]->m_pFirstname, "Tom") == 0);
	UT_CHECK(strcmp(Array[3]->m_pLastname, "Kaeppler") == 0);
	UT_CHECK(Array[3]->m_Age == 22);

	UT_CHECK(strcmp(Array[2]->m_pFirstname, "Jon") == 0);
	UT_CHECK(strcmp(Array[2]->m_pLastname, "Doe") == 0);
	UT_CHECK(Array[2]->m_Age == 54);

	UT_CHECK(strcmp(Array[1]->m_pFirstname, "Jane") == 0);
	UT_CHECK(strcmp(Array[1]->m_pLastname, "Doe") == 0);
	UT_CHECK(Array[1]->m_Age == 33);

	UT_CHECK(strcmp(Array[0]->m_pFirstname, "Test") == 0);
	UT_CHECK(strcmp(Array[0]->m_pLastname, "Test") == 0);
	UT_CHECK(Array[0]->m_Age == 44);
}

UT_TEST(ArrayPushBack)
{
	CArray Array = CArray();

	UT_CHECK(Array.Size() == 0);
	UT_CHECK(Array.IsEmpty() == true);

	SPerson* pPerson = new SPerson("Tom", "Kaeppler", 22);
	SPerson* pPerson2 = new SPerson("Jon", "Doe", 54);
	SPerson* pPerson3 = new SPerson("Jane", "Doe", 33);
	SPerson* pPerson4 = new SPerson("Test", "Test", 44);

	// This should be clearly done in a for, but im lazy
	Array.PushBack(*pPerson);

	UT_CHECK(Array.Size() == 1);
	UT_CHECK(Array.IsEmpty() == false);

	UT_CHECK(strcmp(Array[0]->m_pFirstname, "Tom") == 0);
	UT_CHECK(strcmp(Array[0]->m_pLastname, "Kaeppler") == 0);
	UT_CHECK(Array[0]->m_Age == 22);

	Array.PushBack(*pPerson2);

	UT_CHECK(Array.Size() == 2);
	UT_CHECK(Array.IsEmpty() == false);

	UT_CHECK(strcmp(Array[0]->m_pFirstname, "Tom") == 0);
	UT_CHECK(strcmp(Array[0]->m_pLastname, "Kaeppler") == 0);
	UT_CHECK(Array[0]->m_Age == 22);

	UT_CHECK(strcmp(Array[1]->m_pFirstname, "Jon") == 0);
	UT_CHECK(strcmp(Array[1]->m_pLastname, "Doe") == 0);
	UT_CHECK(Array[1]->m_Age == 54);

	Array.PushBack(*pPerson3);

	UT_CHECK(Array.Size() == 3);
	UT_CHECK(Array.IsEmpty() == false);

	UT_CHECK(strcmp(Array[0]->m_pFirstname, "Tom") == 0);
	UT_CHECK(strcmp(Array[0]->m_pLastname, "Kaeppler") == 0);
	UT_CHECK(Array[0]->m_Age == 22);

	UT_CHECK(strcmp(Array[1]->m_pFirstname, "Jon") == 0);
	UT_CHECK(strcmp(Array[1]->m_pLastname, "Doe") == 0);
	UT_CHECK(Array[1]->m_Age == 54);

	UT_CHECK(strcmp(Array[2]->m_pFirstname, "Jane") == 0);
	UT_CHECK(strcmp(Array[2]->m_pLastname, "Doe") == 0);
	UT_CHECK(Array[2]->m_Age == 33);

	Array.PushBack(*pPerson4);

	UT_CHECK(Array.Size() == 4);
	UT_CHECK(Array.IsEmpty() == false);

	UT_CHECK(strcmp(Array[0]->m_pFirstname, "Tom") == 0);
	UT_CHECK(strcmp(Array[0]->m_pLastname, "Kaeppler") == 0);
	UT_CHECK(Array[0]->m_Age == 22);

	UT_CHECK(strcmp(Array[1]->m_pFirstname, "Jon") == 0);
	UT_CHECK(strcmp(Array[1]->m_pLastname, "Doe") == 0);
	UT_CHECK(Array[1]->m_Age == 54);

	UT_CHECK(strcmp(Array[2]->m_pFirstname, "Jane") == 0);
	UT_CHECK(strcmp(Array[2]->m_pLastname, "Doe") == 0);
	UT_CHECK(Array[2]->m_Age == 33);

	UT_CHECK(strcmp(Array[3]->m_pFirstname, "Test") == 0);
	UT_CHECK(strcmp(Array[3]->m_pLastname, "Test") == 0);
	UT_CHECK(Array[3]->m_Age == 44);
}