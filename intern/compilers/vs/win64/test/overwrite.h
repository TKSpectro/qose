#pragma once

class CFile
{
	public:
		CFile();						// Standardkonstruktor
		CFile(const CFile& _rOther);	// Kopierkonstruktor
		~CFile();						// Dekonstruktor

		CFile& operator = (const CFile& _rOther); // Zuweisungsoperator

	private:
		int m_X;
		int m_Y;

	public:
		void Open();
		void Close();
};