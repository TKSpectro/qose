#pragma once

struct SPerson
{
	SPerson(char* _pFirstname, char* _pLastname, int _Age)
		: m_pFirstname(_pFirstname)
		, m_pLastname(_pLastname)
		, m_Age(_Age)
	{
	}

	char* m_pFirstname;
	char* m_pLastname;
	int m_Age;
};

class CArray
{
	public:
		
		CArray();
		~CArray();

	public:

		bool IsEmpty();
		int	 Size();
		void PushFront(SPerson& _rPerson);
		void PushBack(SPerson& _rPerson);
		SPerson* At(int _Index);

		SPerson* operator [](int _Index);

	private:

		static const int m_MaxNumberOfEntries = 4;

	private:
		
		int m_NumberOfEntries;
		SPerson* m_ppEntries[m_MaxNumberOfEntries];
};