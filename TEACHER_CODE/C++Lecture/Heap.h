#pragma once


class Heap
{
private:
	int*	m_Data;
	int		m_Capacity;
	int		m_Size;

public:
	void push(const int& _Data);

public:
	Heap()
		: m_Data(nullptr)
		, m_Capacity(0)
		, m_Size(0)
	{}

	~Heap()
	{
		if(nullptr != m_Data)
			delete[] m_Data;		
	}
};

