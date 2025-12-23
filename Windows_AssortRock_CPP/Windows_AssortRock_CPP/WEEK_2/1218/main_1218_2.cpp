// C++ 다중 포인터
#include <iostream>
#include <stdlib.h>

void DynamicAlloc(int** _ppInt)
{
	*_ppInt = (int*)malloc(sizeof(int));
}

int main()
{
	// int*를 가리키는 포인터 변수
	int i = 10;
	int** ppInt = nullptr;
	int* pInt = &i;

	ppInt = &pInt;
	//*(ppInt) = 100;	// ppInt의 역참조는 pInt의 주소값을 참조
	*(*ppInt) = 100;

	DynamicAlloc(ppInt);

	int* pData = nullptr;
	DynamicAlloc(&pData);

	free(ppInt);
	free(pData);

	return 0;
}