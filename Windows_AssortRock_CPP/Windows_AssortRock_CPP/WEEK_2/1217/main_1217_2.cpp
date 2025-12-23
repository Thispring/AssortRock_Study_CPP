// C++ 래퍼런스
#include <iostream>

class Test
{

public:
	Test& Output() { printf("Output\n"); return *this; }
	// 생성자, 소멸자는 프로그래머가 구현하지 않아도, 기본형태로 컴파일러에 의해서 구현이 된다.
	// 객체가 생성될 때 생성자가 호출되어야만 하고, 소멸할때는 소멸자가 호출되어야 하는 규칙을 지키기 위해

	// 기본생성자가 아닌 생성자를 선언했을 때,
	// 기본으로 객체생성 시 오류가 발생
	Test() {}
	~Test() {}
};

int main()
{
	// 래퍼런스(참조)
	// C++에 추가된 개념

	// C에서는 포인터를 이용해 활용
	int number = 0;
	int* pInt = &number;
	*pInt = 100;

	// C++ 래퍼런스 변수
	int& iRef = number;
	iRef = 200;
	iRef = 300;
	
	// 래퍼런스의 장점은
	// 포인터의 주소연산 표현 문법을 사용하지 않아도
	// 동일한 기능을 제공하기에, 가독성과 생산성이 좋다.
	
	Test t;
	t.Output().Output().Output();


	return 0;
}