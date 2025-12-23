// CPP 포커 게임

#include "Card.h"
#include "Dealer.h"
#include "Player.h"
#include "PrintManager.h"

#include <iostream>
#include <vector>

// windows API에서 입력버퍼에 있는 문자를 읽어오는 기능
// windows.h에 있는 함수 이용하여 getstdin에 구현
// -> 작동방식 확인 필요
#include <windows.h>

// windows API를 이용한 입력버퍼에 있는 문자를 읽어오는 함수
int getstdin()
{
	// Unicode WASD
	// W (U+0057)
	// A (U+0041)
	// S (U+0053)
	// D (U+0044)
	// 소문자는 대문자+32

	// Unicode는 16진수로 이루어져있고, 정수로 반환 시
	// 16 -> 10진수 반환 과정이 있음을 유의

	// 입력이 없었을 때 %을 반환하는 상황
	// cmd.exe의 "echo %errorlevel%"
	// cmd.exe에는 errorlevel 이라는 특별환경변수가 존재
	
	// 1. 표준 입력 핸들 가져오기
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	if (hInput == INVALID_HANDLE_VALUE) {
		std::cerr << "표준 입력 핸들을 가져올 수 없습니다. 오류 코드: " << GetLastError() << std::endl;
		return 1;
	}

	// 2. 콘솔 입력 모드 설정 (선택 사항, 기본 모드로도 동작)
	DWORD originalMode;
	GetConsoleMode(hInput, &originalMode);

	// 사용자가 입력할 시간을 줌
	Sleep(10);

	// 3. 입력 버퍼에 쌓인 이벤트 개수 확인
	// DWORD는 long 정수타입 변수, 이벤트 개수 확인
	DWORD numEvents = 0;
	if (!GetNumberOfConsoleInputEvents(hInput, &numEvents)) {
		std::cerr << "입력 이벤트 개수를 가져올 수 없습니다. 오류 코드: " << GetLastError() << std::endl;
		return 1;
	}

	// 4. 입력 이벤트를 저장할 버퍼 생성 및 읽기
	std::vector<INPUT_RECORD> buffer(numEvents);
	DWORD numEventsRead = 0;
	if (!ReadConsoleInput(hInput, buffer.data(), numEvents, &numEventsRead)) {
		std::cerr << "콘솔 입력을 읽을 수 없습니다. 오류 코드: " << GetLastError() << std::endl;
		return 1;
	}

	// 5. 읽어온 이벤트를 순회하며 키보드 입력 추출
	for (DWORD i = 0; i < numEventsRead; ++i) {
		// 이벤트 타입이 KEY_EVENT인 경우
		if (buffer[i].EventType == KEY_EVENT) {
			KEY_EVENT_RECORD& keyEvent = buffer[i].Event.KeyEvent;

			// 키가 '눌렸을' 때만 처리 (뗐을 때는 무시)
			if (keyEvent.bKeyDown) {
				char ch = keyEvent.uChar.AsciiChar;
				return ch;
			}
		}
	}
}


