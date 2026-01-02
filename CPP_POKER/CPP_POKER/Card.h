// Card 객체는 각자 고유의 문양과 번호를 부여받습니다. (중복없이)
// 현실의 플레잉카드 52장을 참고해 구현합니다.

#pragma once
#include "GameManager.h"

class Card
{
private:
	// 어떤 문양과 번호를 가지고 있는지 저장
	unsigned short number;
	unsigned short shape;

public:
	// 넘겨받은 카드의 숫자를 판별하여, 문양을 제외하고 카드가 어떤 숫자를 
	// 가지고 있는지 판별하여 문자열로 반환하는 함수
	const char* GetCardNumberName(int getCardNum);
public:
	Card()
		: number(0), shape(0)
	{
		srand(time(NULL));

	}
};