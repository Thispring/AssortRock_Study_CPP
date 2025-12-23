#include "Player.h"
#include "Dealer.h"
#include "PrintManager.h"	// 경고 메시지에 출력 색상을 변경하기 위한 헤더

#include <iostream>

Dealer dealer;

// Dealer로 부터 랜덤한 값을 받아 카드를 얻는 함수
// randCardNum을 얻어 hands 배열에 순차적으로 추가
void Player::SetCard() {
	// 중복되는 카드를 제외하고 받는 기능 구현
	bool isDup = false;
	int loopCount = 0;
	while (loopCount != HAND_LIMIT)
	{
		for (int i = 0; i < HAND_LIMIT; i++)
		{
			hands[i] = dealer.RandomNumber() * dealer.RandomShape();

			// i가 0이 아닌 두번째 부터검사
			if (i != 0)
			{
				for (int j = 0; j < HAND_LIMIT; j++)
				{
					// i와 j의 숫자가 같을때와 값이 0일때는 제외
					if (i != j && hands[i] != 0 && hands[i] == hands[j])
					{
						isDup = true;
						break;
					}
				}
			}

			// 만약 중복으로 인해 isDup가 true라면 다시 뽑기
			if (isDup)
			{
				isDup = false;
				i--;
				continue;
			}

			loopCount++;
		}
	}
}

// hands의 시작주소를 리턴하여 접근하게 하는 함수
int* Player::GetHands() {
	return hands;
}

// selectCards의 시작주소를 리턴하여 접근하게 하는 함수
int* Player::GetselectCards() {
	return selectCards;
}

// Player의 손패에 있는 Card 데이터의 정수 값을 출력하는 함수(테스트용)
// Card는 Dealer가 반환한 두 무작위 숫자의 곱으로 이루어져있음
void Player::ShowHandsInfo() {
	for (int i = 0; i < HAND_LIMIT; i++)
		std::cout << "hands[" << i << "]: " << hands[i] << std::endl;
}

// hands, selectCards 중 어느 배열을 선택할 것인지를 반환하는 함수
// isSelectHands가 true면 hands를 가리키고 있는 상태, false면 selectCards를 가리키는 상태
bool Player::ToggleHandMode(bool state) {
	// 다른 카드 선택 함수들에 bool 변수 판별을 추가하거나,
	// Player.cpp에서 카드 선택 함수들을 오버라이딩 한 후
	// main의 방향키 조작에서 bool 변수를 연산하고 알맞은 오버라이딩 된 함수 호출
	return !state;
}

// hands 배열 탐색을 위한 인덱스를 반환하는 함수, A키는 -1연산, D키는 +1연산으로 정의
// refHandIndex는 main.cpp에서 선언된 변수의 레퍼런스를 사용
void Player::GetPickCardIndex(int& refHandIndex, bool isNegative) {
	// isNegative는 A, D키 방향에 맞게 설정 (D는 false -> +연산, A는 true -> -1연산)

	// refHandIndex의 값을 검사하고, 0~8인덱스를 순환하도록 조건검사
	if (isNegative)	// -1 연산일때, A키
	{
		if (refHandIndex <= 0)	// 0이라면 8로 변경
		{
			refHandIndex = 8;
			return;
		}
		else
			refHandIndex--;
	}
	else		// +1 연산일때, D키
	{
		if (refHandIndex >= 8)	// 8이면 0으로 변경
		{
			refHandIndex = 0;
			return;
		}
		else
			refHandIndex++;
	}
}

// selectCards 배열 탐색을 위한 인덱스를 반환하는 함수, A키는 -1연산, D키는 +1연산으로 정의
// refPickCardIndex는 main.cpp에서 선언된 변수의 레퍼런스를 사용
// GetPickCardIndex와 로직 동일
void Player::GetReturnCardIndex(int& refPickCardIndex, bool isNegative) {
	// isNegative는 A, D키 방향에 맞게 설정 (D는 false -> +연산, A는 true -> -1연산)
	
	// refHandIndex의 값을 검사하고, 0~4인덱스를 순환하도록 조건검사
	if (isNegative)	// -1 연산일때, A키
	{
		if (refPickCardIndex <= 0)	// 0이라면 4로 변경
		{
			refPickCardIndex = 4;
			return;
		}
		else
			refPickCardIndex--;
	}
	else		// +1 연산일때, D키
	{
		if (refPickCardIndex >= 4)	// 4라면 0으로 변경
		{
			refPickCardIndex = 0;
			return;
		}
		else
			refPickCardIndex++;
	}		
}

