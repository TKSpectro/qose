#include "pk2aufgabe5.h"

CDoubleLinkedList::CDoubleLinkedList()
	: m_ElementCount(0)
	, m_FirstNode(nullptr)
	, m_LastNode(nullptr)
{
}

void CDoubleLinkedList::PushBack(int _Value)
{
	SNode* NewNode = new SNode();
	NewNode->m_Value = _Value;
	NewNode->m_Next = m_FirstNode;
	NewNode->m_Previous = m_LastNode;

	if(m_FirstNode == nullptr)
	{
		m_FirstNode = NewNode;
	}
	if(m_LastNode == nullptr)
	{
		m_LastNode = NewNode;
	}

	m_LastNode->m_Next = NewNode;
	m_LastNode = NewNode;

	m_FirstNode->m_Previous = NewNode;

	++m_ElementCount;
}

void CDoubleLinkedList::PopBack()
{
	if(m_FirstNode == m_LastNode)
	{
		delete m_LastNode;

		m_ElementCount = 0;
		m_FirstNode = nullptr;
		m_LastNode = nullptr;
	}
	else
	{
		SNode* TmpLastNode = m_LastNode;
		// Set the last node the m_Previous of the currently last one
		m_LastNode = m_LastNode->m_Previous;
		// Set the m_Next of the new last to the firstNode to keep the loop running
		m_LastNode->m_Next = m_FirstNode;

		// Set the previous of the FirstNode to the new lastNode
		m_FirstNode->m_Previous = m_LastNode;

		delete TmpLastNode;
		--m_ElementCount;
	}
}

CDoubleLinkedList::SNode* CDoubleLinkedList::GetFront()
{
	return m_FirstNode;
}

bool CDoubleLinkedList::IsEmpty()
{
	// Could also check if both SNode* are nullptr, but if all functions
	// where implemented correctly this should suffice
	if(m_ElementCount == 0)
	{
		return true;
	}

	return false;
}

int CDoubleLinkedList::GetElementCount()
{
	return m_ElementCount;
}
