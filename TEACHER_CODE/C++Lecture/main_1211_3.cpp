#include <stdio.h>

#include "Math.h"



// 변수 종류
// 1. 지역변수 - 스택 영역
// 2. 전역변수 - 데이터 영역, 프로그램 실행 도중 상시 유지되는 변수
// 3. 정적변수 - 데이터 영역, static, 전역변수의 특징을 기본적으로 지님, 선언된 곳에서만 사용가능
//            - 함수 안에 선언한 경우, 선언한 함수 안에서만 접근 가능
// 4. 외부변수 - 근본은 전역변수기 때문에 데이터 영역을 사용, extern 선언을 이용해서 다른 파일에서도 
//              사용할 수 있게된 전역변수

// 정적변수 - 전역변수 앞에 붙인 경우
static int Global_1 = 0;

// 전역변수
int Global_2 = 0;


void TestFunc()
{
	Global_1 = 100;
}

int main()
{
	Global_1 = 200;
	Extern = 100;

	Mul(10, 10);


	for (int i = 0; i < 10000; ++i)
	{
		Global_1 = 100;
	}
	

	Extern = 100;

	return 0;
}


