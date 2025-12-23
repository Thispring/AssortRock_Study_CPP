// CPP 재귀함수
#include <iostream>

// Recursive Function
// 함수가 자신을 재 호출하는 구조의 함수
// 계층구조 문제를 간결하게 해결가능
// ex)트리 자료구조, 부모자식 관계
void Add(int a, int b)
{
	Add(a, b);
}

// 재귀함수 활용
// 피보나치 수열
// 1 1 2 3 5 8 13 21 34 55...
void Fibofunc(int count)
{
	// [0] 합산, [1] 이전 숫자
	int fiboNums[3] = { 1, 1, 1 };
	// 횟수를 입력받으면
	// 1부터 해당 횟수까지 피보나치 수열 출력

	for (int i = 0; i < count; i++)
	{
		if (i == 1)
		{
			std::cout << fiboNums[2] << " ";
		}

		std::cout << fiboNums[0] << " ";

		
		fiboNums[0] = fiboNums[1] + fiboNums[2];
		fiboNums[2] = fiboNums[1];
		fiboNums[1] = fiboNums[0];
	}
	std::cout << std::endl;
}

void Fibo_Recfunc(int count)
{
	int num = 1;
	int num2 = 0;
	if (count == 1 || count == 2)
	{
		for (int i = 0; i < count; i++)
			std::cout << num << " ";

		return;
	}

	if (count < 1)
	{
		
		return;
	}
	else
		Fibo_Recfunc(count - 1);

	if (num != 1)
		num2 = count;
	else
		num2 = 0; 
	num = count - 1;
	num2 = num + count;
	std::cout << num2 << " ";
	//std::cout << std::endl;
}

// 팩토리얼 함수 구현(+재귀함수)
unsigned long long Factorial(unsigned long long num)
{
	if (num == 1)
		return 1;

	int temp = num;
	int count = num;
	for (int i = 1; i < count; i++)
	{
		temp *= num - i;
	}
	return temp;
}

unsigned long long Factorial_Rec(unsigned long long num)
{
	if (num == 1)
		return 1;
	else {
		return num * Factorial_Rec(num - 1);
	}
}

int main()
{
	//Add(1, 2);
	Fibofunc(10);
	std::cout << std::endl;

	Fibo_Recfunc(5);
	std::cout << std::endl;

	unsigned long long res1 = Factorial(12);
	std::cout << "!: " << res1 << std::endl;
	std::cout << std::endl;

	unsigned long long res2 = Factorial_Rec(12);
	std::cout << "rec!: " << res2 << std::endl;

	return 0;
}

// Ctrl + Space: 미완성된 항목의 예상 안내를 받을 수 있다.
// Ctrl + Shift + Space: 함수 인자 입력 커서위치에서 누르면, 해당 함수의 정보를 볼 수 있다.