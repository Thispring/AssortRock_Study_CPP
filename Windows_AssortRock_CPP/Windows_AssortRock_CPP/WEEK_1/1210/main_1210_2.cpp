// CPP 함수
#include <iostream>

// 함수
// 코드를 모듈화 하고 재활용하기 위함
// 새로운 기능을 만들때 편리

// 함수는 [반환타입 함수이름 (매개변수) {함수 기능}]으로 이루어져 있음 
int Add(int a, int b) { return a + b; }

// (*)실제 컴퓨터 스택에서 함수가 어떻게 동작하는지에 대해 생각하기
// 스택은 선입후출(후입선출)의 자료구조

int Pow(int Num, int Count);

int recPow(int Num, int Count)
{
	if (Count == 0)
		return 1;

	return Num * recPow(Num, Count - 1);
}

// main도 하나의 함수로 컴파일러의 진입 함수
int main()
{
	int c = Add(100, 200);

	// [*Lab_0]
	// 제곱근 구하는 함수
	// 함수구조: int Pow(int Num, int Count)
	// 사용방법: int Num = Pow(2, 10);
	// Num에 1024 저장
	int res = Pow(2, 10);
	printf("%d\n", res);

	printf("%d\n", recPow(2, 10));

	return 0;
}
// 지역변수와 전역변수


// F10	: 프로시저 단위로 실행
// F11	: 최소 작업단위로 코드 실행

int Pow(int Num, int Count)
{
	int res;
	for (res = 1; 1 <= Count; --Count)
	{
		res *= Num;
	}
	return res;

	//if (Count > 0)
		//return Pow(Num, Count - 1);
}