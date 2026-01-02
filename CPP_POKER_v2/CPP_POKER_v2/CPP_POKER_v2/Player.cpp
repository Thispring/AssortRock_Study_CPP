#include "Player.h"

void Player::ShowHand() {
	for (int i = 0; i < HAND_LIMIT; i++)
	{
		std::cout << "Player Hand[" << i + 1 << "]: ";
		std::cout << "number: " << hand[i].GetCardNumber() << " ";
		std::cout << "shape: " << hand[i].GetCardShape() << std::endl;
	}
}