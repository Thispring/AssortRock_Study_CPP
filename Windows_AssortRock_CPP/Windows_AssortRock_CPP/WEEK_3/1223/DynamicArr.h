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

	// ==========
	// TODO 1224: 
	// erase와 insert 함수 구현하기

	// iterator 가 가리키는 요소를 삭제하고, 삭제한 데이터 다음 요소를 가리키는 iterator 를 만들어서 반환
	iterator erase(const iterator& _iter);
	// iterator 가 가리키는 지점에 데이터를 추가한다.
	void insert(const iterator& _iter, const T& _data);

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
		friend class DynamicArr<T>;	// DynamicArr가 내부 클래스인 iterator의 접근을 허용하는 friend 선언
	private:
		// 절대위치가 아닌 상대위치를 활용한다는 개념으로 접근
		DynamicArr<T>* mOwner;	
		int mIdx;	// -1 마지막 다음(end) 를 가리키는 상황

	public:
		// ==========
		// TODO 1223:
		// 비교 연산자 오버로딩
		// =================
		bool operator ==(const iterator& _Other)
		{
			return mOwner == _Other.mOwner;
		}
		
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
			assert(nullptr != mOwner && mIdx != 0);
			
			// end일때 예외처리, 마지막 데이터를 가리켜야한다.
			if (mIdx == -1)
			{
				// 데이터가 아예 없었을 때
				assert(mOwner->m_Size != 0);
				mIdx = mOwner->m_Size - 1;
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

// 복사 생성자
template<typename T>
DynamicArr<T>::DynamicArr(const DynamicArr<T>& _Other)
	: m_Data(nullptr)
	, m_Capacity(0)
	, m_Size(0)
{
	// 이미 구현된 = 연산자 오버로딩 함수를 호출하여 값을 복사
	(*this) = _Other;
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
	// 호출자의 값을 백업해둘 Temp변수 선언
	int Temp = m_Size;
	m_Size = _Other.m_Size;
	_Other.m_Size = Temp;

	Temp = m_Capacity;
	m_Capacity = _Other.m_Capacity;
	_Other.m_Capacity = Temp;

	// 포인터 pData를 교환하지 않으면?
	// 값 교환이 이루어지지 않음
	T* pData = m_Data;
	m_Data = _Other.m_Data;
	_Other.m_Data = pData;
}

template<typename T>
DynamicArr<T>& DynamicArr<T>::operator=(const DynamicArr<T>& _Other)
{
	// 만약 호출자의 capacity가 인자로 받아온 객체의 capacity보다 작다면
	// 인자로 받아온 객체의 크기만큼 공간 늘리기
	if (m_Capacity < _Other.m_Capacity)
	{
		// reserve 함수를 이용, 매개변수 객체의 사이즈만큼
		reserve(_Other.m_Size);
	}

	// 매개변수 객체의 현재 들고있는 데이터 크기만큼 반복
	for (int i = 0; i < _Other.m_Size; i++)
	{
		m_Data[i] = _Other.m_Data[i];
	}

	// 사이즈도 동일하게 복사
	m_Size = _Other.m_Size;

	return *this;
}

template<typename T>
typename DynamicArr<T>::iterator DynamicArr<T>::erase(const iterator& _iter)
{

}

template<typename T>
typename void DynamicArr<T>::insert(const iterator& _iter, const T& _data)
{
	// _iter와 this가 동일한지 확인
	assert(this == _iter.mOwner);

	// _iter가 가리키는 컨테이너의 Size와 Capacity를 비교해 빈 공간이 있는지 확인
	if (m_Size >= m_Capacity)
	{
		// 이 조건에 걸린다면, 빈 공간이 없다는 뜻
		reserve(m_Capacity * 2);
	}
	
	// 컨테이너에 있는 데이터를 뒤로 한 칸씩 미는 로직
	// 현재 몇번째 인덱스인지 확인하고, 인덱스 부터 Capacity까지 반복문을 통해
	// 기존에 있던 데이터를 한 칸씩 뒤로 밀기
	
	int LoopIdx = m_Size - _iter.mIdx;

	for (int i = 0; i < LoopIdx; i++)
	{
		m_Data[m_Size - i] = m_Data[m_Size - 1 - i];
	}

	// 뒤로 한 칸씩 모두 민 다음, 받아온 데이터를 현재 인덱스에 저장
	m_Data[_iter.mIdx] = _data;
	// 데이터 이동이 모두 성공하면 Size증가
	++m_Size;
	
}
