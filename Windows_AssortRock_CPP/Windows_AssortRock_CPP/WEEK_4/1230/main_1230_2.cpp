#include <iostream>
#include "Heap.h"

// 열거형
// 매크로와 달리 C++ 문법이기 때문에
// 컴파일 타임에서 동작, 디버깅에 용이
// 나열된 타입 이외의 숫자가 입력될 수 없음(컴파일 타임에 오류를 방지)
enum STATE
{
	COLD, HIT
};

enum OTHER_STATE
{
	// 다른 열거형 타입에서 같은 이름을 사용하면
	// 모호성이 생겨 컴파일 에러가 발생
	// 이름 중복 문제를 피하기 위해 OTHER_COLD와 같이 네이밍을 하기도 함
	//COLD, 
	FIRE
};

// C++의 높은 버전에서는 enum에 강한 규칙을 적용한
// enum class를 제공
enum class MY_TYPE
{
	STATE_0,
	STATE_1,
	STATE_2
};

int main()
{
	HEAP_MODE mode = (HEAP_MODE)0;	// 이와 같이 정수를 강제 캐스팅도 가능
	MY_TYPE myType = MY_TYPE::STATE_0;
	//MY_TYPE myType = STATE_0;	// enum class는 :: 연산을 강제로 사용하게 함

	{
		Heap<int> myHeap;
		myHeap.SetMode(MAX);

		myHeap.push(10);
		myHeap.push(20);
		myHeap.push(5);
		myHeap.push(17);
		myHeap.push(3);
		
		myHeap.SetMode(MIN);
		int Array[5] = {};
		int Loop = myHeap.size();

		for (int i = 0; i < Loop; i++)
		{
			Array[i] = myHeap.Get();
		}

		for (int i = 0; i < Loop; i++)
		{
			std::cout << Array[i] << " ";
		}
	}



	//Heap<int>::iterator iter = minHeap.begin();
	//for (; iter != minHeap.end(); ++iter)
	//{
	//	std::cout << *iter << " ";
	//}

	return 0;
}