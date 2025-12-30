#pragma once

// https://gmlwjd9405.github.io/2018/05/10/data-structure-heap.html

#include "Arr.h"

// Heap의 루트를 최솟값으로 할지 최댓값으로 할지를 결정
enum HEAP_MODE
{
	MIN,
	MAX,
};

template<typename T>
class Heap : public Arr<T>
{
private:
	HEAP_MODE m_Mode;
	using Arr<T>::push_back;	// Heap의 의도와는 다르므로 private로 비공개 처리

public:
	// Heap에서 자체적으로 정의한 push 함수를 이용해 데이터 추가
	void push(const T& _Data);

	// 가장 작은 값을 반환
	T Get(HEAP_MODE _Mode);
	// HEAP_MODE를 변경
	void SetMode(HEAP_MODE _Mode);
	
public:
	Heap()
		: m_Mode(HEAP_MODE::MIN)
	{
	}

	~Heap()
	{
	}
};

template<typename T>
inline void Heap<T>::push(const T& _Data) {
	// 상속받은 Arr의 push_back을 재활용
	Arr<T>::push_back(_Data);

	// 최근에 추가한 데이터를 부모와 비교해서 올린다.
	int curIdx = Arr<T>::size() - 1;

	// 반복문을 통해 비교하여 정렬
	// curIdx == 0은 루트
	// 현재 인덱스가 루트가 아니고, 추가된 Data가 부모 노드((현재인덱스 -1)/2) Data보다 작다면 while문 진입
	while (curIdx != 0 && Arr<T>::GetData(curIdx) < Arr<T>::GetData((curIdx - 1) / 2))
	{
		// 부모 노드와 현재노드의 값을 교환한다
		int temp = Arr<T>::GetData(curIdx);
		Arr<T>::GetData(curIdx) = Arr<T>::GetData((curIdx - 1) / 2);
		Arr<T>::GetData((curIdx - 1) / 2) = temp;

		// 현재 데이터 인덱스를 부모 위치로 변경한다
		curIdx = (curIdx - 1) / 2;
	}
}

template<typename T>
inline T Heap<T>::Get(HEAP_MODE _Mode)
{
	// 예외처리
	// Arr에 데이터가 아예 없는 상태에는 동작 X
	assert(Arr<T>::size() > 0);

	// ========================
	// HEAP_MODE에 따른 분기 처리
	// ========================
	if (_Mode == MAX)	// MAX일 때는 루트가 최댓값
	
	else if (_Mode == MIN)	// MIN일 때는 루트가 최솟값


	// 1. 가장 작은 값을 반환한다.(루트는 없어짐)
	// index[0]에 있는 값을 미리 복사하고, Size를 -1
	T min = Arr<T>::GetData(0);

	// 2. 가장 마지막에 있는 데이터를 루트로 올림
	Arr<T>::GetData(0) = Arr<T>::back();
	
	// 배열 Size 감소
	Arr<T>::pop_back();
	
	int curIdx = 0;
	// 3. 루트로 올린 데이터를 제자리로 찾아갈 수 있도록 자식과 비교해서 내림
	while (1)
	{
		// 둘 중 더 작은 자식의 인덱스를 찾아야 한다.
		int leftChild = (curIdx * 2) + 1;
		int rightChild = (curIdx * 2) + 2;
		int minIdx = 0;

		// 자식 인덱스를 확인할때 인덱스가 총 Size보다 작은지 확인
		// 왼쪽 자식이 없으면 더 내려갈 수 없음, 왼쪽 -> 오른쪽 순으로 추가되기 때문
		if (Arr<T>::size() <= leftChild)
			break;

		// 오른쪽 자식이 없으면, 왼쪽자식을 기준으로 비교
		if (Arr<T>::size() <= rightChild)
			minIdx = leftChild;
		else
			// 3항 연산자로 left와 right 가 가리키는 값을 비교
			Arr<T>::GetData(leftChild) < Arr<T>::GetData(rightChild) ? minIdx = leftChild : minIdx = rightChild;

		// 두 자식 중, 더 작은 값과 현재 노드 값을 비교해서 자식이 더 크면 내려갈 필요가 없음
		if (Arr<T>::GetData(curIdx) < Arr<T>::GetData(minIdx))
			break;

		// 위 모든 조건을 만족하면 값을 교환
		T temp = Arr<T>::GetData(curIdx);
		Arr<T>::GetData(curIdx) = Arr<T>::GetData(minIdx);
		Arr<T>::GetData(minIdx) = temp;

		curIdx = minIdx;
	}

	return min;
}

template<typename T>
inline void Heap<T>::SetMode(HEAP_MODE _Mode) {

	if (_Mode == MAX)
		m_Mode = MAX;
	else if (_Mode == MIN)
		m_Mode = MIN;
}
