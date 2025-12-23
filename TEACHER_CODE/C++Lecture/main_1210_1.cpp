#include <stdio.h>
#include <windows.h>

int main()
{	
	// 배열 - 동일한 자료형으로 변수를 한번에 여러개 선언
	// 1. 메모리가 연속되어있다

	// 배열 초기화
	// 배열의 각 요소의 값을 앞에서부터 순서대로 초기화때 지정해 줄 수 있다.
	// 적지 않은 부분은 모두 0으로 초기화 된다 ==> 아무것도 적지 않으면 모두 0으로 초기화 하겠다는 뜻
	int Array[10] = {1, 2};

	// 배열을 선언 후에 각 요소에 접근할때 배열의 이름 뒤에 인덱스를 붙여서 접근한다.
	// 인덱스는 0부터 시작하며, 0이 첫번째이다
	// 배열의 이름은 시작 주소다.
	// 인덱스는 Offset 개념
	Array[0] = 10;
	Array[1] = 20;
	Array[2] = 30;
	Array[9] = 100;
	//Array[10] = 110;

	// sizeof 키워드에 배열의 이름을 넣으면, 배열 전체의 메모리 크기를 알 수 있다.
	int size = sizeof(Array);
	

	// 반복문
	//for ( 반복문 시작할때 딱 한번 수행됨 ; 반복문을 유지할 것인지 참 거짓 조건체크 ; 반복문을 1회 종료될 때 다마 매번 수행됨 );
	for (int i = 0; i < 10; i += 1)
	{
		Array[i] = i + 1;
		//printf("반복문 수행\n");
	}

	// 이중 반복문
	// * 찍기
	int Count = 5;
	for (int k = 0; k < Count; k += 1)
	{
		for (int i = 0; i < k+1; i += 1)
		{
			printf("*");
		}

		printf("\n");
	}

	
	Count = 100;
	for (int k = 0; k < Count; k += 1)
	{
		for (int i = 0; i < Count - k; i += 1)
		{
			printf("*");
		}

		printf("\n");
	}


	// 연산자
	// 증감 연산자
	// ++, --
	// 증감연산자 위치에 따라서 전치, 후치로 나뉨
	// 연산자 우선순위에 영향
	// 전치, 전위, 연산자 우선순위가 가장 빠르다
	// 후치, 후위, 연산자 우선순위가 가장 느리다
	int a = 0;
	a = a + 1;
	a += 1;
	++a;
	a++;

	// a == 4
	//int b = ++a + 2;
	int b = a++ + 2;

	


	for ( ;1;)
	{
		printf("원하는 작업을 선택하세요.\n");
		printf("1. 프로그램 종료\n");
		printf("2. 프로그램 종료\n");
		printf("3. 프로그램 종료\n");

		int input = 0;
		scanf_s("%d", &input);

		// 조건문
	/*	if (input == 1 || input == 2 || input == 3)
		{
			break;
		}
		else
		{
			printf("잘못된 선택입니다.\n");
		}*/

		bool IsBreak = false;
		switch (input)
		{
		case 1:
		case 2:
		case 3:
			IsBreak = true;
			break;
		default:
			printf("잘못된 선택입니다.\n");
			break;
		}

		if (IsBreak)
		{
			break;
		}
	}
			
	// 비트 연산자
	// &, |, ~, ^
	// 비트 쉬프트
	// >>, << 비트 이동
	// << 2배 증가
	// >> 2로 나눈 몫
	int j = 110;
	j <<= 1;
	j <<= 1;
	j >>= 1;

	// 비트 쉬프트 연산자는 실수 타입 데이터에는 사용 할 수 없다.
	float f = 1.11f;
	//f << 1;
	//RGB(110, 20, 189);

	int Arr[1000] = {50, 52};

	

	return 0;
}