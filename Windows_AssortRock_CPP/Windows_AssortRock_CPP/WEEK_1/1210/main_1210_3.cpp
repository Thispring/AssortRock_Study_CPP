// CPP 함수 문법
#include <iostream>
#include <ctime>

// Default 인자
// 기본으로 보장되는 입력값을 미리 설정
// Default 인자는 뒤에서 부터 세팅이 가능

void funC(int a, int b, int c = 0)
{
	std::cout << a + b + c << std::endl;
}

// (*)함수 오버로딩
// 함수의 이름이 같더라도
// 매개변수의 개수나 타입이 다를 경우
// 같은 이름의 함수 중복 가능
void funC(int a)
{
	std::cout << a << std::endl;
}
// (*)함수 오버로딩과 오버라이딩의 차이
// https://brunch.co.kr/@kimkm4726/2

// [*Lab_0]
// 버블정렬
// 작은 수 부터 정렬
void BubbleSort(int(&Arr)[10], bool isAscending)
{
	// 배열을 하나 더 선언하는게 아닌
	// 매개변수로 받은 배열을 이용하여 다시 만들어보기
	int tmpA[10] = { };
	int tmp = 0;
	int tmpIndex = 0;
	int index;
	int assenNum;

	if (isAscending)
	{
		index = 9;
		assenNum = -1;
	}
	else
	{
		index = 0;
		assenNum = 1;
	}

	for (int i = 0; i < 10; i++)
	{
		tmpA[i] = Arr[i];
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			// 제일 큰 수를 기준으로 배열 순회 후
			// Arr의 마지막 인덱스부터 채우기
			if (tmpA[j] >= tmp)
			{
				tmp = tmpA[j];
				tmpIndex = j;
			}
		}

		Arr[index] = tmp;
		tmpA[tmpIndex] = 0;
		index += assenNum;
		tmp = 0;
		tmpIndex = 0;
	}
}

void Fix_BubbleSort(int(&arr)[], bool isAscending)
{
	for (int i = 0; i < 9; i++)
	{
		bool isSwap = false;

		for (int j = 0; j < 9 - i; j++)
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

int main()
{
	funC(1, 2);
	funC(200);

	// 무작위로 수를 집어넣고, 작은 수 부터 정렬
	srand(time(NULL));

	int Arr[10];
	for (int i = 0; i < 10; i++)
		Arr[i] = rand() % 100 + 1;
	int Arr2[10];
	for (int i = 0; i < 10; i++)
		Arr2[i] = rand() % 100 + 1;

	std::cout << std::endl << "Before Sort" << std::endl;
	for (int i = 0; i < 10; i++)
		std::cout << Arr[i] << " ";
	BubbleSort(Arr, true);
	std::cout << std::endl << "After Sort" << std::endl;
	for (int i = 0; i < 10; i++)
		std::cout << Arr[i] << " ";

	std::cout << std::endl << std::endl << "Before Fix_Sort" << std::endl;
	for (int i = 0; i < 10; i++)
		std::cout << Arr2[i] << " ";
	Fix_BubbleSort(Arr2, false);
	std::cout << std::endl << "After Fix_Sort" << std::endl;
	for (int i = 0; i < 10; i++)
		std::cout << Arr2[i] << " ";

	return 0;
}