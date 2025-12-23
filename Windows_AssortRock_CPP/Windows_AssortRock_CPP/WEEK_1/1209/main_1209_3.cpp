// CPP 연산자
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 가독성을 위해 16진수로 비트 상태 표현
#define BLEED 0x1
#define STUN 0x2
#define FROZEN 0x4
#define BURN 0x8
#define POISION 0x10
#define HEAL 0x40
#define DEX_UP 0x200

int main()
{
	// bool 자료형
	// 참과 거짓을 나타내는 자료형 (1byte)
	// bool 변수에 0과 1이 아닌 다른 숫자를 대입하고,
	// bool 변수를 다른 자료형에 대입할때
	// bool은 해당 숫자가 아닌 1을 저장
	// 다른 자료형에서는 1이 저장됨

	// 비트 연산자
	// &(곱), |(합), ^(XOR), ~(반전), <<(), >>()

	// 특정 비트값 제거
	// (*)
	// status &= ~COLD;
	// status ^= COLD;
	// 기능의 차이점 생각하기

	// [Lab_0]
	// 비트연산자를 활용하여, 상태이상 체크하는 프로그램
	{
		srand(time(NULL));
		unsigned int player = 0;

		// TODO: 2의 제곱 수를 무작위로 생성하여, 정의된 상태이상에 따라
		// 플레이어의 상태를 나타내는 기능 구현
		unsigned int status = rand() % 600 + 1;

		player |= STUN;
		player |= BURN;

		if (player == STUN)
			printf("Player is Stun!\n");
		else if (player == BURN)
			printf("Player is Burn!\n");
		else if (player == STUN + BURN)
			printf("Player is Stun & Burn!\n");
		else
			printf("\n");

		// TODO: 상태 이상을 해제하는 기능 구현

	}

	return 0;
}