// Player가 포커 족보를 생성하기 위해 hands에서 하나의 카드를 고르는 함수
// hands[curHandIndex]로 현재 접근한 인덱스의 값을 selectCards에 빈 공간에 순차적으로 옮김
void Player::PickCard(int curHandIndex) {
	// 골라진 hands[curHandIndex]값은 0으로 변경하여
	// 주어진 카드가 없는 공간으로 설정합니다.

	// selectCards배열을 순회하여 빈자리 부터 차례대로 정렬
	// 만약 빈자리가 없다면 경고 메시지 출력
	
	int emptyIndex = 0;	// 값이 없는 빈 공간이 어디인지 저장하는 변수
	for (int i = 0; i < SELECT_CARD_LIMIT; i++)
	{
		if (selectCards[i] == 0)
		{
			emptyIndex = i;
			break;	// 빈공간을 찾으면 빠져나오기
		}
	}

	// 이전에 고른 카드일 때
	if (hands[curHandIndex] == 0)
	{
		std::cout << "Already selected card from hands!" << std::endl;
		std::cout << std::endl;
		return;
	}

	// selectCards 남은 배열 공간이 없는 경우
	// 카드 선택이 성공했으면 Player 멤버 변수인 selectCount을 증가 시켜
	// selectCount가 SELECT_CARD_LIMIT와 같은지 판별
	if (selectCount == SELECT_CARD_LIMIT)
	{
		std::cout << "Is SELECT CARD LIMIT!" << std::endl;
		std::cout << std::endl;
		return;
	}

	// 위 예외 조건이 통과되면
	// hands의 값을 selectCards로 옮기고
	// 현재 hands값을 0으로 만들어 카드 데이터를 비우기
	selectCards[emptyIndex] = hands[curHandIndex];
	hands[curHandIndex] = 0;
	
	selectCount++;	// 카드 선택이 성공했으면 Player 멤버 변수인 selectCount을 증가
}

// 선택된 카드를 다시 hands에 돌려놓는 함수
// PickCard와 옮기는 규칙(=옮겨진 배열에 0대입) 동일
void Player::ReturnSelectCard(int curIndex) {
	// hands[]배열을 첫번째부터 순회하여 만약 값이 0이면, 해당 인덱스 부터 값 채워나가기

	int emptyIndex = 0;	// 값이 없는 빈 공간이 어디인지 저장하는 변수
	for (int i = 0; i < HAND_LIMIT; i++)
	{
		if (hands[i] == 0)
		{
			emptyIndex = i;
			break;
		}
	}

	// 매개변수 curIndex는 main의 static int selectCardIndex = 0; 사용
	if (selectCards[curIndex] != 0)
	{
		// hands[emptyIndex]는 비어있기에 (=값이 0), 해당 위치에 값 대입
		hands[emptyIndex] = selectCards[curIndex];
		selectCards[curIndex] = 0;
		selectCount--;	// Player 멤버 변수 selectCount을 -1 감소
	}
	else
	{
		// selectCards[curIndex]가 0이면 비어있는 카드이기 때문에 반환
		std::cout << "Current selectCard is Already Empty!" << std::endl;
		std::cout << std::endl;
		return;
	}
}

// selectCards를 읽어와, 알맞은 포커족보를 반환하는 함수
// TODO: 역할을 다시 고려해보고 PokerCard의 함수로 옮기기
void Player::PokerChecker() {
	// selectCards 배열에 값이 5개가 모두 있는지 검사
	for (int i = 0; i < SELECT_CARD_LIMIT; i++)
	{
		if (selectCards[i] == 0)
		{
			return;
		}
	}

	// 족보 검사 로직
	// 계산을 위한 배열 선언 후, selectCards 그대로 복사
	int tempNumCards[SELECT_CARD_LIMIT] = { };
	for (int i = 0; i < SELECT_CARD_LIMIT; i++)
	{
		tempNumCards[i] = selectCards[i];
	}

	int sameNumberCount = 0;

	// 가장 높은 족보부터 조건문 우선 검사
	// HIGH_CARD 조건
	// 5장의 손에 같은 숫자를 가진 카드가 없어야함
	// 만약 HIGH_CARD에서도 등급을 매기려면 숫자번호를 반환하는 것으로 구현

	// 패에 같은 숫자카드가 얼마나 있는지 확인하는 로직은
	// 문양값을 제외한 숫자번호를 이용해서 판별하기
	int divided = 1;

	// 숫자번호를 받고 문양 숫자(1~4)를 나눈 값을 다시 저장
	for (int i = 0; i < SELECT_CARD_LIMIT; i++)
	{
		while (divided <= 4)
		{
			if (tempNumCards[i] == 0)
				break;

			tempNumCards[i] = tempNumCards[i] / divided;
			if (1 <= tempNumCards[i] && 13 >= tempNumCards[i])
			{
				break;
			}
			else
			{
				divided++;
			}
		}		
	}
	
	for (int i = 0; i < SELECT_CARD_LIMIT; i++)
	{
		// 현재 카드와 다음 순서에 있는 카드의 숫자가 같은지 판별
		if (i != 4 && tempNumCards[i] == tempNumCards[i + 1])	
			sameNumberCount++;
	}

	// 만약 같은 숫자 카드가 없다면, 해당 족보는 HIGH_CARD
	if (sameNumberCount == 4)
		std::cout << "FOUR_OF_A_KIND" << std::endl;
	else if (sameNumberCount == 3)
		std::cout << "THREE_OF_A_KIND" << std::endl;
	else if (sameNumberCount == 2)
		std::cout << "TWO_PAIRS" << std::endl;
	else if (sameNumberCount == 1)
		std::cout << "ONE_PAIR" << std::endl;
	else if (sameNumberCount == 0)
		std::cout << "HIGH_CARD" << std::endl;

}