// 사용자 정의 헤더
#include "Card.h"
// 표준 헤더
#include <iostream>

// Card에서 숫자번호를 받아, 해당하는 숫자를 문자열로 반환하는 함수
// 11은 JACK, 12는 QUEEN, 13은 KING으로 반환합니다.
const char* Card::GetCardNumberName(int getCardNum) {
	// getCardNum은 Dealer가 무작위로 생성한 수(1~13), (1~4)의 곱으로 이루어져 있습니다.
	// 그 중 1~4의 범위는 카드의 문양을 구분하는데 사용하므로, 카드의 숫자를 판별하려면
	// 1~4범위의 숫자로 나눈 값이 1~13이 되어야 합니다.
	int divided = 1;	
	while (divided <= 4)
	{
		if (getCardNum == 0)
			break;

		getCardNum = getCardNum / divided;
		if (1 <= getCardNum && 13 >= getCardNum)
		{
			switch (getCardNum)
			{
			case 1: return "    1"; break;
			case 2: return "    2"; break;
			case 3: return "    3"; break;
			case 4: return "    4"; break;
			case 5: return "    5"; break;
			case 6: return "    6"; break;
			case 7: return "    7"; break;
			case 8: return "    8"; break;
			case 9: return "    9"; break;
			case 10: return "  10"; break;
			case 11: return "JACK"; break;
			case 12: return "QUEEN"; break;
			case 13: return "KING"; break;
			default: break;
			}
		}
		else
		{
			divided++;
		}
	}
}
