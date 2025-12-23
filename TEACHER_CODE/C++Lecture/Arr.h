#pragma once

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


public:
	Arr();
	~Arr();
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
			T* pNew = new T[m_Capacity * 2];

			for (int i = 0; i < m_Size; ++i)
			{
				pNew[i] = m_Data[i];
			}

			delete[] m_Data;

			m_Data = pNew;

			m_Capacity *= 2;
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

}

template<typename T>
void Arr<T>::resize(int _Size)
{

}
