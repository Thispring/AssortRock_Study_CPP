// CPP 구조체
#include <iostream>

// 구조체
// 사용자 정의 자료형
// 프로그래머가 직접 설계하고 만드는 자료형
struct My_Type
{
	int i;
	float f;
};

struct Other_Type
{
	My_Type mt;	// 다른 구조체를 자신의 멤버 변수로 선언이 가능
	Other_Type* otp;	// 자기 참조 구조체
	char ch;
};

typedef int My;	// typedef 키워드를 통해 내가 만든 이름으로 자료형 선언 가능
My name = 123;

// C++ 문법에서 구조체에 typedef 문법이 포함
// C에서는 typedef이 없다면 struct가 포함되어야 사용 가능
typedef struct My_Define_Type {
	long num;
} Define;

int main()
{
	My_Type t = { 1, 2 };	// 배열과 같은 방법으로 초기화 할 수 있다.
	t.i = 10;
	t.f = 3.14;

	Define df;
	df.num = 1;

	Other_Type ot;
	ot.ch = 1;
	ot.otp = &ot;
	ot.otp->mt.f = 3.14;
	ot.otp->mt.f *= 2;
	std::cout << ot.mt.f << std::endl;

	return 0;
}