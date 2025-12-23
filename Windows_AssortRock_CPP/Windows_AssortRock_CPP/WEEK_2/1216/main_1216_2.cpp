// C++ 자료구조
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// 자료구조(Data Structure)
// 동적배열(가변배열)
struct Array
{
	int* pData;		// 동적할당 받은 힙 공간을 가리킬 포인터
	int Capacity;	// 동적할당 받은 공간에 최대 저장할 수 있는 int 개수
	int Size;		// 동적할당 받은 공간에 저장시킨 데이터 개수
};

void Init(Array* arr)
{
	printf("Input Capacity: ");
	scanf("%d", &arr->Capacity);
	arr->pData = (int*)malloc(arr->Capacity * sizeof(int));
}

// 동적배열에 접근해 Data를 넣는 함수
bool Push_Back(Array* arr, int Data)
{
	if (arr->Capacity == arr->Size)
	{
		printf("Out of Range\n");
		free(arr->pData);
		return false;
	}

	arr->pData[arr->Size] = Data;
	printf("%d ", arr->pData[arr->Size]);
	arr->Size++;
	return true;
}

int main()
{
	Array arr = {nullptr, 0, 0};
	Init(&arr);
	bool isPush;

	for (int i = 0; i < 5; i++)
	{
		isPush = Push_Back(&arr, 2);
		if (!isPush) break;
	}

	//free(arr.pData);
	
	return 0;
}