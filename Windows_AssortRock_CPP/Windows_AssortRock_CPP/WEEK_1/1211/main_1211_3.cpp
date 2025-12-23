// CPP 변수 선언위치 및 사용범위 2

// 정적 전역 변수
// 선언된 곳에서만 접근할 수 있기에, 선언된 파일에서만 사용가능
static int Global = 1;

#include "Math.h"
#include <iostream>

int main()
{
	// ex변수는 컴파일타임에는 main.cpp에서 존재를 모름
	// extern 변수를 선언하지 않고 빌드 시 링크 에러가 발생
	// 만약 연결된 파일마다 같은 extern 변수가 있어도 링크 에러가 발생
	ex = 100;

	return 0;
}