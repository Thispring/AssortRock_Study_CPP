#include <iostream>

int Add(int a, int b)
{
	int c = a + b;
	return c;
}



class CTest
{
private:
	int		m_i;
	float	m_f;

public:
	void SetData(int _i, float _f)
	{
		m_i = _i;
		m_f = _f;
	}

	// 디폴트 대입 연산자
	CTest& operator = (const CTest& _Other)
	{
		m_i = _Other.m_i;
		m_f = _Other.m_f;

		return *this;
	}

	CTest operator + (const CTest& _Other)
	{
		CTest Temp;
		Temp.SetData(m_i + _Other.m_i, m_f + _Other.m_f);
		return Temp;
	}

public:
	CTest()
		: m_i(0)
		, m_f(0.f)
	{}

	// 디폴트 복사 생성자
	CTest(const CTest& _Other)
		: m_i(_Other.m_i)
		, m_f(_Other.m_f)
	{
	}
};

int main()
{
	int a = 10;
	int b = 20;
	int c = a + b;

	CTest t1;
	t1.SetData(10, 10.f);

	CTest t2;
	t2.SetData(20, 20.f);

	// 복사 생성자
	// 객체가 생성될때 생성자가 호출되어야 하고, 객체끼리 복사가 이루어 져야 하기 때문에
	// 기본생성자로 초기화한 후 대입연사자를 호출시키는 두번에 걸친 동작 수행은 최적화로 보기 어렵다.
	// 따라서 컴파일러는 동일한 효과를 발생시키면서 한번에 처리가 가능한 복사생성자 호출로 컴파일한다.
	CTest t3 = t2;
	 
	// 명시적은 복사생성자 호출
	//CTest t3(t2);

	// 기본생성자로 객체를 생성시킨 뒤에, 복사를 진행하는 구문
	//CTest t3;
	//t3 = t2;

	CTest t4 = t1 + t2;

	CTest t5 = std::move(t1);


	return 0;
}