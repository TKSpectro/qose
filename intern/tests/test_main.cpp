
#include "unittest/ut_suite.h"

#include <iostream>
#include "../compilers/vs/win64/test/overwrite.h"
#include "../compilers/vs/win64/test/asserttest.h"
//#include "../compilers/vs/win64/test/person.h"

#include "../compilers/vs/win64/test/aufgabe2.h"
#include "../compilers/vs/win64/test/aufgabe3.h"
#include "../compilers/vs/win64/test/aufgabe4.h"

#include "../compilers/vs/win64/test/pk2aufgabe2.h"
#include "../compilers/vs/win64/test/pk2aufgabe4.h"
#include "../compilers/vs/win64/test/pk2aufgabe5.h"

void overwrite();
void assertTest();
void person();
void pk1();
void pk2();

void main()
{
	std::cout << "---- TESTS ----" << std::endl;
	UT::Suite::Reset(&std::cout);
	UT::Suite::RunTests();
	std::cout << "---- TESTS ----" << std::endl;

	std::cout << "overwrite" << std::endl;
	overwrite();
	std::cout << "assertTest" << std::endl;
	assertTest();
	//std::cout << "person" << std::endl;
	//person();

	std::cout << "probeklausur 1" << std::endl;
	pk1();
	std::cout << "probeklausur 2" << std::endl;
	pk2();
}

void overwrite()
{
	{
		CFile File = CFile();
		
		File.Open();

		// throw Exception
	}
	// File would be closed as its called in the deconstructor
}

void assertTest()
{
	SFoo foo = SFoo();
	foo.m_Value = 1.0f;

	AssertTest(&foo);
	//AssertTest(nullptr);
}

//void person()
//{
//	CPerson* pPerson = new CPerson();
//
//	char* pFirstName = new char[strlen("hello") + 1];
//	strcpy_s(pFirstName, strlen("hello") + 1, "hello");
//
//	char* pLastName = new char[strlen("world") + 1];
//	strcpy_s(pLastName, strlen("world") + 1, "world");
//
//	pPerson->SetFirstName(pFirstName);
//	pPerson->SetLastName(pLastName);
//
//	std::cout << "1 FirstName: " << pPerson->GetFirstName() << std::endl;
//	std::cout << "1 LastName " << pPerson->GetLastName() << std::endl;
//	
//	CPerson* pPerson2 = new CPerson();
//	pPerson2 = pPerson;
//
//	std::cout << "2 FirstName: " << pPerson2->GetFirstName() << std::endl;
//	std::cout << "2 LastName " << pPerson2->GetLastName() << std::endl;
//}

void pk1()
{
	int* pResult = new int;

	// Not allowed
	//Aufgabe2(0, pResult);
	//Aufgabe2(1, pResult);
	//Aufgabe2(10, pResult);
	//Aufgabe2(>10, pResult);

	Aufgabe2(9, pResult);
	delete pResult;

	CCard Card = CCard(CCard::GetDiamond(), CCard::Get7());
	Card.m_CardColor;

	CCard Card2 = Card;
	Card2.m_CardColor;


	CRectangle rect;

	rect.m_PointA = Point2D(0, 0);
	rect.m_PointB = Point2D(4, 0);
	rect.m_PointC = Point2D(4, 4);
	rect.m_PointD = Point2D(0, 4);

	float area = rect.GetArea();
	area;

	// Run tests for task 5
	//UT::Suite::Reset(&std::cout);
	//UT::Suite::RunTests();
}

void pk2()
{
	int* pA = new int;
	*pA = 1;
	int* pB = new int;
	*pB = 2;

	Swap(pA, pB);

	// Run tests for task 5
	//UT::Suite::Reset(&std::cout);
	//UT::Suite::RunTests();
}