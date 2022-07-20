#pragma once

class CDoubleLinkedList
{
	public:

		struct SNode
		{
			int m_Value;
			SNode* m_Previous;
			SNode* m_Next;
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
		SNode* m_FirstNode;
		SNode* m_LastNode;
};