#pragma once

class CPerson
{
	public:

		CPerson& operator = (const CPerson& _rOther);

	public:
		
		void SetFirstName(char* _pFirstName);
		char* GetFirstName() const;

		void SetLastName(char* _pLastName);
		char* GetLastName() const;

	private:

		char* m_pFirstName = nullptr;
		char* m_pLastName = nullptr;

};