int main()
{
	// dealer.Random 함수들에 srand(time(NULL)); 실행 시
	// 컴퓨터의 빠른 연산속도에 따라 함수들이 호출되어, time 시드값 간의 차이가
	// 유의미하게 나지 않아, 이를 컴퓨터가 인식하지 못해 같은 값이 출력되는 문제발생
	// -> 해결을 위해 main함수에서 srand를 한번만 호출
	srand(time(NULL));

	// 클래스 선언부
	Card card;
	Dealer dealer;
	Player player;
	PrintManager printM;

	// main 함수에서 사용할 변수 선언부
	// 
	// Player의 hands 멤버 변수에 접근할 포인터 변수 pHand선언
	int* pHand = player.GetHands();
	// Player의 selectCards 멤버 변수에 접근할 포인터 변수 pSelectCard선언
	int* pSelectCard = player.GetselectCards();

	// 터미널 비우기 여부
	// 무한반복문에 이전 출력 내용을 지우고, 현재 출력내용만 남게 하기
	bool isClear = false;	

	// Player가 어떤 배열을 가리키고 있는지 판단하는 bool 변수
	// true면 hands를 가리키고 있는 상태, false면 selectCards를 가리키는 상태
	bool isSelectHand = true;

	// hands 배열을 순회하는 변수
	static int handIdx = 0;

	// selectCards 배열을 순회하는 변수
	static int selectCardIdx = 0;

	// Dealer dealt card to Player
	printM.PrintTitle();
	printM.PrintAction("Dealer");

	player.SetCard();

	printM.PrintSelectArray(isSelectHand);
	printM.PrintSelectCardBorad(pSelectCard, selectCardIdx);
	printM.PrintCardBorad(pHand, handIdx);

	while (1)
	{
		char input = 0;

		// 입력버퍼에서 문자를 읽어오는 함수
		input = getstdin();
		// 반환한 문자 내용을 기반으로 특정 동작을 수행하도록 조건문을 작성합니다.

		// system("cls");	// 터미널을 비우는 함수
		// switch문 case 마다 해당 함수 선언하여 이전 터미널 출력을 지우고 출력하기	

		switch (input)
		{
		// input에서 받아온 문자의 숫자를 case로 사용합니다.
		// 방향키 입력 숫자를 확인하기
		// or WASD 사용

		// case 87 && 119: 와 같이 표현하면
		// 컴파일러는 && 논리연산을 실행 -> 양쪽의 값이 모두 참이면 참 반환
		// 숫자를 논리값으로 해석하여, 0이아닌 모든 숫자는 참으로 계산
		// 고로 switch에서 2개이상의 숫자에 같은 조건을 넣고싶으면, 중첩하여 표현하기

		// W, w
		// W키는 현재 handIdx 값에 맞는 카드를 hands에서 가져와 selectCards에 순차적으로 배치
		// 선입후출 방식으로 카드를 선택하고 제외 시키기
		case 87:
		case 119:
			system("cls");
			std::cout << "Input: W" << std::endl;
			// player.isSelectHands 상태에 따라 행동 분기 나뉨
			// WASD 에도 isSelectHands에 따라 행동 분기 나뉘게 구현
			// ex) !isSelectHands 일때 A, D 누르면 isSelectHands현재 선택 인덱스 색상 변경
			if (isSelectHand)
				player.PickCard(handIdx);	// 두 번째 매개변수로 래퍼런스를 받아 selectCardIdx -1 증가
			else
				player.ReturnSelectCard(selectCardIdx);	// 두 번째 매개변수로 래퍼런스를 받아 selectCardIdx -1 감소

			std::cout << std::endl;
			std::cout << "Current handIdx: " << handIdx << std::endl;
			std::cout << "Current selectCardIdx: " << selectCardIdx << std::endl;
			std::cout << std::endl;

			// 위 로직이 끝난 후 Print
			printM.PrintTitle();
			printM.PrintSelectArray(isSelectHand);
			printM.PrintSelectCardBorad(pSelectCard, selectCardIdx);
			printM.PrintCardBorad(pHand, handIdx);
			break;
		// A, a
		// A키는 인덱스를 -1연산으로 인덱스 번호를 변경
		case 65:
		case 97:
			system("cls");
			std::cout << "Input: A" << std::endl;
			if (isSelectHand)
				player.GetPickCardIndex(handIdx, true);
			else
				player.GetReturnCardIndex(selectCardIdx, true);
	
			std::cout << std::endl;
			std::cout << "Current handIdx: " << handIdx << std::endl;
			std::cout << "Current selectCardIdx: " << selectCardIdx << std::endl;
			std::cout << std::endl;

			// 위 로직이 끝난 후 Print
			printM.PrintTitle();
			printM.PrintSelectArray(isSelectHand);
			printM.PrintSelectCardBorad(pSelectCard, selectCardIdx);
			printM.PrintCardBorad(pHand, handIdx);
			break;
		// S, s
		// S키는 선택모드를 변경
		// ex) 호출이 없었다면 hands에서 카드를 W로 선택할 수 있게하고, 호출이 있었다면 hands가 아닌 selectCards에서 카드를 W로 다시 가져오는 기능
		case 83:
		case 115:
			system("cls");
			std::cout << "Input: S" << std::endl;
			isSelectHand = player.ToggleHandMode(isSelectHand);

			std::cout << std::endl;
			std::cout << "Current handIdx: " << handIdx << std::endl;
			std::cout << "Current selectCardIdx: " << selectCardIdx << std::endl;
			std::cout << std::endl;

			// 위 로직이 끝난 후 Print
			printM.PrintTitle();
			printM.PrintSelectArray(isSelectHand);
			printM.PrintSelectCardBorad(pSelectCard, selectCardIdx);
			printM.PrintCardBorad(pHand, handIdx);
			break;
		// D, d
		// D키는 인덱스를 +1연산으로 인덱스 번호를 변경
		case 68:
		case 100:
			system("cls");
			std::cout << "Input: D" << std::endl;
			if (isSelectHand)
				player.GetPickCardIndex(handIdx, false);
			else
				player.GetReturnCardIndex(selectCardIdx, false);

			std::cout << std::endl;
			std::cout << "Current handIdx: " << handIdx << std::endl;
			std::cout << "Current selectCardIdx: " << selectCardIdx << std::endl;
			std::cout << std::endl;

			// 위 로직이 끝난 후 Print
			printM.PrintTitle();
			printM.PrintSelectArray(isSelectHand);
			printM.PrintSelectCardBorad(pSelectCard, selectCardIdx);
			printM.PrintCardBorad(pHand, handIdx);
			break;

		default:
			break;
		}
	}
	
	return 0;
}
