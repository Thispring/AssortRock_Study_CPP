

// 구조체
struct MyType
{
	int		a;
	float	b;
	short   c;
};

// 포인터
// 자료형 * 변수명;
// 1. 자료형에 해당하는 주소만 받겠다.
// 2. 주소의 원본을 자료형으로 해석하겠다.


int main()
{
	// 포인터와 구조체
	MyType a = {};
	a.a = 10;
	a.b = 1.111f;
	a.c;

	// 구조체 타입 포인터로 원본 변수에 접근을 한 수에 다시 세부 맴버로 접근하기 위해서 . 연산자를 사용한다.
	MyType* pMyType = &a;
	(*pMyType).a = 20;
	(*pMyType).b = 2.222f;
	(*pMyType).c = 10;

	// 연산구문이 복잡하기 때문에, 구조체 포인터로 원본 구조체의 맴버까지 
	// 한번에 접근을 표현하는 -> 연산자가 있다.
	pMyType->a = 30;
	pMyType->b = 3.333f;
	pMyType->c = 40;


	// 1. 포인터 이해하기 
	char Array[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

	int* pInt = (int*) Array;

	pInt += 3;
		
	*((char*)pInt) = 100;
	

	// 1. 포인터 이해하기 
	short s = 257; // 257 이진수   0000 0001 0000 0001

	char* pChar = (char*) & s;

	char data = pChar[1];

	return 0;
}

