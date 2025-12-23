#include <stdlib.h>

void DynamicAlloc(int** _ppInt)
{
	*_ppInt = (int*)malloc(4);
}

int main()
{
	int Number = 0;

	// 포인터
	int* pInt = &Number;
	*pInt = 100;

	// 이중 포인터
	int** ppInt = &pInt;
	*(*ppInt) = 200;

	int* pData = nullptr;
	DynamicAlloc(&pData);

	return 0;
}
