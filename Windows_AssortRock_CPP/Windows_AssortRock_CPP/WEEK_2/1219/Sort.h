#pragma once
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
	int insertCount = 0;
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
				// j가 아직 i까지 전부 순회하지 않았다면
				if (i != 1 && insertCount != 0)	// i가 1이라면 (초반) 검사 생략
				{
					int temp = Arr[i];
					// 삽입점(j) 기준으로 뒤에 있는 배열 요소들을 n칸씩 밀기
					int move = 0;	// 배열 이동을 위한 임시 인덱스 변수
					while (insertCount != 0)
					{
						// inserCount만큼 i번째 위치에 i이전 위치에 있는 값을 옮기고
						// i이전 위치에는 i - 2 위치에 있는 값을 옮기는 식의 반복
						Arr[i - move] = Arr[i - (1 - move)];
						insertCount--;
						move++;
						continue;
						//Arr[i - 1] = Arr[i - 2];
						//Arr[i - 2] = Arr[i - 3];	// 이런식으로 반복해야함
						//// 몇개를 옮겨야할지는 inserCount와 i사이에 몇개의 배열이 존재하는지 확인
					}
					// 반복이 끝나고 임시로 저장한 Arr[i]값을 비워진 Arr[j]위치에 넣기
					Arr[j] = Arr[i];
					break;
				}

				// 첫 for문 기준 j는 0에서 해당 조건이 걸리기 때문에
				// j자리는 0
				int temp = Arr[i];
				Arr[i] = Arr[j];
				Arr[j] = temp;
				break;
			}
			insertCount++;
		}
		insertCount = 0;
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