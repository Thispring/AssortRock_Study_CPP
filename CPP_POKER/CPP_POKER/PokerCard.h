// 포커 규칙에 맞춰서 족보를 판별하는 클래스를 만듭니다.
// Card 클래스를 상속받아 구현합니다.
#pragma once
// 사용자 정의 헤더
#include "Card.h"
#include "Player.h"

// 이 게임에서 사용할 포커 족보
// High Card
// One Pair
// Two Pairs
// Three of a Kind
// Straight
// Flush
// Full House
// Four of a Kind
// Straight Flush

// 족보는 모두 1로 초기화 하고, Player가 선택한 카드들의 숫자들을 합산하여 대입


class PokerCard : Card {

protected:
	enum HandRank
	{
		HIGH_CARD , ONE_PAIR , TWO_PAIRS , THREE_OF_A_KIND ,
		STRAIGHT , FLUSH , FULL_HOUSE , FOUR_OF_A_KIND , STRAIGHT_FLUSH 
	} typedef HAND_RANK;
public:
	void PokerCheck(int* _selectCard, bool isCheck);
	int ReturnRank();
};
