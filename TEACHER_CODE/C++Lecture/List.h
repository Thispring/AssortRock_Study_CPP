#pragma once

#include <assert.h>

template<typename T>
struct Node
{
	T		Data;
	Node*	Next;
	Node*	Prev;

	Node()
		: Data()
		, Next(nullptr)
		, Prev(nullptr)
	{}

	Node(const int& _Data)
		: Data(_Data)
		, Next(nullptr)
		, Prev(nullptr)
	{}
};

template<typename T>
class List
{
private:
	Node<T>*	m_Head;
	Node<T>*	m_Tail;
	int			m_Size;

public:
	void push_back(const T& _Data);

	// 데이터를 맨 앞에 추가
	void push_front(const T& _Data);

	// 맨 뒤 데이터 제거
	void pop_back();

	// 맨 앞 데이터 제거
	void pop_front();

	void reverse();

	class iterator;

	iterator begin() { return iterator(this, m_Head); }
	iterator end() { return iterator(this, nullptr); }
	//iterator erase(const iterator& _iter);
	//void insert(const iterator& _iter, const T& _Data);
	//void insert(const iterator& _Where, const iterator& _Begin, const iterator& _End);
	//<T>& operator =(const List<T>& _Other);

private:
	void reverse_recursive(Node<T>* _Node);

public:
	List();
	//List(const List<T>& _Other);
	~List();

public:
	class iterator
	{
	private:
		List<T>*	m_Owner;
		Node<T>*	m_Node;  // m_Owner 가 nullptr 가 아니고 m_Node 는 nullptr 인 경우 end iterator 이다.

	public:
		bool operator == (const iterator& _Other) { return m_Owner == _Other.m_Owner && m_Node == _Other.m_Node; }
		bool operator != (const iterator& _Other) { return !((*this) == _Other); }

		T& operator*()
		{
			assert(m_Owner);
			return m_Node->Data;
		}

		iterator& operator ++()
		{
			assert(m_Owner);
			assert(m_Node); // end iterator 인데, ++ 을 호출한 경우

			m_Node = m_Node->Next;

			return *this;
		}

		iterator operator++(int)
		{
			iterator Copy(*this);
			++(*this);
			return Copy;
		}

		iterator& operator --()
		{

			return *this;
		}

		iterator operator--(int)
		{
			iterator Copy(*this);
			--(*this);
			return Copy;
		}

	public:
		iterator()
			: m_Owner(nullptr)
			, m_Node(nullptr)
		{}

		iterator(List<T>* _Owner, Node<T>* _Node)
			: m_Owner(_Owner)
			, m_Node(_Node)
		{}
	};
};

template<typename T>
List<T>::List()
	: m_Head(nullptr)
	, m_Tail(nullptr)
	, m_Size(0)
{
}

template<typename T>
List<T>::~List()
{
	Node<T>* pNode = m_Head;

	while (pNode != nullptr)
	{
		Node<T>* pNext = pNode->Next;
		delete pNode;
		pNode = pNext;
	}
}

template<typename T>
void List<T>::push_back(const T& _Data)
{
	// 데이터를 저장시킬 노드를 동적할당 한다. 데이터를 채운다
	Node<T>* pNewNode = new Node<T>(_Data);

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

template<typename T>
void List<T>::push_front(const T& _Data)
{
	Node<T>* pNewNode = new Node<T>(_Data);

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

template<typename T>
void List<T>::pop_back()
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

template<typename T>
void List<T>::pop_front()
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

template<typename T>
void List<T>::reverse()
{
	reverse_recursive(m_Head);
}

template<typename T>
void List<T>::reverse_recursive(Node<T>* _Node)
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

