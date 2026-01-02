#pragma once

#include "GameManager.h"	// 매크로와 표준 헤더 참조

class Dealer
{
private:
	// deck은 Card 객체를 저장한 배열로 선언
	Card deck[DECK_NUMBER];

public:
	// 52장의 플레잉 카드를 만드는 함수
	void MakeDeck();
	
	// Player에게 만들어진 Card 객체를 무작위로 나누어 주는 함수
	Card ShareCard();

	// 디버깅을 위해 Dealer가 소유한 카드를 보여주는 함수
	void ShowCard();

	// Card들을 저장한 배열주소를 받아, 족보를 체크하고, 알맞은 HAND_RANK를 반환하는 함수
	HAND_RANK CheckPoker(Card* _pCard);
};

