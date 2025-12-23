#include "Arr.h"

Arr::Arr()
	: m_Data(nullptr),
	m_Capacity(0),
	m_Size(0)
{

}

Arr::~Arr() 
{
	if (m_Data != nullptr)
		delete[] m_Data;
}


// 데이터를 끝에서 부터 집어 넣는 함수
void Arr::push_back(const int& data)	// 상수 int의 레퍼런스를 매개변수로 받음
{
	int* temp;

	// 포인터 m_Data에 int크기 만큼 동적할당
	temp = new int;

	m_Data = temp;
	
	delete temp;

	m_Data[m_Size] = data;
	// 데이터 넣기에 성공하면 +1연산
	m_Size++;
}


//// 인덱스 번호를 받아 해당 인덱스에 있는 데이터 반환
//int& GetData(int _Index);
//// GetData와 동일한 기능으로 연산자 오버로딩으로 구현
//int& operator[](int _Index);