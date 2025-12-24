#pragma once
#include <assert.h>
// 템플릿에 관한 자료
// https://koey.tistory.com/113

// ===================
// TODO 1224: 
// 연결형 리스트 템플릿화
// ===================

// 멤버 함수는 외부에 따로 구현 후 정리해서 보기 편하게 하기
// 생성, 소멸자는 내부에서 모두 구현

// ==========
// Node 선언부
// ==========
template <typename T>
struct Node
{
	T		Data;
	Node*	Next;
	Node*	Prev;

	Node() : Data(), Next(nullptr), Prev(nullptr) {}
	Node(const T& _Data) : Data(_Data), Next(nullptr), Prev(nullptr) {}
};

// ==========
// List 선언부
// ==========
template <typename T>
class List
{
private:
	Node<T>*		m_Head;
	Node<T>*		m_Tail;
	T				m_Size;	// 연결 리스트의 총 길이

public:
	// 데이터를 맨 뒤에 추가
	void push_back(const T& _Data);

	// 데이터를 맨 앞에 추가
	void push_front(const T& _Data);

	// 맨 뒤 데이터 제거
	void pop_back();

	// 맨 앞 데이터 제거
	void pop_front();

	void reverse();

private:
	void reverse_recursive(Node<T>* _Node);

public:
	List() : m_Head(nullptr), m_Tail(nullptr), m_Size() {};
	//~List();

// =========================
// List의 iterator class 구현
// =========================
//public:
//	// 자료구조의 특징을 생각하여 구현하기
//	// 연결형 리스트는 연속적인 데이터 구조가 아님
//	// -> 많은 데이터가 저장된 상태에서 인덱싱으로 
//	// 자료를 찾을 경우에 속도가 많이 느림
//	// -> 자기가 가리키고 있는 Node의 주소를 바로 전달
//	class iterator
//	{
//	private:
//		List<T>* m_Owner;
//		List<T>* m_Node;	// m_Owner가 nullptr가 아니고 m_Node는 nullptr인 경우
//	
//	// 멤버 함수
//	public:
//		//bool operator == () {}
//		//bool operator != () {}
//
//		T& operator*() { }
//
//		iterator& operator ++()
//		{
//
//			return *this;
//		}
//
//		iterator& operator ++(int)
//		{
//
//		}
//
//		iterator& operator --()
//		{
//
//		}
//
//		iterator& operator --(int)
//		{
//
//		}
//
//	// 생성, 소멸자
//	public:
//		iterator() : m_Owner(nullptr), m_Node(nullptr) {}
//		iterator(List<T>) : m_Owner(), m_Node() {}
//		// 디폴트 소멸자 사용
//	};
};

// ===================
// List 멤버 함수 구현부
// ===================

template <typename T>
void List<T>::push_back(const T& _Data) {
	
	// new 키워드를 사용해서 Node<T>만큼 객체를 새로 생성
	Node<T>* pNewNode = new Node<T>(_Data);

	// 분기를 최초 생성과 최초 생성이 아닐때로 나눔
	if (m_Size == 0)
	{
		// Head와 Tail모두 새 노드를 가리킴
		m_Head = m_Tail = pNewNode;
	}
	else
	{
		// Tail이 가리키고 있던 노드(이전 생성 노드)의 Next를 새로 생성한 노드로 연결
		m_Tail->Next = pNewNode;
		// 새로 생성한 노드의 이전을 가리키는 포인터는(현재 null) Tail(이전 생성 노드를 가리킴)을 가리키게 함
		pNewNode->Prev = m_Tail;
		// Tail을 새로 생성한 노드로 연결(함수 다시 실행 시, Tail은 이전 생성 노드를 가리키게 됨)
		m_Tail = pNewNode;
	}

	++m_Size;
}

template <typename T>
void List<T>::push_front(const T& _Data) {

}

template <typename T>
void List<T>::pop_back() {

}

template <typename T>
void List<T>::pop_front() {

}

template <typename T>
void List<T>::reverse() {

}
