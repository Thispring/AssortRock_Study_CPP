#pragma once

#include "Arr.h"

enum HEAP_MODE
{
	MIN,
	MAX,
};


template<typename T>
class Heap
	: public Arr<T>
{
private:
	HEAP_MODE	m_Mode;

protected:
	// 동적배열(Arr) 에서 제공하는 데이터 추가함수를 비공개처리
	using Arr<T>::push_back; 
public:
	// Heap 에서 자체적으로 정의한 push 함수를 이용해서 데이터 추가
	void push(const T& _Data);

	// 가장 작은값을 반환해준다.
	T Get();

	void SetMode(HEAP_MODE _Mode);


public:
	Heap()
		: m_Mode(HEAP_MODE::MIN)
	{}

	~Heap()
	{}
};

template<typename T>
void Heap<T>::push(const T& _Data)
{
	// 데이터를 추가한다.
	// 부모클래스 Arr 에 구현되어있는 push_back 을 재활용해서, 데이터를 가장 뒤에 채운다.
	Arr<T>::push_back(_Data);

	// 최근에 추가한 데이터를 부모와 비교해서 올린다.
	int CurIdx = Arr<T>::size() - 1;

	// 루트 노드가 아니고, 
	while (CurIdx != 0 && Arr<T>::GetData(CurIdx) < Arr<T>::GetData((CurIdx - 1) / 2))
	{
		// 부모 노드와 현재노드의 값을 교환한다.
		int Temp = Arr<T>::GetData(CurIdx);
		Arr<T>::GetData(CurIdx) = Arr<T>::GetData((CurIdx - 1) / 2);
		Arr<T>::GetData((CurIdx - 1) / 2) = Temp;

		// 현재 데이터 인덱스를 부모 위치로 변경한다.
		CurIdx = (CurIdx - 1) / 2;
	}
}

template<typename T>
T Heap<T>::Get()
{
	// 데이터가 최소 1개 이상 있어야 한다.
	assert(Arr<T>::size() > 0);

	// 가장 작은값(루트 == 0번 인덱스) 을 복사해둔다.
	T Data = Arr<T>::GetData(0);

	// 가장 뒤에있는 데이터를 루트로 복사
	Arr<T>::GetData(0) = Arr<T>::back();

	// 맨 뒤 데이터를 제거
	Arr<T>::pop_back();

	// 루트로 올린 데이터를 제자리를 찾아갈 수 있도록 자식과 비교해서 내린다.
	int CurIdx = 0;
	while (true)
	{
		// 왼쪽, 오른쪽 자식 인덱스, 둘중 더 작은 자식의 인덱스를 찾아야 한다.
		int LeftChild = CurIdx * 2 + 1;
		int RightChild = CurIdx * 2 + 2;
		int MinIdx = 0;

		// 왼쪽 자식이 없으면, 더 내려갈 수 없다.
		if (Arr<T>::size() <= LeftChild)
			break;

		// 오른쪽 자식이 없으면, 두 자식중 왼쪽 자식이랑 비교한다.
		if (Arr<T>::size() <= RightChild)
			MinIdx = LeftChild;
		else
			Arr<T>::GetData(LeftChild) < Arr<T>::GetData(RightChild) ? MinIdx = LeftChild : MinIdx = RightChild;

		// 두 자식중, 더 작은 값과, 현재 노드 값을 비교해서, 자식이 더 크면, 내려갈 필요가 없다.
		if (Arr<T>::GetData(CurIdx) < Arr<T>::GetData(MinIdx))
			break;

		T Temp = Arr<T>::GetData(CurIdx);
		Arr<T>::GetData(CurIdx) = Arr<T>::GetData(MinIdx);
		Arr<T>::GetData(MinIdx) = Temp;

		// 현재 인덱스를 자식인덱스로 교환해서 계속 내려가는 작업을 반복한다.
		CurIdx = MinIdx;
	}

	// 가장 작은 값을 반환한다.
	return Data;
}

template<typename T>
void Heap<T>::SetMode(HEAP_MODE _Mode)
{

}
