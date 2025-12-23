// C++ 구조체와 포인터

struct MyType
{
	int a;
	float f;
};

int main()
{
	MyType mt;
	// 구조체 주소를 저장하려면 자신이 선언한 구조체 포인터가 필요
	MyType* mtp;
	mtp = &mt;
	
	// 구조체 변수로 멤버 변수에 접근
	mt.a = 10;
	mt.f = 3.14;
	// 구조체 포인터로 멤버 변수에 접근
	mtp->a = 20;
	mtp->f = 6.28;

	// [Lab_0]
	// 포인터 이해하기
	char Array[20] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	int* pInt = (int*)Array;
	pInt += 3;
	*((char*)pInt) = 100;

	// [Lab_1]
	// 포인터 이해하기
	// s의 바이트 저장은 0000 0001 0000 0001 로 되어 있음
	short s = 257;
	char* pChar = (char*)&s;
	char data = *(pChar + 1);

	return 0;
}