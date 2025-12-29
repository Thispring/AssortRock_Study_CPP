// C++ 클래스와 동적할당
#include <iostream>
#include <stdlib.h>

class MyClass
{
private:
	int mArr[10];
public:
	MyClass()
		: mArr{}
	{
		std::cout << "MyClass constructor" << std::endl;
	}
	~MyClass() { std::cout << "MyClass destructor" << std::endl; }

};

int main()
{
	MyClass my;
	// 클래스를 malloc함수로 동적할당 할 경우
	// 클래스의 바이트 크기만큼의 공간이 필요하다.

	// myP에 malloc으로 힙 영역에 동적할당 할 경우, 클래스의 생성자와 호출자가 만들어지지 않는다.
	// 객체를 힙 영역에서 사용할 수 없다.
	MyClass* myP = (MyClass*)malloc(sizeof(MyClass));

	free(myP);

	// C++ 문법에서 new를 만들어 객체를 힙 영역에서 사용할 수 있다.
	MyClass* myRP = new MyClass;
	// new로 동적할당한 공간을 해제는 delete 키워드
	delete myRP;

	// malloc: 전달받은 크기만큼 동적할당을 하고 void*을 반환
	// new: 전달받은 자료형 정보의 크기만큼 동적할당을 하고 생성자 호출

	// MyClass 동적할당을 3번 진행
	MyClass* pArrMy = new MyClass[3];
	pArrMy[0];
	pArrMy[1];
	pArrMy[2];

	delete[] pArrMy;

	return 0;
}