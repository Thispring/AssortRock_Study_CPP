// Card의 역할은 숫자를 받아와서 어떤 포커카드인지 정보를 넘겨주고
// Player가 뽑은 5개의 포커카드를 통해 어떤 족보인지 정보를 넘겨주는 역할입니다.

#pragma once
#include "GameManager.h"

class Card : public Dealer
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