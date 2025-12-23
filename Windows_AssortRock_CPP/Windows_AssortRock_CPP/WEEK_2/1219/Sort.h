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
	// 삽입 후, 뒤에 있는 값을 몇번 정렬할지 저장하는 변수
	int sortCount = 0;
	for (int i = 1; i < Size; i++)
	{
		for (int j = 0; j < Size; j++)
		{
			// j가 더 큰 경우, i번째 있는 숫자가 가장 작은 값이므로
			// j위치가 삽입점이 됨
			if (j == i)	// j가 i보다 클때는 검사 X
				break;
			if (Arr[j] >= Arr[i])
			{
				// Arr[j]는 Arr[i]기준으로 가장 큰 값
				int tempMax = Arr[j];
				
				int sortCount = 0;
				// 0부터 i까지의 몇개의 배열이 존재하는지 검사
				for (int k = 0; k < i; k++)
				{
					sortCount++;
				}
				// sortCount가 0이 아니라면 0부터 i까지 이미 배열이 있으므로
				// 남은 배열을 서로 순회하면서 큰 값이 있다면 마지막 자리에 정렬하기
				while (sortCount != 0)
				{
					// Arr[sortCount], Arr[sortCount -1]... 식으로 정렬하기
					if (Arr[sortCount] <= Arr[sortCount - 1])
					{
						// sortCount - 1이 크면 sortCount자리로 옮겨야함
						int tempMin = Arr[sortCount - 1];
						Arr[sortCount - 1] = Arr[sortCount];
						Arr[sortCount] = tempMin;
					}
					sortCount--;
				}
			}
			
		}
		sortCount = 0;
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