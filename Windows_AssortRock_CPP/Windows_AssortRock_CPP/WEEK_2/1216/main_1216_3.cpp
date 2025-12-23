// C++ 함수 템플릿
#include <stdio.h>
#include <stdlib.h>

// 함수 오버로딩
// 이름이 같은 함수를 인자의 개수, 타입 등을 다르게 하여 구현
// 반환타입은 영향 없음

// 함수 템플릿(틀, 주형)
template<typename T>
T Mul(T a, T b)
{
	return a * b;
}	
// 템플릿을 통해 틀을 제공하고, typename 키워드를 이용해
// 자료형에 상관없이 함수 실행

// 구조체 템플릿
template<typename T>
struct Array
{
	T* pData;
	T Capacity;
	T Size;
};

// 구조체 템플릿을 이용한 동적할당 함수
template<typename T>
void Init(Array<T>* arr)
{
	arr->Capacity = 1;
	// T의 자료형에 따라 어떤 타입의 메모리를 동적할당할지 결정
	arr->pData = (T*)malloc(sizeof(T) * arr->Capacity);
	arr->Size = 0;
}

// 템플릿을 이용한 동적할당 공간에 데이터를 넣는 함수
template<typename T>
void PushBack(Array<T>* arr, T Data)
{
	arr->pData[arr->Size] = Data;
	arr->Size++;
}

int main()
{
	{
		// 컴파일러가 자료형을 유추하여, 호출될때 알맞은 함수를 생성하여 실행
		int i = Mul(2, 5);
		float f = Mul(3.14, 5.2);
		double d = Mul<double>(3.1, 2.5);	// < >을 통해 명시적으로 자료형을 표시할 수 있음
	}

	{
		Array<int> iArray;		// 구조체를 int형으로 선언
		Array<char> cArray;	// 구조체를 char형으로 선언
		Init(&cArray);
		PushBack(&iArray, 5);
	}

	return 0;
}