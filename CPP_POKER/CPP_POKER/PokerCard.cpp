#include "PokerCard.h"
#include <iostream>

int PokerCard::PokerCheck(int* _selectCard, bool isCheck) {
	// 만약 main에서 isCheck가 true가 되지 않았다면
	// 검사 조건이 불충분한데 함수가 호출된것이므로 경고 메시지 출력

	if (!isCheck)
	{
		std::cout << "Not Poker Check Condition" << std::endl;
		return 1;
	}

	// 족보 검사 로직
	// 계산을 위한 배열 선언 후, _selectCard 그대로 복사
	int tempNumCards[SELECT_CARD_LIMIT] = { };
	for (int i = 0; i < SELECT_CARD_LIMIT; i++)
	{
		tempNumCards[i] = _selectCard[i];
	}

	// 같은 숫자가 몇개 있는지 카운팅하는 변수
	// 표현 숫자가 0부터 5까지만 필요하므로, unsigned char 사용
	// _2는 FullHouse 조건문에 사용
	unsigned char sameNumCount_1 = 0;
	unsigned char sameNumCount_2 = 0;

	// 가장 높은 족보부터 조건문 우선 검사
	// HIGH_CARD 조건
	// 5장의 손에 같은 숫자를 가진 카드가 없어야함
	// 만약 HIGH_CARD에서도 등급을 매기려면 숫자번호를 반환하는 것으로 구현

	// 패에 같은 숫자카드가 얼마나 있는지 확인하는 로직은
	// 문양값을 제외한 숫자번호를 이용해서 판별하기
	int divided = 1;

	// 숫자번호를 받고 문양 숫자(1~4)를 나눈 값을 다시 저장
	for (int i = 0; i < SELECT_CARD_LIMIT; i++)
	{
		while (divided <= 4)
		{
			if (tempNumCards[i] == 0)
				break;

			tempNumCards[i] = tempNumCards[i] / divided;
			if (1 <= tempNumCards[i] && 13 >= tempNumCards[i])
			{
				break;
			}
			else
			{
				divided++;
			}
		}
	}

	for (int i = 0; i < SELECT_CARD_LIMIT; i++)
	{
		// 현재 카드와 다음 순서에 있는 카드의 숫자가 같은지 판별
		if (i != 4 && tempNumCards[i] == tempNumCards[i + 1])
			sameNumCount_1++;
	}

	// 같은 카드숫자가 얼마나 있는지 판별하고, 조건문을 통해 알맞은 값을 반환
	// 만약 같은 숫자 카드가 없다면, 해당 족보는 HIGH_CARD

	//	HIGH_CARD(0~) , ONE_PAIR , TWO_PAIRS , THREE_OF_A_KIND ,
	//	STRAIGHT , FLUSH , FULL_HOUSE , FOUR_OF_A_KIND , STRAIGHT_FLUSH(~8) 
	//  (괄호 안 숫자는 정수 값, 오른쪽으로 갈수록 +1 증가)

	if (sameNumCount_1 == 4)
		return 4;
	else if (sameNumCount_1 == 3)
		return 3;
	else if (sameNumCount_1 == 2)
		return 2;
	else if (sameNumCount_1 == 1)
		return 1;
	else if (sameNumCount_1 == 0)
		return 0;

	return 100;
}

void PokerCard::SortCards(int* _sCard) {
	// selectCard를 받아, 값을 오름차순으로 정렬
	
	int min = _sCard[0];
	int Idx = 0;
	for (int i = 0; i < SELECT_CARD_LIMIT; i++)
	{
		min = _sCard[i];
		for (int j = 0 + i; j < SELECT_CARD_LIMIT; j++)
		{
			if (j >= SELECT_CARD_LIMIT)
				break;

			if (min > _sCard[j])
				min = _sCard[j];

			Idx = j;
		}
		int temp = _sCard[i];
		_sCard[i] = min;
		_sCard[Idx] = temp;
		Idx = 0;
	}
}