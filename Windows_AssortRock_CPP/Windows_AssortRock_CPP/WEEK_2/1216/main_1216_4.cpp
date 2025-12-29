// C++ 자료구조
#include <stdio.h>
#include <stdlib.h>

// 동적 배열
// 장점: 인덱싱으로 데이터를 접근할 경우 가장 빠르다.
// 단점: 데이터가 중간에 삽입되거나, 삭제되는 경우 효율이 안좋다.
//      최악의 경우는 맨 앞에 데이터가 삭제되거나 추가되는 경우

// 연결형 리스트
// 장점: 데이터가 중간에 삽입 삭제될때 가장 빠른구조
// 단점: 데이터 인덱싱이 느리다

struct Node
{
	int Data;	// 받아온 데이터 저장
	Node* pNext;
};

struct List
{
	Node* pHead;
	int Size;	// 노드의 개수 저장
};

void Push_Back(List* list, int data)
{
	Node* pNewNode = (Node*)malloc(sizeof(Node));	// 첫번째 노드를 함수의 지역에 생성
	pNewNode->Data = data;
	pNewNode->pNext = nullptr;

	// 최초입력인지 아닌지를 분기로 나누어 판별
	if (list->pHead == nullptr)	// list가 처음 데이터를 입력받는 경우
	{
		list->pHead = pNewNode;	// 처음 생성된 노드를 pHead 포인터에 연결
	}
	else // list가 최초 생성이 아님(1개 이상 보유)
	{
		// 리스트가 현재 보유한 데이터 중에서 가장 마지막 노드를 찾아낸다.
		Node* pLastNode = list->pHead;
		
		while (pLastNode->pNext != nullptr)
		{
			pLastNode = pLastNode->pNext;
		}

		// 마지막 노드가 새로 입력된 노드를 연결
		pLastNode->pNext = pNewNode;
	}

	++list->Size;	// 데이터 카운팅
}

// [Lab_0]
// 연결 리스트 Push_Front 함수 구현
// 연결 구조에서 마지막에 온 데이터를 앞으로 정렬
void Push_Front(List* list, int data)
{
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->Data = data;
	pNewNode->pNext = nullptr;

	// pHead가 null이면 최초생성
	if (list->pHead == nullptr)
	{
		list->pHead = pNewNode;
	}
	else
	{
		// 새로 생성한 노드가 기존 헤드를 자신의 다음으로 가리키고
		pNewNode->pNext = list->pHead;

		// 리스트는 새로 생성한 노드를 처음 노드로 가리킨다.
		list->pHead = pNewNode;
	}

	++list->Size;
}

// [Lab_1]
// 연결 리스트의 맨 앞, 맨 뒤에 있는 데이터를 삭제하는
// POP함수 구현해보기
void Pop_Back(List* list)
{

}

void Pop_Front(List* list)
{

}

// 메모리 해제 함수
void Release(List* list)
{
	Node* pNode = list->pHead;
	while (pNode != nullptr)
	{
		Node* pNext = pNode->pNext;
		free(pNode);
		pNode = pNext;
	}
}

int main()
{
	//List list = {};
	//Push_Back(&list, 5);
	//Push_Back(&list, 10);
	//Push_Back(&list, 15);
	//Push_Back(&list, 20);

	//Node* pNode = list.pHead;

	//for (int i = 0; i < list.Size; i++)
	//{
	//	printf("pNode->%d:  %d\n", i, pNode->Data);
	//	pNode = pNode->pNext;
	//}

	// 연결 리스트는 리스트를 모두 찾아서 동적할당 해제를 해야함
	//Release(&list);

	List list = {};
	Push_Front(&list, 5);
	Push_Front(&list, 10);
	Push_Front(&list, 15);

	Node* pNode = list.pHead;

	for (int i = 0; i < list.Size; i++)
	{
		printf("pNode->%d:  %d\n", i, pNode->Data);
		pNode = pNode->pNext;	
	}	

	// 연결 리스트는 리스트를 모두 찾아서 동적할당 해제를 해야함
	Release(&list);

	return 0;
}
