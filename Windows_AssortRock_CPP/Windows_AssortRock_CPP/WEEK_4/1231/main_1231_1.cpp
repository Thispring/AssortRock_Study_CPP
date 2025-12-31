// C++ 이진탐색
#include <iostream>
#include <time.h>
#include <random>
#include <string>
#include "C:\Users\141245124\Documents\GitHub\AssortRock_Study_CPP\Windows_AssortRock_CPP\Windows_AssortRock_CPP\WEEK_4\1230\Heap.h"

// 이진탐색:
// 분할 정복 알고리즘
// 
// 이진트리 + 이진탐색 -> 이진탐색트리

// 이진탐색 컨테이너 set, map
#include <set>
#include <map>

using namespace std;

// 이진탐색 구현
template<int Size>
int BinarySearch(int(&_arr)[Size], int _find)
{
	// 이진 탐색은 중간으로 들어가서, 검색범위를 좁혀야함
	int Start = 0;
	int End = Size - 1;

	while (1)
	{
		// 탐색 범위에서 중간 인덱스
		int Idx = (Start + End) / 2;
		
		// 중간 인덱스에서 찾는 숫자와 일치하면, 해당 인덱스 반환
		if (_arr[Size] == _find)
			return Idx;

		// 탐색 중, Start와 End가 같은 값이 되었더라도 찾지 못했다면
		// 찾으려는 값이 없다는 뜻
		if (Start >= End)	// 정수 나눗셈은 소수점이 없으므로, 홀수연산에 대한 예외처리
			return -1;

		// 찾는 숫자가 중간 인덱스 보다 더 크다면
		if (_arr[Idx] < _find)
			Start = Idx + 1;
		else  // 찾는 숫자가 중간 인덱스 보다 더 작다면
			End = Idx - 1;
	}

	return -1;
}

int main()
{
	// 이진탐색의 검사 대상 데이터가 정렬되어있다면

	// 탐색알고리즘	시간복잡도 bigO 표기법
	// 순차 탐색:		O(N)
	// 이진 탐색:		O(logN)

	Heap<int> minHeap;

	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		minHeap.push(rand() % 1000 + 1);
	}
	
	int Data[10] = {};
	for (int i = 0; i < 10; i++)
	{
		Data[i] = minHeap.Get();
	}

	int a = 0;

	{
		set<int> intSet;
		intSet.insert(1);
		intSet.insert(2);
		set<int>::iterator Iter = intSet.begin();
		//cout << *Iter << endl;
	}

	{
		// map의 첫번째 타입은 인덱스, 두번째는 데이터로 사용
		map<int, float> myMap;
		myMap.insert(make_pair(50, 1.1f));
		map<int, float>::iterator Iter = myMap.find(50);
	}

	{
		map<int, string> cppMap;
		cppMap.insert(make_pair(1, "int"));
		cppMap.insert(make_pair(2, "short"));
		cppMap.insert(make_pair(3, "long"));
		cppMap.insert(make_pair(4, "longlong"));
		map<int, string>::iterator Iter = cppMap.begin();
		cout << cppMap[1] << endl;
		//cout << *Iter << endl;	// map은 *Iter연산이 불가능
		cout << cppMap[2] << endl;

		int a = 0;
	}


	return 0;
}