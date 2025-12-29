#include <stdio.h>


// 타입 재정의하는 키워드
typedef int MY;



// 구조체
#include <Windows.h>

// 특정 자료형에 다른 네이밍을 부여함
//typedef


// 사용자 정의 자료형 - 프로그래머가 직접 설계하고 만드는 자료형
// 구조체 선언시 typedef 을 동시에 진행하는 이유
// C 에서는 구조체를 사용할 때 앞에 struct 를 꼭 붙여야 해서, struct 키워드를 포함한 구조체 전체 이름을
// 다른 이름으로 재정의 해서 편하게 사용하기 위함.
// C++ 에서도 해당 방식으로 구조체를 선언하면, C 문법도 동시에 만족하기 때문에, 
// 두 언어에서 범용적으로 사용할 구조체를 설계할때 사용함
typedef struct MY_TYPE
{
	int		i; // 맴버
	float	f;
} myType;

// 구조체 안에, 다른 구조체 자료형을 맴버로 선언할 수 있다.
struct MY_OTHER_TYPE
{
	MY_TYPE type;
	int     i;
};

struct MY_SUPER_TYPE
{
	MY_OTHER_TYPE	t;
	MY_TYPE			a;
};

int main()
{
	MY_SUPER_TYPE k = {};
	k.t.type.f;

	
	myType t = { 1, 2.22f}; // 초기화
	t.i = 10;				 // 대입
	t.f = 3.14f;			 // 대입

	MY_TYPE a = {2, 3.333f};
	a.i = 0;
	a.f = 0.f;


	MY i = 0;


	return 0;
}