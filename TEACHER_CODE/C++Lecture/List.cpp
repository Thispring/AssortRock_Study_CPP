#include "List.h"

#include <assert.h>



List::List()
	: m_Head(nullptr)
	, m_Tail(nullptr)
	, m_Size(0)
{
}

List::~List()
{
	Node* pNode = m_Head;

	while (pNode != nullptr)
	{
		Node* pNext = pNode->Next;
		delete pNode;
		pNode = pNext;
	}
}

void List::push_back(const int& _Data)
{
	// 데이터를 저장시킬 노드를 동적할당 한다. 데이터를 채운다
	Node* pNewNode = new Node(_Data);

	if (0 == m_Size)
	{
		m_Head = pNewNode;
		m_Tail = pNewNode;
	}

	else
	{
		m_Tail->Next = pNewNode;
		pNewNode->Prev = m_Tail;
		m_Tail = pNewNode;
	}

	++m_Size;
}

void List::push_front(const int& _Data)
{
	Node* pNewNode = new Node(_Data);

	if (m_Size == 0)
	{
		m_Head = m_Tail = pNewNode;
	}
	else
	{
		pNewNode->Next = m_Head;		
		m_Head->Prev = pNewNode;
		m_Head = pNewNode;
	}
	
	++m_Size;
}

void List::pop_back()
{
	assert(0 != m_Size);	

	if (1 == m_Size)
	{
		delete m_Head;
		m_Head = m_Tail = nullptr;
	}

	else
	{
		// 리스트가 현재 마지막 노드의 이전노드를, Tail 로 가리키게 한다.
		m_Tail = m_Tail->Prev;

		// 마지막 노드를 삭제한다.
		delete m_Tail->Next;

		// 마지막 이전노드가, 삭제될 곳을 가리키지 않게 한다.
		m_Tail->Next = nullptr;
	}

	--m_Size;
}

void List::pop_front()
{
	assert(0 != m_Size);

	if (1 == m_Size)
	{
		delete m_Head;
		m_Head = m_Tail = nullptr;
	}
	
	else
	{
		// 두번째 노드를 새로운 Head 노드로 지정
		m_Head = m_Head->Next;

		// 맨 앞에 노드를 삭제하고
		delete m_Head->Prev;

		// 새로 Head 로 지정된 노드(원래 2번째 였던 노드)의 이전 주소를 nullptr 막는다.
		m_Head->Prev = nullptr;
	}

	--m_Size;
}

void List::reverse()
{
	reverse_recursive(m_Head);
}

void List::reverse_recursive(Node* _Node)
{	
	if (nullptr == _Node)
	{
		// List 가 head 노드랑 Tail 노드를 반대로 가리키게 한다.
		Node* pTemp = m_Head;
		m_Head = m_Tail;
		m_Tail = pTemp;	
	}
	else
	{
		reverse_recursive(_Node->Next);

		Node* pTemp = _Node->Next;		
		_Node->Next = _Node->Prev;
		_Node->Prev = pTemp;
	}
}