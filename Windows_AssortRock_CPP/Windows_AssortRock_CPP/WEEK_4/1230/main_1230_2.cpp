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

int main()
{
	Heap<int> myHeap;
	myHeap.push(10);
	myHeap.push(20);
	myHeap.push(5);
	myHeap.push(17);
	myHeap.push(3);

	myHeap.SetMode(MAX);
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

	//Heap<int>::iterator iter = minHeap.begin();
	//for (; iter != minHeap.end(); ++iter)
	//{
	//	std::cout << *iter << " ";
	//}

	return 0;
}