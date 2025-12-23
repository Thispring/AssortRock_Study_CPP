// C++ 선택, 삽입 정렬 알고리즘
#include <iostream>
#include <cstring>
#include <time.h>
#include <chrono>	// 시간 측정에 대한 헤더
// 출처: https://giveme-happyending.tistory.com/221 [소연의_개발일지:티스토리]
#include "Sort.h"

// 자료구조 정렬은 크게 '안정 정렬', '불안정 정렬'로 나눌 수 있다.
// 버블(안정), 삽입(안정), 병합(안정), 힙소트(안정)
// 선택(불안정), 퀵 소트(불안정)
// 의도에 맞게 정렬 알고리즘을 선택 해야한다.
// 안정 정렬, 불안정 정렬의 특징을 살펴보기

// 게임에서 정렬 예시
// 자신이 가지고 있는 수많은 캐릭터의 공격력, 방어력 순으로 정렬하는 기능
// 위 예시에서 안정과 불안정 정렬의 차이점은?
// 안정 정렬은 이전 수치에 대한 정렬은 유지되고, 불안정 정렬은 이전 정렬이 유지가 되지 않는다.

int main()
{
	// 이전에 구현했던 버블정렬과 시간 비교해보기

	srand(time(NULL));

	int array[10000];
	for (int i = 0; i < 10000; i++)
	{
		array[i] = rand() % 100;
	}
	int array2[10000];
	for (int i = 0; i < 10000; i++)
	{
		array2[i] = rand() % 100;
	}
	int array3[10];
	for (int i = 0; i < 10; i++)
	{
		array3[i] = rand() % 100;
	}

	//// 시작 시간 측정
	//auto start = std::chrono::high_resolution_clock::now();
	//SelectionSort(array);
	//// 종료 시간 측정
	//auto stop = std::chrono::high_resolution_clock::now();
	//// 경과 시간 계산
	//auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	//std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;
	//std::cout << std::endl;

	//// 시작 시간 측정
	//auto start2 = std::chrono::high_resolution_clock::now();
	//Fix_BubbleSort(array2, true);
	//// 종료 시간 측정
	//auto stop2 = std::chrono::high_resolution_clock::now();
	//// 경과 시간 계산
	//auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(stop2 - start2);
	//std::cout << "Time taken by function: " << duration2.count() << " microseconds" << std::endl;
	//std::cout << std::endl;

	// 시작 시간 측정
	auto start3 = std::chrono::high_resolution_clock::now();
	InsertionSort(array3);
	// 종료 시간 측정
	auto stop3 = std::chrono::high_resolution_clock::now();
	// 경과 시간 계산
	auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(stop3 - start3);
	std::cout << "Time taken by function: " << duration3.count() << " microseconds" << std::endl;
	std::cout << std::endl;

	//memmove
	return 0;
}