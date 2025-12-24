#include "PokerCard.h"
#include <iostream>

void PokerCard::PokerCheck(int* _selectCard, bool isCheck) {
	// 만약 main에서 isCheck가 true가 되지 않았다면
	// 검사 조건이 불충분한데 함수가 호출된것이므로 경고 메시지 출력

	if (!isCheck)
	{
		std::cout << "Not Poker Check Condition" << std::endl;
		return;
	}

	// _selectCard 배열에 값이 5개가 모두 있는지 검사
	for (int i = 0; i < SELECT_CARD_LIMIT; i++)
	{
		if (_selectCard[i] == 0)
		{
			return;
		}
	}

	// 족보 검사 로직
	// 계산을 위한 배열 선언 후, _selectCard 그대로 복사
	int tempNumCards[SELECT_CARD_LIMIT] = { };
	for (int i = 0; i < SELECT_CARD_LIMIT; i++)
	{
		tempNumCards[i] = _selectCard[i];
	}

	int sameNumberCount = 0;

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
			sameNumberCount++;
	}

	// 만약 같은 숫자 카드가 없다면, 해당 족보는 HIGH_CARD
	if (sameNumberCount == 4)
		std::cout << "FOUR_OF_A_KIND" << std::endl;
	else if (sameNumberCount == 3)
		std::cout << "THREE_OF_A_KIND" << std::endl;
	else if (sameNumberCount == 2)
		std::cout << "TWO_PAIRS" << std::endl;
	else if (sameNumberCount == 1)
		std::cout << "ONE_PAIR" << std::endl;
	else if (sameNumberCount == 0)
		std::cout << "HIGH_CARD" << std::endl;

}

// enum으로 설정된 HandRank를 반환
int PokerCard::ReturnRank()
{
	return HandRank();
}
