#include "List.h"

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

	mSize++;
}

void List::push_front(const int& _Data)
{

}
