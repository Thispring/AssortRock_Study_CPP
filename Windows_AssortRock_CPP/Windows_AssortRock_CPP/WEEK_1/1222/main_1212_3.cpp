// CPP 포인터 2
#include <stdlib.h>
#include <stdio.h>

int main()
{
	// nullptr 주소(0번지)로 접근하면 런타임 에러 발생
	char* pChar = nullptr;
	//*pChar = 100;

	// void 포인터
	// 어떤 자료형의 주소라도 가려받지 않음
	// 단, 주소에 접근이 불가능
	// 형변환(캐스팅)을 통해 주소에 접근이 가능

	int* pVoid = nullptr;
	int alloCount = 0;
	printf("Input Memory Size: ");
	scanf_s("%d", &alloCount);

	pVoid = (int*)malloc(sizeof(int) * alloCount);

	for (int i = 0; i < alloCount; i++)
		pVoid[i] = i;

	for (int i = 0; i < alloCount; i++)
		printf("%d ", pVoid[i]);

	free(pVoid);

	return 0;
}