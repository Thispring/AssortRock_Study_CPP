#pragma once

// 알고리즘 간의 효율성을 비교하는 빅오(big-O) 표기법
// https://noahlogs.tistory.com/27

// 단순하게 데이터를 저장하는 용도
struct Node
{
	int Data;
	// 양방향성으로 포인터를 활용하기
	Node* pNext;
	Node* pPrev;

	// C++문법에서 구조체도 생성자를 사용가능
	// 디폴트 생성자
	Node()
		: Data()
		, pNext(nullptr)
		, pPrev(nullptr)
	{ }

	// const int&을 받는 생성자
	Node (const int& _Data)
		: Data(_Data)
		, pNext(nullptr)
		, pPrev(nullptr)
	{ }
};

// List는 관리자 역할
class List
{
private:
	Node* mHead;	// 첫 번째 노드를 가리키는 포인터
	Node* mTail;	// 끝 노드를 가리키는 포인터
	int mSize;	// 데이터가 몇개가 들어왔는지 확인
public:
	// 데이터를 맨 뒤에 추가
	void push_back(const int& _Data);	// 자료형이 바뀔수도 있기에 const 참조형으로 선언

	// 데이터를 맨 앞에 추가
	void push_front(const int& _Data);
	// 맨 뒤 데이터 제거
	void pop_back(const int& _Data);
	// 맨 앞 데이터 제거
	void pop_front(const int& _Data);
	
	// 데이터를 역순으로 정렬
	void reverse();
private:
	// 데이터를 역순으로 정렬, 재귀함수로 구현
	// Tip: 연결리스트는 메모리 공간이 연속적인게 아닌, 포인터로 주소를 가리켜 연결시킨 구조이므로
	// 재귀함수 호출이 끝났을 때, 연결상태를 생성된 역순으로 가리키게 변경, 그림을 그려가면서 구조를 설계하기
	// 재귀함수는 종료조건까지 자기자신의 함수가 호출되며, 스택이 쌓이고 종료가 되면서 먼저 쌓인 스택부터 빠져나가는 것을 유의
	void reverse_recursive(Node* _Node);
	
public:
	List();
	~List();
};

