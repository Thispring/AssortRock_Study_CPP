// C++ 유저 입출력 프로그램(동적할당)

// 유저 데이터를 소스코드에만 저장한다면
// 프로그램이 종료되면 데이터가 사라짐
// -> 유저의 데이터를 '저장'해야 다시 사용이 가능
// -> 파일 입출력을 통해 데이터를 저장하고 불러올 수 있음

// 유저 정보를 저장할 수 있는 구조체를 선언해
// 데이터를 저장하는 프로그램 만들기

#include <stdio.h>
#include <stdlib.h>

// [Lab_0]
// 두 문자열을 비교하는 cmp함수 구현해보기
int StrCmp(const char* scr1, const char* src2)
{
	// scr1이 사전순서가 높으면 -1, scr2가 높으면 1
	// 두 문자열이 같다면 0 반환

	return 0;
}


// 스택(함수)
// 데이터
// 코드(ROM)
// 힙(동적할당)

int main()
{
	// Memory Allocate
	// 동적할당함수 malloc
	// malloc은 받은 인수만큼 힙 영역에
	// 바이트 단위로 메모리 공간을 생성하고 그 시작주소를 반환
	// 
	// 개발자가 타입에 상관없이 사용할 수 있도록 void*를 반환하기에 
	// 사용할 타입으로 형변환을 하여 사용
	int* pInt = (int*)malloc(4);
	char* pChar = (char*)malloc(4);


	// 동적할당 공간을 해제하는 함수
	// 해제하지 않으면 메모리 누수 발생
	free(pInt);
	free(pChar);

	return 0;
}