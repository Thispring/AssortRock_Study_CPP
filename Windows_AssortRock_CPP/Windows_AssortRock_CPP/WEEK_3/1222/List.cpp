#include "List.h"

#include <assert.h>

List::List()
	: mHead(nullptr)
	, mTail(nullptr)
	, mSize(0)
{

}

List::~List()
{
	// 현재 노드주소를 지우고, 다음 노드를 연결
	Node* pNode = mHead;

	while (pNode != nullptr)
	{
		Node* pNext = pNode->pNext;
		delete pNode;
		pNode = pNext;
	}
}

// 데이터를 맨 뒤에 추가
// 스스로 구현완료, 추후 다시 구현할 수 있는지 점검하기
void List::push_back(const int& _Data)
{
	// Node 포인터만큼 new로 동적할당
	Node* pNewNode = new Node(_Data);	// const int& 생성자를 호출하여 초기화
	 
	// 최초 생성이라면
	if (mSize == 0)
	{
		// Head와 Tail 포인터를 설정
		mHead = pNewNode;
		mTail = pNewNode;
	}
	else
	{
		// 기존에 있던 포인터를 새로 생성된 Node에 연결
		mTail->pNext = pNewNode;
		pNewNode->pPrev = mTail;
		mTail = pNewNode;
	}

	++mSize;
}

// 데이터를 맨 앞에 추가
// 스스로 구현완료, 추후 다시 구현할 수 있는지 점검하기
void List::push_front(const int& _Data)
{
	Node* newNode = new Node(_Data);

	if (mSize == 0)
	{
		mHead = newNode;
		mTail = newNode;
	}
	else
	{
		// mHead가 갱신되면서 pPrev가 새로운 노드에 연결
		mHead->pPrev = newNode;
		newNode->pNext = mHead;
		mHead = newNode;
	}

	++mSize;
}

// 맨 뒤 데이터 제거
void List::pop_back(const int& _Data)
{
	// assert는 디버깅을 위해 사용하는 매크로 (디버그 모드에서만 실행)
	// assert의 조건이 참인 경우, 프로그램 계속 진행
	// 거짓인 경우 에러 메시지를 출력하고 프로그램 즉시 종료
	assert(0 != mSize);

	// 연결 리스트의 뒤 부터 데이터를 제거하는 기능
}
