// 포커 규칙에 맞춰서 족보를 판별하는 클래스를 만듭니다.

#pragma once

// 사용자 정의 헤더
#include "GameManager.h"

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

class PokerCard {

public:
	// selectCard를 체크하여, 정수값을 Player의 pokerCards로 전달
	HAND_RANK PokerCheck(int* _selectCard, bool isCheck);
	// selectCard에 있는 값을 오름차순으로 정렬하는 알고리즘
	void SortCards(int* _sCard);
};
