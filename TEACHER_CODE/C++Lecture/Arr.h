#pragma once

#include <assert.h>

template<typename T>
class Arr
{
private:
	T*		m_Data;		// 힙 영역에 저장된 데이터를 가리키는 포인터
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

	class iterator;
	iterator begin()
	{
		return iterator(this, 0); // 이름없는 객체
	}

	iterator end()
	{		
		return iterator(this, -1); // 이름없는 객체
	}


public:
	Arr();
	~Arr();

public:
	class iterator
	{
	private:
		Arr<T>* m_Owner;
		int		m_Idx;   // m_Owner 가 nullptr 이 아니면서, m_Idx 이 -1, 마지막의 다음(end) 를 가리키는 상황

	public:
		T& operator*()
		{
			// iterator 가 데이터를 보유하고 있는 컨테이너를 알고있어야 하고,
			// index 가 -1 이 아니어야 한다.
			assert(nullptr != m_Owner && m_Idx != -1);

			return m_Owner->m_Data[m_Idx];
		}

		void operator++()
		{
			assert(-1 != m_Idx);
			
			++m_Idx;

			if (m_Owner->m_Size <= m_Idx)
			{
				m_Idx = -1;
			}			
		}

		void operator++(int _Num)
		{

		}

	public:
		iterator()
			: m_Owner(nullptr)
			, m_Idx(-1)
		{
		}

		iterator(Arr<T>* _Owner, int _Idx)
			: m_Owner(_Owner)
			, m_Idx(_Idx)
		{
		}

		~iterator()
		{
		}
	};
};

template<typename T>
Arr<T>::Arr()
	: m_Data(nullptr)
	, m_Capacity(0)
	, m_Size(0)
{
}

template<typename T>
Arr<T>::~Arr()
{
	if (nullptr != m_Data)
	{
		delete[] m_Data;
	}
}

template<typename T>
void Arr<T>::push_back(const T& _Data)
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
T& Arr<T>::GetData(int _Index)
{
	return m_Data[_Index];
}

template<typename T>
T& Arr<T>::operator[](int _Index)
{
	return m_Data[_Index];
}

template<typename T>
void Arr<T>::reserve(int _Size)
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
void Arr<T>::resize(int _Size)
{
	if (m_Capacity < _Size)
	{
		reserve(_Size);
	}	

	m_Size = _Size;
}
