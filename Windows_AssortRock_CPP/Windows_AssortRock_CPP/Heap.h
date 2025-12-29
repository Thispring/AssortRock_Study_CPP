#pragma once

// https://gmlwjd9405.github.io/2018/05/10/data-structure-heap.html

class Heap
{
private:
	int* m_Data;
	int m_Capacity;
	int m_Size;

public:
	void push(const int& _Data);

public:
	Heap() : m_Data(nullptr), m_Capacity(0), m_Size(0) {}
	~Heap() { if (m_Data != nullptr) delete[] m_Data; }
};