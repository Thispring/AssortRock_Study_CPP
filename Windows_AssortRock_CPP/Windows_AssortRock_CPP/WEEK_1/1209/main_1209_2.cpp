// CPP 연산자
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	// 논리 연산자
	// !, &&, ||

	// [Lab_0]
	// 놀이기구 탑승 제한 프로그램(키 160이상, 나이 13세 이상)
	//{
	//	int age;
	//	float height;
	//	cout << "나이와 키를 입력하세요" << endl;
	//	cin >> age >> height;

	//	int isTrue = height >= 160 && age >= 13;

	//	if (isTrue != 0)
	//		cout << "탑승 가능" << endl;
	//	else
	//		cout << "탑승 불가" << endl;
	//}

	// (*)false && true(연산 X), true || false(연산 X)


	// 조건문
	// 참 or 거짓을 이용해서 코드의 흐름을 제어한다.
	// if else 문, if else if else 문
	// (*)앞에 조건이 성공하면, 검사하지 않는다.
	// 의도에 맞게 조건문을 설정

	// 콘솔 창(cmd) 입출력
	{
		int Data = 0;
		scanf("%d", &Data);
		printf("%d\n", Data);
	}


	return 0;
}

// 단축키
// Ctrl + K, C		: 지정한 곳 전체주석
// Ctrl + K, U		: 지정한 곳 주석해제