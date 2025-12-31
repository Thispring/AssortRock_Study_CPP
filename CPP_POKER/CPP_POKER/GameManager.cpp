#include "GameManager.h"

int classifyCardInfo(int* _pHand, int _Idx, CARD_INFO _whatInfo)
{
	int div = 1;   // 몫 (division)
	int mod = 1;   // 나머지 (modulo)

	// 검사할 데이터를 저장
	int data = _pHand[_Idx];

	while (1)
	{
		// data가 0이라면(빈 카드 상태) 검사 종료
		if (data == 0)
			return 0;

		// 나눗셈과 나머지를 이용해서, 나머지가 1이상 이고,			
		// 나눗셈 결과 범위가 1~13일 때 판별
		int number = 0;
		int shape = 0;
		number = data / div;
		shape = data % mod;
		// 나머지가 0이면서, 1~13범위의 숫자여야함
		if (shape == 0 && number >= 1 && number <= 13)
		{
			// _whatInfo에 따라 return 분기를 다르게 전달
			if (_whatInfo == NUMBER)
				return number;
			else
				return mod;	// shape가 0이 되는 숫자이면서 해당 범위라면 mod가 곧 문양 번호
		}
		else
		{
			// 위 조건이 충족되지않으면 div, mod를 모두 +1
			div++;
			mod++;
		}
	}

	// 위 조건이 모두 만족되지 않았다면 잘못 설계된 것이므로 -1 반환
	return -1;
}
