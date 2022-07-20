#include "pk2aufgabe5.h"

CDoubleLinkedList::CDoubleLinkedList()
	: m_ElementCount(0)
	, m_pFirstNode(nullptr)
	, m_pLastNode(nullptr)
{
}

void CDoubleLinkedList::PushBack(int _Value)
{
	SNode* NewNode = new SNode();
	NewNode->m_Value = _Value;
	NewNode->m_pNext = m_pFirstNode;
	NewNode->m_pPrevious = m_pLastNode;

	if(m_pFirstNode == nullptr)
	{
		m_pFirstNode = NewNode;
	}
	if(m_pLastNode == nullptr)
	{
		m_pLastNode = NewNode;
	}

	m_pLastNode->m_pNext = NewNode;
	m_pLastNode = NewNode;

	m_pFirstNode->m_pPrevious = NewNode;

	++m_ElementCount;
}

void CDoubleLinkedList::PopBack()
{
	if(m_pFirstNode == m_pLastNode)
	{
		delete m_pLastNode;

		m_ElementCount = 0;
		m_pFirstNode = nullptr;
		m_pLastNode = nullptr;
	}
	else
	{
		SNode* TmpLastNode = m_pLastNode;
		// Set the last node the m_pPrevious of the currently last one
		m_pLastNode = m_pLastNode->m_pPrevious;
		// Set the m_pNext of the new last to the firstNode to keep the loop running
		m_pLastNode->m_pNext = m_pFirstNode;

		// Set the previous of the FirstNode to the new lastNode
		m_pFirstNode->m_pPrevious = m_pLastNode;

		delete TmpLastNode;
		--m_ElementCount;
	}
}

CDoubleLinkedList::SNode* CDoubleLinkedList::GetFront()
{
	return m_pFirstNode;
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
