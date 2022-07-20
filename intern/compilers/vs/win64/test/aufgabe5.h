#pragma once

class CPerson
{
	public:

		CPerson();

	public:

		void SetFirstname(char* _pFirstname);
		void SetLastname(char* _pLastname);
		void SetAge(int _Age);

		char* GetFirstname();
		char* GetLastname();
		int GetAge();

	private:

		char* m_pFirstname;
		char* m_pLastname;
		int m_Age;

};