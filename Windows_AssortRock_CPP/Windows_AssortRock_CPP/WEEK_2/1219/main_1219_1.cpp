// C++ 동적 배열 실습

// C Style
#include <stdio.h>
#include <stdlib.h>

// 데이터를 저장하고, 다음 Node를 가리키는 역할
struct Node
{
	Node* pNext;	// 다음 Node를 가리키는 Node 포인터 변수
	int Data;		// 값을 저장하는 변수
};

// Node의 시작점
struct List
{
	Node* pHead;
	int Count;	// Node가 연결될때마다 +1
};

void push_back(List* _pList, int _Data)
{
	// Count의 개수에 따라 조건 분기
	// 최초 생성
	if (_pList->Count == 0)
	{
		// 동적할당을 하지않으면, 함수가 한 번 돌고, Node newNode 변수는 수명이 끝남
		Node* newNode = (Node*)malloc(sizeof(Node));
		_pList->pHead = newNode;
		newNode->pNext = nullptr;
		newNode->Data = _Data;
	}
	else    // 이전에 이미 생성 됨
	{
		Node* lastNode = _pList->pHead;
		// Head가 연결하고 있는 Node의 pList에 nullptr이 있는지 검사
		while (lastNode->pNext != nullptr)
		{
			lastNode = lastNode->pNext;
		}
		Node* newNode = (Node*)malloc(sizeof(Node));
		lastNode->pNext = newNode;
		newNode->pNext = nullptr;
		newNode->Data = _Data;
	}

	_pList->Count++;
}

void freeMemory(List* _list)
{
	//Node* pNode = _list->pHead;
	//while (pNode != nullptr)
	//{
	//	Node* pNext = pNode->pNext;
	//	free(pNode);
	//	pNode = pNext;
	//}

	Node* lastNode = _list->pHead;
	while (lastNode->pNext != nullptr)
	{
		Node* pNode = lastNode->pNext;
		free(lastNode);
		lastNode = pNode;
	}
}

int main()
{
	List myList;
	myList.pHead = nullptr;
	myList.Count = 0;

	push_back(&myList, 10);
	push_back(&myList, 20);
	push_back(&myList, 30);
	push_back(&myList, 40);
	push_back(&myList, 50);


	//// 노드 연결 흐름을 함수로 작성하기
	//Node myNode1;
	//myNode1.Data = 10;
	//Head.pNext = &myNode1;
	//Head.Data = (Head.pNext->Data);

	//Node myNode2;
	//myNode2.Data = 20;
	//myNode1.pNext = &myNode2;
	//myNode1.Data = (myNode1.pNext->Data);

	// free함수로 동적할당 메모리 해제 시, myList의 주소를 전달하면
	// myList가 가리키는 첫번째 메모리부터 해제가 되어 연결이 끊겨 해제가 불가능
	// 역순으로 해제 시키기
	freeMemory(&myList);

	return 0;
}
