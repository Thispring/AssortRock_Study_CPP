// Card의 역할은 숫자를 받아와서 어떤 포커카드인지 정보를 넘겨주고
// Player가 뽑은 5개의 포커카드를 통해 어떤 족보인지 정보를 넘겨주는 역할입니다.

// 카드 정보에 대한 헤더
// 어떤 카드인지는 숫자를 통해 구분하고
// 출력은 유니코드를 사용 (♠, ♥, ♦, ♣)
#pragma once
#define NUMBER_LIMIT 13
#define SHAPE_LIMIT 4

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

class Card {
public:
	// 넘겨받은 카드의 숫자를 판별하여, 문양을 제외하고 카드가 어떤 숫자를 
	// 가지고 있는지 판별하여 문자열로 반환하는 함수
	const char* GetCardNumberName(int getCardNum);
};