#include "Dealer.h"

void Dealer::MakeDeck() {
	
	int Idx = 0;
	
	for (unsigned int i = 1; i <= SHAPE_LIMIT; i++)
	{
		for (unsigned int j = 1; j <= NUMBER_LIMIT; j++)
		{
			Card card(j, i);
			deck[Idx] = card;
			Idx++;
		}
	}
}

Card Dealer::ShareCard() {
	// 0~51중 무작위 번호를 받고,
	// 중복되지 않은 숫자라면 Player에게 
	// deck에서 해당 인덱스의 Card를 리턴
	// 리턴된 Dealer의 Card는 0으로 초기화
	int randNum = 0;
	int dupCheckNum = 0;	// Card 객체의 GetCardNumber 함수 호출을 통해 0이 아닌지 확인

	do
	{
		randNum = rand() % 51;
		dupCheckNum = deck[randNum].GetCardNumber();

	} while (dupCheckNum == 0);

	// 중복된 카드가 아니라면 전달할 카드의 정보를 복사하고 해당 카드를 리턴
	// Dealer의 카드는 0으로 초기화
	Card dealCard = deck[randNum];
	deck[randNum].InitCardInfo();

	return dealCard;
}

void Dealer::ShowCard() {
	for (int i = 0; i < DECK_NUMBER; i++)
	{
		// Deck 배열은 0~51, 가독성을 원하면 +1하여 출력
		std::cout << "Deck[" << i+1 << "] Card Info: ";
		std::cout << "number: " << deck[i].GetCardNumber() << " ";
		std::cout << "shape: " << deck[i].GetCardShape() << std::endl;
	}
}

HAND_RANK Dealer::CheckPoker(Card* _pCard) {
	
	HAND_RANK rank = NONE;

	// FLUSH 판별은 shape가 모두 같은지 확인
	
	// STRAIGHT는 number만 따로 추출하여, 순서대로 있는지 확인

	// Card 배열에서 같은 숫자가 얼마나 있는지 판별
	int countSameNum_1 = 0;
	int countSameNum_2 = 0;

	int sameNum_1 = 0;
	int sameNum_2 = 0;
	
	return rank;
}
