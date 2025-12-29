#pragma once

struct Node
{
    int Data;   // 데이터를 저장하는 변수
    Node* Next; // 다음 Node를 가리키는 포인터 변수
    Node* Prev; // 이전 Node를 가리키는 포인터 변수

    // 구조체에서도 생성 소멸자를 호출 할 수 있다.
    // 디폴트 생성자
    Node()
    : Data(0)
    , Next(nullptr)
    , Prev(nullptr)
    {

    }

    // const int& 인수를 받는 생성자
    Node(const int& _Data)
    : Data(_Data)
    , Next(nullptr)
    , Prev(nullptr)
    {

    }

};

class List
{
private:
    int mSize;   // 몇 개의 데이터를 저장했는지 기록하는 변수
    Node* mHead;    // 연결된 리스트의 첫번째를 가리키는 포인터 변수 
    Node* mTail;    // 연결된 리스트의 끝을 가리키는 포인터 변수
// 함수 구현
public:
    // 데이터를 맨 뒤에 추가
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

// 생성, 소멸자 구현
public:
    List();
    ~List();
};