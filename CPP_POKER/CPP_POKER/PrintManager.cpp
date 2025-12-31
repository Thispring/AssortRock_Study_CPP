// 사용자 정의 헤더
#include "Card.h"
#include "PrintManager.h"
// 표준 헤더
#include <iostream>

///*** 게임에서의 키를 눌러 다른 화면을 출력하게 하려면
///*** 무한반복안에 출력과 조건을 걸어두고, 특정 조건을 만나면
///*** 출력의 내용을 변경하는 방식으로 동작함

Card card;

// 인수만큼 '-'을 출력하는 함수
inline void PrintManager::PrintLine(int count) {
	for (int i = 0; i < count; i++)
		std::cout << "-";
	std::cout << std::endl;
}

// 인수만큼 ' '을 출력하는 함수
inline void PrintManager::PrintSpace(int count) {
	for (int i = 0; i < count; i++)
		std::cout << " ";
}

// Player가 어떤 배열을 선택했는지 출력하는 함수
void PrintManager::PrintSelectArray(bool isHandSelect) {
// Player의 isSelectHands 상태에 따라 출력 다르게 구현
	if (isHandSelect)
		std::cout << "Select: Hands" << std::endl;
	else
		std::cout << "Select: SelectCards" << std::endl;
}

// 게임의 이름과, 작동방법을 출력하는 함수
void PrintManager::PrintTitle() {
	PrintLine(45);
	std::cout << "       TOSPADA_C++_Ver       " << std::endl;
	std::cout << std::endl;
	std::cout << "  A, D: move card index      " << std::endl;
	std::cout << "  W: select or return card   " << std::endl;
	std::cout << "  S: Change select mode      " << std::endl;
	std::cout << "  P: Quit                    " << std::endl;
	std::cout << std::endl;
}

// 행동에 관련된 문장을 출력하는 함수, 매개변수로 어떤행동을 실행했는지 문자를 받고
// 조건에 따른 행동 출력
void PrintManager::PrintAction(const char* action) {
	
	if (action == "Dealer")
	{
		std::cout << "The dealer dealt 9 cards to the player." << std::endl;
		std::cout << "Blue Color Card is Current Card." << std::endl;
	}
}

// Player의 손패를 출력하는 함수, color를 매개변수로 받아
// 현재 선택된 카드의 텍스트 색상을 변경하여 출력
// 텍스트 색상은 본 헤더파일 namespace Color에 정의
void PrintManager::PrintCardBorad(int* pHand, int pointerColor) {
	PrintLine(45);
	PrintSpace(14);
	std::cout << "Player_Hands" << std::endl;
	std::cout << std::endl;
	
	// 카드는 shape값과 number값의 곱으로 이루어져 있어
	// 범위를 설정해 shape를 찾고, 어떤 숫자의 카드인지 출력
	// 출력은 Card.h에 선언한 문자 배열 사용

	for (int i = 0; i < HAND_LIMIT; i++)
	{
		// 중간 지점에서 개행으로 정리하기
		if (i == 4)
			std::cout << std::endl;

		// 현재 선택된 카드 텍스트 색상 변경
		// int pointerColor 매개변수와 맞는 i값에 특정 컬러 값을 추가하는 조건을 만들기
		// for문이 한번 돌때 작동하고, 그외에는 기본 색상으로 출력
		if (pointerColor == i)
			std::cout << Color::MAGENTA;
		else
			std::cout << Color::RESET;

		// pHand의 i번째 인덱스 번호를 추출해, 조건문으로 알맞은 카드를 콘솔에 출력
		int cardNum = classifyCardInfo(pHand, i, NUMBER);
		int cardShape = classifyCardInfo(pHand, i, SHAPE);

		// Card 클래스에 cardType 정수 변수를 인자로 받고
		// char 문자열을 반환하는 함수 만들기
		const char* cardName = card.GetCardNumberName(cardNum);

		// cardType이 0일때(카드를 선택하면 cardType 값이 0으로 변경) 반복 검사 생략
		if (cardNum == 0 || cardShape == 0)
		{
			std::cout << " [       ] ";
			continue;
		}

		switch (cardShape)
		{
		case 1:
			std::cout << "[" << CLUB << " " << cardName << "] ";
			break;
		case 2:
			std::cout << "[" << DIA << " " << cardName << "] ";
			break;
		case 3:
			std::cout << "[" << HEART << " " << cardName << "] ";
			break;
		case 4:
			break;
			std::cout << "[" << SPADE << " " << cardName << "] ";
		default:
			std::cout << "ERROR" << std::endl;
			break;
		}

	// 마지막 인덱스 숫자에서 컬러 강제 초기화
	// 8 -> 0으로 넘어갈때 그 다음 print 색상이 변경됨
	if (pointerColor >= HAND_LIMIT-1)
		std::cout << Color::RESET;
	std::cout << std::endl;
	}
}

// Player의 선택한 카드들을 출력하는 함수
void PrintManager::PrintSelectCardBorad(int* pSelectCard, int pointerColor) {
	// Player의 selectCards 배열을 받아 정보 출력
	// Card 정보를 받아와 문자열로 출력 변경
	
	PrintLine(45);

	// 가운데 정렬로 문자열 출력하는 함수
	// 문자열 상수의 strlen값을 받아 /2를 한 값을 반환하고
	// 해당 값 만큼 " " 출력하기
	for (int i = 0; i < 14; i++)
		std::cout << " ";
	std::cout << "Player_SelectCard" << std::endl;
	std::cout << std::endl;


	for (int i = 0; i < SELECT_CARD_LIMIT; i++)
	{
		// 선택된 카드 색상 변경
		if (pointerColor == i)
			std::cout << Color::CYAN;
		else
			std::cout << Color::RESET;

		if ((pSelectCard + i) == 0)
			std::cout << " [       ] ";
		else
		{
			// pHand의 i번째 인덱스 번호를 추출해, 조건문으로 알맞은 카드를 콘솔에 출력
			int cardNum = classifyCardInfo(pSelectCard, i, NUMBER);
			int cardShape = classifyCardInfo(pSelectCard, i, SHAPE);

			const char* cardName = card.GetCardNumberName(cardNum);

			switch (cardShape)
			{
			case 1:
				std::cout << "[" << CLUB << " " << cardName << "] ";
				break;
			case 2:
				std::cout << "[" << DIA << " " << cardName << "] ";
				break;
			case 3:
				std::cout << "[" << HEART << " " << cardName << "] ";
				break;
			case 4:
				break;
				std::cout << "[" << SPADE << " " << cardName << "] ";
			default:
				std::cout << "ERROR" << std::endl;
				break;
			}
		}
	}
	if (pointerColor >= SELECT_CARD_LIMIT - 1)
		std::cout << Color::RESET;
	std::cout << std::endl;
}
