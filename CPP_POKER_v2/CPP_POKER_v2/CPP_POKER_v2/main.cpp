// 표준 헤더
#include <iostream>

// 사용자 정의 헤더
#include "Card.h"
#include "Dealer.h"
#include "GameManager.h"
#include "Player.h"

int main()
{
	srand(time(NULL));

	Dealer dealer;
	Player player;

	dealer.MakeDeck();

	Card* pHand = nullptr;
	pHand = player.GetHand();

	for (int i = 0; i < HAND_LIMIT; i++)
	{
		pHand[i] = dealer.ShareCard();
	}
	
	dealer.ShowCard();
	std::cout << std::endl;
	player.ShowHand();

	return 0;
}