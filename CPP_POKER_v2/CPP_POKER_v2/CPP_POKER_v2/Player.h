#pragma once

#include "GameManager.h"

class Player
{
private:
	// Dealer로 부터 9장의 카드를 받아 저장
	Card hand[HAND_LIMIT];
	// 플레이어가 포커를 만들기 위해 선택한 카드 모음
	Card selectCards[SELECT_CARD_LIMIT];
	// 플레이어가 완성된 포커카드를 저장할 배열
	HAND_RANK pokerCards[3];

public:
	// Player의 Hand를 참조하여 사용하기 위한 Getter
	Card* GetHand() { return hand; };
	// selectCards의 참조를 위한 Getter
	Card* GetSelectCards() { return selectCards; }
	// 디버깅을 위해 자신의 손패를 확인하는 함수
	void ShowHand();

};

