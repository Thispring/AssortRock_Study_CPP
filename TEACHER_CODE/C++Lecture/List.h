#pragma once


struct Node
{
	int		Data;
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

class List
{
private:
	Node*		m_Head;
	Node*		m_Tail;
	int			m_Size;

public:
	void push_back(const int& _Data);

	// 데이터를 맨 앞에 추가
	void push_front(const int& _Data);

	// 맨 뒤 데이터 제거
	void pop_back();

	// 맨 앞 데이터 제거
	void pop_front();

	void reverse();

private:
	void reverse_recursive(Node* _Node);

public:
	List();
	~List();
};

