#pragma once
#include <cassert>

template<typename T>
class DynamicArr
{
private:
	T* m_Data;		// 힙 영역에 저장된 데이터를 가리키는 포인터
	int		m_Capacity;	// 저장 가능한 데이터 개수
	int		m_Size;		// 현재 데이터 저장 개수

public:
	void push_back(const T& _Data);
	T& GetData(int _Index);
	T& operator[](int _Index);
	int size() { return m_Size; }

	// 미리 m_Capacity 를 확보해둔다.
	void reserve(int _Size);

	// 미리 m_Size 를 확보해둔다.
	void resize(int _Size);

	// =========
	// TODO 1224:
	// 입력으로 들어온 다른 배열과 내용물을 교환
	void swap(DynamicArr<T>& _Other);

	// 동적배열끼리 대입(저장하고 있는 데이터가 같아져야 한다.)
	DynamicArr<T>& operator = (const DynamicArr<T>& _Other);
	// =======================================


	// ==========================================
	// 내부 클래스 iterator에 시작 주소를 반환하는 함수
	// 객체가 이 함수를 호출해야함
	// =======================
	class iterator;	// 전방 선언, iterator class가 밑에 있기에 컴파일러한테 미리 알려줌
	iterator begin()
	{
		iterator iter(this, 0);	// this의 작동방식을 생각하기
		return iter;
		//retrun iterator(this, 0);	// 이름없는 객체, 위 코드를 한줄로 줄일 수 있음
	}
	// .end()도 구현해보기
	iterator end()
	{
		return iterator(this, -1);	// -1 인덱스를 전달 
	}

public:
	DynamicArr();
	// ==========
	// TODO: 1224
	// 복사 생성자
	DynamicArr(const DynamicArr<T>& _Other);
	// =====================================
	~DynamicArr();

// ==========
// TODO 1223: 
// 내부 클래스로 iterator 구현하기
// ============================
public:
	class iterator
	{
	private:
		// 절대위치가 아닌 상대위치를 활용한다는 개념으로 접근
		DynamicArr<T>* mOwner;	
		int mIdx;	// -1 마지막 다음(ebd) 를 가리키는 상황
	public:
		// * 연산자 오버로딩
		T& operator*()
		{
			// Out of Range 예외처리
			// iterator가 제대로 컨테이너를 가리키고 있어야하고, mIdx가 -1가 아니여야함 (-1은 end())
			assert(nullptr != mOwner && mIdx != -1);

			// mOwner가 가리키고 있는 DynamicArr의 m_Data에 접근
			return mOwner->m_Data[mIdx];
		}
		// ++ 연산자 오버로딩
		iterator& operator++()
		{	
			// 예외처리
			assert(mIdx != -1);

			// 현재 mOwner가 가리키는 컨테이너의 mIdx를 하나 증가
			++mIdx;
			// 예외처리
			if (mOwner->m_Size <= mIdx)
			{
				mIdx = -1;	// end iterator로 만들기
			}

			return *this;
		}
		// 후위 ++ 연산자 오버로딩
		// 인자로 int 하나를 받게 하면 후위 연산자 오버로딩을 하기로 약속
		iterator operator++(int _Num)
		{
			// main에서 수동호출 할때, ()에 int값을 주면 후위버전으로 호출
			// 직접구현한다면 연산자 우선순위의 작동방식을 고려

			// 복사 생성자
			// 지역에 임시 iterator를 만들고, 호출한 자신을 복사
			iterator copyIter(*this);

			// 호출한 자기 자신을++ (복사본과는 값이 다름)
			this->operator++();

			// 복사본을 리턴하는 방식으로 후위 연산자와 동작 원리가 비슷해짐
			return copyIter;
		}

		// ==========
		// TODO 1224: 
		// -- 전위, 후위 연산자 실습
		iterator& operator--()
		{
			// 예외처리
			assert(nullptr != mOwner && mIdx != -1);
			
			if (mIdx <= 0)
			{
				mIdx = -1;
			}
			else 
			{
				--mIdx;
			}

			return *this;
		}

		iterator operator--(int _Num)
		{
			iterator copyIter(*this);
			this->operator--();

			return *this;
		}
		// ===========================

	public:
		iterator() : mOwner(nullptr), mIdx(-1) {}	// mIdx가 아무것도 가리키지 않게 -1로 설정

		// 생성자 오버로딩
		iterator(DynamicArr<T>* _Owner, int _Idx) : mOwner(_Owner), mIdx(_Idx) {}

		// 소멸자가 호출되도 DynamicArr이 지워지면 안됨
		// iterator는 DynamicArr을 보조해주는 역할
		~iterator() {}
	};

};

template<typename T>
DynamicArr<T>::DynamicArr()
	: m_Data(nullptr)
	, m_Capacity(0)
	, m_Size(0)
{
}

template<typename T>
DynamicArr<T>::DynamicArr(const DynamicArr<T>& _Other)
{

}

template<typename T>
DynamicArr<T>::~DynamicArr()
{
	if (nullptr != m_Data)
	{
		delete[] m_Data;
	}
}

template<typename T>
void DynamicArr<T>::push_back(const T& _Data)
{
	if (m_Capacity <= m_Size)
	{
		// 데이터가 처음 입력되는 경우
		if (m_Capacity == 0)
		{
			// 기본 공간을 2칸을 확보한다.
			m_Capacity = 2;
			m_Data = new T[m_Capacity];
		}

		// 데이터가 이미 여러개 입력 되어있는 경우
		else
		{
			reserve(m_Capacity * 2);
		}
	}

	m_Data[m_Size++] = _Data;
}

template<typename T>
T& DynamicArr<T>::GetData(int _Index)
{
	return m_Data[_Index];
}

template<typename T>
T& DynamicArr<T>::operator[](int _Index)
{
	return m_Data[_Index];
}

template<typename T>
void DynamicArr<T>::reserve(int _Size)
{
	// 이미 보유한 데이터 개수보다도 적은 숫자로 공간 예약을 하려고 하면 무시한다.
	if (_Size <= m_Size)
	{
		return;
	}

	T* pNew = new T[_Size];

	for (int i = 0; i < m_Size; ++i)
	{
		pNew[i] = m_Data[i];
	}

	delete[] m_Data;

	m_Data = pNew;

	m_Capacity = _Size;
}

template<typename T>
void DynamicArr<T>::resize(int _Size)
{
	if (m_Capacity < _Size)
	{
		reserve(_Size);
	}

	m_Size = _Size;
}

template<typename T>
void DynamicArr<T>::swap(DynamicArr<T>& _Other)
{

}

template<typename T>
DynamicArr<T>& DynamicArr<T>::operator=(const DynamicArr<T>& _Other)
{


	return *this;
}
