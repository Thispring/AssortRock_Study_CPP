


// 함수(코드) 가 저장된 코드영역
// 스택 메모리 영역

// 재귀함수 - Recursive
// 함수가 자신을 재 호출하는 구조의 함수
// 계층구조 문제 해결
// 스택오버플로우를 조심해야한다.
// 스택오버 플로우 - 재귀함수의 종료조건이 제대로 설정되지 않아서 무한히 스택이 생성되는 경우, 스택 공간이 모자라서 발생
// 재귀함수를 설계할때에는 종료조건이 확실하게 있어야 한다.
void Add(int a, int b)
{
	static int iCount = 0;

	++iCount;

	if (iCount >= 3)
	{
		return;
	}	
	else
	{
		Add(20, 20);
		int a = 0;
	}	
}

// 재귀함수 활용
// 피보나치수열
// 1 1 2 3 5 8 13 21 34 55...
int Fibonacci(int Num)
{
	// 반복문
	if (1 == Num || 2 == Num)
		return 1;

	int Prev1 = 1;
	int Prev2 = 1;
	int RepeatCount = Num - 2;

	int Result = 0;

	for (int i = 0; i < RepeatCount; ++i)
	{
		Result = Prev1 + Prev2;
		Prev1 = Prev2;
		Prev2 = Result;
	}

	return Result;
}

int Fibonacci_Recursive(int Num)
{
	// 재귀함수
	if (1 == Num || 2 == Num)
		return 1;
		
	return Fibonacci_Recursive(Num - 2) + Fibonacci_Recursive(Num - 1);
}

// 팩토리얼
// 10
// 10! = 1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10
long long Factorial(long long Num)
{
	if (Num == 1)	
		return 1;
	
	int Result = 1;

	for (int i = 0; i < Num; ++i)
	{
		Result *= i + 1;
	}

	return Result;
}

// 팩토리얼을 구하는 함수, 재귀함구 구조로 설계함
long long Factorial_Recursive(long long Num)
{
	if (Num == 1)
		return 1;
	
	return Factorial_Recursive(Num - 1) * Num;
}


int main()
{
	Add(10, 10);

	int Data = Fibonacci(10);

	Data = Fibonacci_Recursive(10);

	int a = Factorial(5);

	a = Factorial_Recursive(5);

	return 0;
}

// Ctrl + Space : 미완성된 항목의 예상 안내를 받을 수 있다.
// Ctrl + Shift + Space : 함수 인자 입력 커서위치에서 누르면, 해당 함수의 정보를 볼 수 있다.

