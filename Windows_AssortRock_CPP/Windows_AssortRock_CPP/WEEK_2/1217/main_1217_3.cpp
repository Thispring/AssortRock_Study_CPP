// C++ 연산자 오버로딩
#include <iostream>

class MyClass
{
private:
	int mI;
	float mF;

public:
	// 연산자를 사용자가 원하는 기능으로 오버로딩이 가능
	// 멤버 함수로 오버로딩을 구현
	// 실제로는 멤버 함수를 호출하여 작동하는 원리
	
	// 컴파일러가 자동으로 만드는 디폴트 대입 연산자
	void operator = (const MyClass& other)	
	// 매개변수를 클래스의&를 사용하는 이유:
	// 포인터를 사용해도 동일하게 구현이 가능하지만
	// 사용 시 &을 붙여서 사용해야 하기 때문에 목적에 맞지 않기때문에,
	// 클래스이름을 사용해서 구현할 시, 주소 참조가 아니기 때문에
	// 자기 자신의 클래스만큼 복사해야하는 비용이 발생함
	{
		mI = other.mI;
		mF = other.mF;
	}

	// << 연산자 원본 기능
	MyClass& operator << (const char* str)
	{
		printf(str);
		return *this;
	}

};

int main()
{
	MyClass a;

	a << "hello" << "\n" << "world";

	return 0;
}