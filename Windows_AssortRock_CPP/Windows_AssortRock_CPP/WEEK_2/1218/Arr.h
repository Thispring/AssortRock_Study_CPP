#pragma once
class Arr
{
private:
	int* m_Data;
	int m_Capacity;
	int m_Size;
public:
	// 데이터를 끝에서 부터 집어 넣는 함수
	void push_back(const int& data);
	// 인덱스 번호를 받아 해당 인덱스에 있는 데이터 반환
	int& GetData(int _Index);
	// GetData와 동일한 기능으로 연산자 오버로딩으로 구현
	int& operator[](int _Index);
public:
	Arr();
	~Arr();
};

