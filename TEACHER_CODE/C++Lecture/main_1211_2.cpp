#include <stdio.h>

// 복사
#include "Math.h"

// 변수 종류
// 1. 지역변수 - 스택 영역
// 2. 전역변수 - 데이터 영역, 프로그램 실행 도중 상시 유지되는 변수
// 3. 정적변수 - 데이터 영역, static, 전역변수의 특징을 기본적으로 지님, 선언된 곳에서만 사용가능
//            - 함수 안에 선언한 경우, 선언한 함수 안에서만 접근 가능
// 4. 외부변수 - 데이터 영역, extern

// 메모리 영역
// 1. 스택 영역
// 2. 데이터 영역 - 프로그램 시작시 생성, 프로그램 종료시 해제
// 3. ROM(읽기 전용, 코드영역)
// 4. 힙 영역 - 동적할당을 통해서 프로그래머가 자유롭게 사용할 수 있는 메모리 영역
//            - 프로그래머가 직접 할당한 영역에 대한 메모리 해제를 신경써야 한다.

int Global = 0;

// 분할구현 - 헤더(.h) 와 파일(.cpp) 로 분할 구현

int TestFunc()
{
	// 지역변수
	int Count = 0;
	++Count;

	// 정적변수 - 데이터
	static int CallCount = 0;
	++CallCount;

	// 전역변수
	++Global;

	return 0;
}


int main()
{
	TestFunc();

	TestFunc();

	TestFunc();

	Global = 100;

	// 정적변수는 선언된 곳에서만 접근이 가능하다.
	//CallCount = 100;


	// 전처리기 - 컴파일(파일(cpp) 단위로 독립적으로 진행) - 링킹
	// Math.cpp 에 구현되어있는 Mul
	int result = Mul(22, 2);


	return 0;
}