// C++ 문자, 문자열, 리터럴
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// [Lab_0]
// 입력된 문자열이 몇개인지 알려주는 함수
int GetStrlen(const char* str)
{
	int index = 0;
	int len = 0;
	char ch = *(str + index);
	while (ch != '\0')
	{
		index++;
		len++;
		ch = *(str + index);
	}

	return len;
}

// [Lab_1]
// 문자열 복사 함수
// src가 가리키는 문자열에서 len의 숫자만큼 문자 dest가 가리키는 곳으로 복사
bool StrCpy(char* dest, const char* src, int len)
{
	int index = 0;
	char ch = 0;
	while (ch != '\0')
	{
		*(dest + index) = *(src + index);
		if (*(dest + index) == '\0')
			return 0;

		len--;
		index++;
	}

	return 1;

	// 성공 시 true 반환
	// 실패 시 false 반환
	// 실패조건: src 보다 dest의 문자배열이 짧은 경우
}

// [Lab_2]
// 문자열끝에 문자열을 이어 붙이는 함수, dest끝에서 src를 이어 붙이기
void StrCat(char* dest, const char* src)
{
	int index = 0;
	int strlen = 0;
	char ch = *(dest + strlen);
	while (ch != '\0')
	{
		ch = *(dest + strlen);
		if (ch == '\0')
			break;
		strlen++;
	}

	ch = *(src + index);
	while (ch != '\0')
	{
		ch = *(src + index);
		*(dest + strlen) = ch;
		strlen++;
		index++;
	}

	*(dest + strlen) = '\0';
	//return 1;

	// 성공 시 true 반환
	// 실패 시 false 반환
	// 실패조건: src 보다 dest의 문자배열이 짧은 경우
}

int main()
{
	// 컴퓨터에서 문자는 아스키 코드를 이용해
	// 숫자로 매칭시키기로 약속이 되어있다.
	// ex) a = 97, A = 65
	{
		int i = 67;
		char c = 57;
		i = 'a';
		c = 'a';
		// 자료형에 따라 아스키 코드 값에 대한 해석이 다르다.
		// char는 숫자와 매칭되는 문자를 같이 표현할 수 있고, 
		// 정수형은 문자를 표현할 수 없고 숫자만 표현할 수 있다.
	}

	// 문자열
	// 문자가 연속된 메모리 공간에 나열됨, 끝에 널문자가 존재

	// 리터럴
	// 문자열 중에서, 코드상에 작성된 문자여르 프로그램 시작 시, ROM(Read Only Memory) - 코드영역에 저장됨
	// 문자열의 원본역할을 수행
	// 리터럴은 값을 실행도중 변경할 수 없음
	// 실제 메모리에서 똑같은 문자열은 1개만 존재
	char name[10] = "abcdef";
	char name2[10] = "abcdef";

	// 리터럴의 시작주소를 받아옴
	const char* pString = "abcdef";

	// 문자열의 개수 + 1칸 더 여유가 있어야한다. <- 널문자가 들어갈 여유공간 1칸

	{
		int slen = GetStrlen("Hello");
		std::cout << slen << std::endl;
	}

	{
		char name[20] = "hello world";
		bool isCopy = StrCpy(name, "world", 4);
		for (int i = 0; i < 20; i++)
			std::cout << name[i];

		std::cout << std::endl;
	}

	{
		char name2[30] = "hello world";
		//bool iscat = false;
		StrCat(name2, "good bye");
		for (int i = 0; i < 30; i++)
			std::cout << name2[i];
	}

	// 구조체와 메모리 얼라인먼트
	// 구조체는 가장 큰 자료형을 기준으로 메모리가 생성되고
	// 자료형의 순서 및 크기 따라 구조체의 크기가 달라집니다.
	struct Test
	{
		short s;
		char c;
		int i;
	};

	struct Test2
	{
		short s;
		int i;
		char c;
	};

	int size = sizeof(Test);
	size = sizeof(Test2);
	// #pragma pack(1) 전처리기를 실행하면
	// 패딩비트를 1로 설정합니다.


	// 공용체
	union MyUnion
	{

	};

	return 0;
}
