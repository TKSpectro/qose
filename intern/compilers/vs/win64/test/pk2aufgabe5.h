#pragma once

class CDoubleLinkedList
{
	public:

		struct SNode
		{
			int m_Value;
			SNode* m_pPrevious;
			SNode* m_pNext;
		};

	public:

		CDoubleLinkedList();

		void PushBack(int _Value);
		void PopBack();
		SNode* GetFront();
		bool IsEmpty();
		int GetElementCount();

	private:

		int m_ElementCount;
		SNode* m_pFirstNode;
		SNode* m_pLastNode;
};