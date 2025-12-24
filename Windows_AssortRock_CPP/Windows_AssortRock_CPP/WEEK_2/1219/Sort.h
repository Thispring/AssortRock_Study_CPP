#pragma once
#include <stdlib.h>

// 선택 정렬
template<int Size>
void SelectionSort(int(&Arr)[Size])
{
	// 정렬 인덱스의 값을 기준으로, 배열을 순회하였을 때 가장 작은 값을 인덱스에 정렬
	int minNum = 0;
	int temp = 0;
	int index = 0;

	while (1)
	{
		if (minNum == Size)
			break;

		for (int i = index; i < Size; i++)
		{
			if (Arr[minNum] > Arr[i])
			{
				temp = Arr[minNum];
				Arr[minNum] = Arr[i];
				Arr[i] = temp;
			}
		}
		minNum++;
		index++;
	}
}

// 삽입 정렬
template<int Size>
void InsertionSort(int(&Arr)[Size])
{	
	int insertNum = 0;
	for (int i = 1; i < Size; i++)
	{
		for (int j = 0; j < Size; j++)
		{
			// j는 i가 되기 전까지만 검사
			if (j == i)
			{
				break;
			}

			if (Arr[j] > Arr[i])
			{
				int temp = Arr[i];
				// j가 아직 i까지 전부 순회하지 않았다면
				if (i != 1)	// i가 1이라면 (초반) 검사 생략
				{
					int Idx = j;	// 동적배열을 사용할 임시 인덱스 변수
					if (i > j)
						insertNum = i - j;
					else
						insertNum = j - i;

					int* pTemp = (int*)malloc(sizeof(int) * insertNum);
					// 임시 포인터 변수에 값 복사
					for (int k = 0; k < insertNum; k++)
					{
						pTemp[k] = Arr[Idx];
						Idx++;
					}
					// 값 옮기기
					// 작은 값부터 순차적으로 옮겨야하기 때문에 삽입점인 j의 다음 위치부터 값을 복사
					Idx = j + 1;
					for (int k = 0; k < insertNum; k++)
					{
						Arr[Idx] = pTemp[k];
						Idx++;
					}
					// 끝났으면 동적할당 해제
					free(pTemp);
					Arr[j] = temp;
					break;
				}

				// 첫 for문 기준 j는 0에서 해당 조건이 걸리기 때문에
				// j자리는 0
				Arr[i] = Arr[j];
				Arr[j] = temp;
				break;
			}
		}
		insertNum = 0;
	}
}

template<int Size>
void Fix_BubbleSort(int(&arr)[Size], bool isAscending)
{
	for (int i = 0; i < (Size-1); i++)
	{
		bool isSwap = false;

		for (int j = 0; j < (Size-1) - i; j++)
		{
			// 오름차순
			// j번째 배열과 그 다음 순서의 배열을 비교해서
			// j번째가 더 크다면 오름차순 정렬이 되지 않았으므로 값 교환
			if (isAscending && arr[j] > arr[j + 1])
			{
				isSwap = true;
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}

			// 내림차순
			// j번째 배열과 그 다음 순서의 배열을 비교해서
			// j번째가 더 작다면 내림차순 정렬이 되지 않았으므로 값 교환
			if (!isAscending && arr[j] < arr[j + 1])
			{
				isSwap = true;
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}

		if (!isSwap)
		{
			break;
		}
	}
}