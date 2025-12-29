// CPP 배열과 반복문
#include <iostream>
#include <ctime>

int main()
{
	// 배열
	// 동일한 자료형으로 변수를 한번에 여러개 선언
	// 메모리 주소가 연속적으로 연결되어있다.
	{
		// 배열 초기화
		// 배열의 각 요소의 값을 앞에서부터 순서대로 지정하여 초기화가 가능
		// {}를  사용하며, 아무것도 없으면 0으로 초기화
		// {}를 사용하지 않으면 초기화 X
		int array[10] = {};
		int array2[20];

		int size = sizeof(array);
		array[9] = 100;
		// (*)배열 선언 시 사용하는 인덱스는 몇개의 자료형을 만들지를 나타내고
		// 배열 사용 시 0부터 사용하는 이유는 배열이름은 배열의 시작 주소이고,
		// 인덱스는 offset(상대거리)를 나타내기 때문에
		// ex) array[5] -> 시작주소에서 5만큼 떨어져있는 공간
		// 제자리를 표현하기 위해 0을 사용해주어야 한다.

	}

	// 반복문
	// for문, while문
	{
		// for (반복문 시작 시 딱 한번 수행_주로 초기화; 반복문의 조건; 반복문 1회 종료 시 실행;)
		for (int i = 0; i < 10; i++)	// 연산 시 전위, 후위를 의도에 맞게 표현
		{
			printf("Hello World_%d\n", i);
		}

		//for (double i = 0; i < 5; scanf_s("%lf", &i))

		for (double d = 0.1f; d < 10; d++)
		{
			printf("C++_%lf\n", d);
		}

		srand(time(NULL));
		for (int r = 0; r < 100; r = rand() % 100 + 1)
		{
			printf("r: %d\n", r);
		}

		// [*Lab_0] 반복문으로 *찍기
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0 + i; j < 10; j++)
			{
				printf("*");
			}
			printf("\n");
		}

		printf("\n");
		// [Lab_1] *로 마름모 만들기
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (j == 2)
					printf("*");
				else
					printf(" ");
			}
			printf("\n");
		}


	}
	// 증감연산자
	// ++, --
	// 전위, 후위에 따라 연산 우선순위가 다르다
	// 우선순위: 전위 > 후위

	// switch case문

	// (*)숏 서킷 룰

	// 비트 쉬프트 연산자
	// <<, >> 화살표가 가리키는 방향으로 n칸 비트를 밀어버림
	// 빈 공간은 0이 채워짐
	// << 2배증가, >> 2로 나눈 몫
	// 실수에서는 사용 불가
	// 쉬프트는 RGB표현에서 사용 ex) <windows.h> RGB 매크로 함수

	return 0;
}