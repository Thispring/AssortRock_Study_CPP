// 게임의 실행에 대한 관리를 담당합니다.
// 관리할 부분을 클래스로 만들어 사용합니다.

// 클래스를 어떻게 나누는게 좋을지 생각해보기
// 헤더파일 단위로 
// ex) GameManager에 역할이 다른 클래스 5개가 필요한 경우 .h도 5개 생성
// 하나의 클래스 안에 생성
// ex) GameManager에 역할이 다른 클래스 5개가 필요한 경우 GameManager에 5개의 클래스 생성
// 
// -> 현재 역할마다 클래스와 헤더파일을 각각 생성하는 식으로 작성 중
#pragma once
#include <ctime>
#include <iostream>

#include "Card.h"

// ==================================================================
// 게임 내에서 여러 번 공유되는 정의는 모두 GameManager.h에 구현, 관리 합니다.
// ==================================================================

#define HAND_LIMIT 9			// Player의 손패는 9장으로 제한합니다.
#define SELECT_CARD_LIMIT 5		// 포커 족보를 만들기 위해 선택한 카드는 5장으로 제한합니다. (현실 포커 족보를 따름)
#define POKER_CARD_LIMIT 3		// Poker 카드는 3장으로 제한합니다.

// 카드 정보에 대한 헤더
// 어떤 카드인지는 숫자를 통해 구분하고
// 출력은 유니코드를 사용 (♠, ♥, ♦, ♣)
#define NUMBER_LIMIT 13
#define SHAPE_LIMIT 4
#define DECK_NUMBER 52

// 카드 문양 출력용 데이터
// 만약 비정상 출력 시
// 컴퓨터에서 유니코드 및 폰트 설정
#define CLUB "♣"
#define DIA "♦"
#define HEART "♥"
#define SPADE "♠"

// 카드 이름 출력용 데이터
#define JACK "JACK"
#define QUEEN "QUEEN" 
#define KING "KING"

// HandRank를 enum으로 선언하여, 등장확률이 낮은 순서가 높은 번호를 부여받게 설정
extern enum HAND_RANK {
	NONE, HIGH_CARD, ONE_PAIR, TWO_PAIRS, THREE_OF_A_KIND,
	STRAIGHT, FLUSH, FULL_HOUSE, FOUR_OF_A_KIND, STRAIGHT_FLUSH
};

// 카드 배열과 인덱스 번호를 받아 나눗셈 결과를 반환하는 전역함수
// 번호 전용, 문양 전용으로 나누어 다른 클래스에서도 사용
// enum 형태로 어떤 정보를 반환할지 전달받기
//extern int classifyCardInfo(int* _pHand, int _Idx, CARD_INFO _whatInfo);
