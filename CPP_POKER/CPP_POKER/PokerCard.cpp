#include "PokerCard.h"
#include "Player.h"
#include <iostream>

HAND_RANK PokerCard::PokerCheck(int* _selectCard, bool isCheck) {
	// SortCards 함수 호출 후, 정렬된 상태에서 함수 동작해야함
	//SortCards(_selectCard);
	
	// 만약 main에서 isCheck가 true가 되지 않았다면
	// 검사 조건이 불충분한데 함수가 호출된것이므로 경고 메시지 출력
	if (!isCheck)
	{
		std::cout << "Not Poker Check Condition" << std::endl;
		return NONE;
	}

	// 족보 검사 로직
	// 계산을 위한 배열 선언 후, _selectCard 그대로 복사
	// 배열은 카드 번호를 판별하는 배열과, 문양을 판별하는 배열을 각각 선언
 	int tempNumbers[SELECT_CARD_LIMIT] = { };
	int tempShapes[SELECT_CARD_LIMIT] = { };
	for (int i = 0; i < SELECT_CARD_LIMIT; i++)
	{
		tempNumbers[i] = _selectCard[i];
	}

	// 같은 숫자가 몇개 있는지 카운팅하는 변수
	// 표현 숫자가 0부터 5까지만 필요하므로, unsigned char 사용
	// _2는 FullHouse 조건문에 사용
	unsigned char countSameNum_1= 0;
	unsigned char countSameNum_2 = 0;
	// 어떤 숫자가 같은건지 저장하는 정수 변수
	unsigned short sameNum_1 = 0;
	unsigned short sameNum_2 = 0;

	// 만약 같은 족보에서도 등급을 매기려면 enum 정수값 + N을 반환하는 것으로 구현
	// 숫자는 가장 큰 숫자가 높은 등급을, 문양은 SPADE > HEART > DIA > CLUB 순으로 등급 설정

	// 패에 같은 숫자카드가 얼마나 있는지 확인하는 로직은
	// 문양값을 제외한 숫자번호를 이용해서 판별하기
	int div = 1;   // 몫 (division)
	int mod = 1;   // 나머지 (modulo)

	// 숫자번호를 받고 문양 숫자(1~4)를 나눈 값을 다시 저장
	for (int i = 0; i < SELECT_CARD_LIMIT; i++)
	{
		int count = 1;	// 카드가 판별될때마다 +1;
		while (count != SELECT_CARD_LIMIT)
		{
			if (tempNumbers[i] == 0)
				break;

			// 나눗셈과 나머지를 이용해서, 나머지가 0이고,
			// 나눗셈 결과 범위가 1~13일 때 판별
			int tempDiv = 0;
			int tempMod = 0;
			tempDiv = tempNumbers[i] / div;
			tempMod = tempNumbers[i] / mod;
			// 나머지가 0이 아니면서, 1~13범위의 숫자여야함
			if (mod != 0 && div >= 1 && div <= 13)
			{
				// 어떤 문양인지를 저장, divided는 문양 번호 1~4에 대응되므로
				// divided를 저장
				tempShapes[i] = div;
				tempNumbers[i] = mod;
				div = 1;
				mod = 1;
				count++;
				break;
			}
			else
			{
				// 위 조건이 충족되지않으면 div, mod를 모두 +1
				div++;
				mod++;
			}
		}
	}

	// 나눈 값을 오름차순으로 재정렬
	SortCards(tempNumbers);

	bool isFlush = false;
	// FLUSH 판별
	// tempShapes가 모두 같은 값이면 FLUSH
	for (int i = 0; i < SELECT_CARD_LIMIT; i++)
	{
		if (i != 4 && tempShapes[i] != tempShapes[i + 1])
		{
			// 모든 문양번호가 일치해야지 FLUSH이므로, 1칸씩 이동하면서 다른값이 들어있다면
			// 바로 검사 중지
			isFlush = false;
			break;
		}
		else if (i == 4)	// 마지막 검사일때 위 조건이 걸리지 않았다면 isFlush를 true로 설정
		{
			isFlush = true;
		}
	}

	// 같은 숫자 판별 이전에, STRAIGHT 판별하기
	// 오름차순으로 정렬했기 때문에, 기준점에서 다음 배열이 +1한 값이라면
	// 계속 검사, +1이 아니라면 STRAIGHT 조건이 안되므로 검사 중지
	unsigned char straightCount = 0;
	for (int i = 0; i < SELECT_CARD_LIMIT; i++)
	{
		if (i != 4 && tempNumbers[i + 1] - tempNumbers[i] == 1)
		{
			// 카운트 변수를 따로 두어, STRAIGHT인지 카운트
			straightCount++;
		}
		else
		{
			break;
		}
	}
	// for 문이 끝나고 straightCount가 4인지 확인,
	// STRAIGHT_FLUSH는 가장 확률이 낮은 족보이고, FLUSH와 STRAIGHT조건을 모두 만족시켜야 하기 때문에
	// STRAIGHT검사가 끝난 뒤에 판별, FLUSH가 STRAIGHT보다 낮은 확률이므로 FLUSH를 먼저 판별
	if (isFlush && straightCount == 4)
		return STRAIGHT_FLUSH;
	else if (isFlush)
		return FLUSH;
	else if (straightCount == 4)
		return STRAIGHT;

	for (int i = 0; i < SELECT_CARD_LIMIT; i++)
	{
		for (int j = 1 + i; j < SELECT_CARD_LIMIT; j++)
		{
			// [i]번째를 기준점으로 잡고, [j+1]까지 전체를 검사
			// 만약 같은 숫자가 있다면 카운팅 후, 해당 숫자는 검사에서 제외
			// i는 기준점으로 0부터 5까지 순차적으로 카운팅, 검사 완료 후 [i]에 0을 대입해, 검사에서 제외시킴
			if (tempNumbers[i] != 0 && sameNum_1 == 0 && tempNumbers[i] == tempNumbers[j])
				countSameNum_1++;

			// sameNum_1에 값이 있다는 뜻은, 이미 같은 숫자가 판별되었다는 뜻이므로
			// countSameNum_2를 카운팅
			if (tempNumbers[i] != 0 && sameNum_1 != 0 && tempNumbers[i] == tempNumbers[j])
				countSameNum_2++;
		}
		// j for문이 끝나고 countSameNum_1가 1이상이라면 sameNum_1에 기준점 숫자를 대입
		if (sameNum_1 == 0 && countSameNum_1 >= 1)
		{
			sameNum_1 = tempNumbers[i];
			// i 번째를 0으로 만들어서 중복 검사 방지
			tempNumbers[i] = 0;
		}
		// 다음 조건에서 countSameNum_2가 1이상이라면, 같은 카드가
		// 2종류가 있다는 뜻이므로, sameNum_2에 해당 숫자를 대입
		else if (sameNum_2 == 0 && countSameNum_2 >= 1)
		{
			sameNum_2 = tempNumbers[i];
			// i 번째를 0으로 만들어서 중복 검사 방지
			tempNumbers[i] = 0;
		}
	}

	// FULL_HOUSE 조건 체크용
	// sameNum_1, _2 둘다 0이 아니라면, 같은 숫자가 있다는 뜻이므로
	// countSameNum_1, _2를 더한값이 5인지를 확인
	if (sameNum_1 != 0 && sameNum_2 != 0)
	{
		if (countSameNum_1 + countSameNum_2 == 5)
		{
			// FULL_HOUSE 이므로 이 시점에서 함수 종료
			return FULL_HOUSE;
		}
	}

	// 같은 카드숫자가 얼마나 있는지 판별하고, 조건문을 통해 알맞은 값을 반환
	// 만약 같은 숫자 카드가 없다면, 해당 족보는 HIGH_CARD

	//	HIGH_CARD(1) , ONE_PAIR , TWO_PAIRS , THREE_OF_A_KIND ,
	//	STRAIGHT , FLUSH , FULL_HOUSE , FOUR_OF_A_KIND , STRAIGHT_FLUSH(8) 
	//  (괄호 안 숫자는 정수 값, 오른쪽으로 갈수록 +1 증가)
	// 등장확률에 따라 가장 등장확률이 낮은 족보를 첫 if문으로 설정 

	if (countSameNum_1 == 4)
		return FOUR_OF_A_KIND;
	else if (countSameNum_1 == 3)
		return THREE_OF_A_KIND;
	else if (countSameNum_1 + countSameNum_2 == 2)
		return TWO_PAIRS;
	else if (countSameNum_1 == 1)
		return ONE_PAIR;
	else if (countSameNum_1 == 0)
		return HIGH_CARD;

	return NONE;
}

void PokerCard::SortCards(int* _sCard) {
	// selectCard를 받아, 값을 오름차순으로 정렬
	
	int min = 0;
	int Idx = 0;
	for (int i = 0; i < SELECT_CARD_LIMIT; i++)
	{
		// 정렬 후, 다음 i를 검사대상으로 초기화
		min = _sCard[i];
		for (int j = 0 + i; j < SELECT_CARD_LIMIT; j++)
		{
			if (j >= SELECT_CARD_LIMIT)
				break;

			// 더 작은 값을 찾아야 함
			// >= 연산자를 사용해 i와 j가 같을 때에도 한번 검사해
			// Idx에 j 값을 대입
			if (min >= _sCard[j])
			{
				min = _sCard[j];
				Idx = j;
			}
		}
		int temp = _sCard[i];
		_sCard[i] = min;
		_sCard[Idx] = temp;
		Idx = 0;
	}
}