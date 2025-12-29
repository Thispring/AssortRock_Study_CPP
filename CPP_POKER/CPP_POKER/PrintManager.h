#pragma once
// 게임의 출력을 담당하는 프로그램

// 표준 헤더
#include <iostream>
#include <string>

// cmd 문자열 색상 변경 방법:
// ANSI 이스케이프 코드 사용
// 
// 주요 ANSI 코드:
// \033[0m - 리셋 (기본 색상으로 복귀)
// \033[30m ~\033[37m - 전경색(검정, 빨강, 초록, 노랑, 파랑, 마젠타, 청록, 흰색)
// \033[90m ~\033[97m - 밝은 전경색
// \033[40m ~\033[47m - 배경색
// \033[1m - 볼드
// \033[4m - 밑줄

// 색상 코드 namespace 정의
namespace Color {
	const std::string RESET = "\033[0m";
	const std::string RED = "\033[31m";
	const std::string GREEN = "\033[32m";
	const std::string YELLOW = "\033[33m";
	const std::string BLUE = "\033[34m";
	const std::string MAGENTA = "\033[35m";
	const std::string CYAN = "\033[36m";
	const std::string WHITE = "\033[37m";
	const std::string BOLD_RED = "\033[1;31m";
	const std::string BOLD_GREEN = "\033[1;32m";
}

// TODO: 경고 메시지 namespace 정의
namespace WarningMessage {
	const std::string EMPTY = "It's Already Empty!";
	const std::string ALREADY = " ";
}

class PrintManager {
	// 터미널에 출력을 담당하는 클래스
	// main에서 while(1)문에 함수를 배치하여
	// 매 프레임 프린트하게 구현
public:
	// 인수만큼 '-'을 출력하는 함수
	void PrintLine(int count);

	// 인수만큼 ' '을 출력하는 함수
	void PrintSpace(int count);

	// Player가 어떤 배열을 선택했는지 출력하는 함수
	void PrintSelectArray(bool isHandSelect);

	// 게임의 이름과, 작동방법을 출력하는 함수
	void PrintTitle();

	// 행동에 관련된 문장을 출력하는 함수, 매개변수로 어떤행동을 실행했는지 문자를 받고
	// 조건에 따른 행동 출력
	void PrintAction(const char* string);

	// Player의 손패를 출력하는 함수, color를 매개변수로 받아
	// 현재 선택된 카드의 텍스트 색상을 변경하여 출력
	// 텍스트 색상은 본 헤더파일 namespace Color에 정의
	void PrintCardBorad(int* pHand, int pointerColor);

	// Player의 선택한 카드들을 출력하는 함수
	void PrintSelectCardBorad(int* pSelectCard, int pointerColor);
};
