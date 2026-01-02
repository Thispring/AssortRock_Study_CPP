// Card 객체는 각자 고유의 문양과 번호를 부여받습니다. (중복없이)
// 현실의 플레잉카드 52장을 참고해 구현합니다.

#pragma once

// Card

#include <iostream>

class Card
{
private:
	// 카드 문양과 번호를 정수 변수로 구분합니다.
	// 음수가 필요없으므로 unsigned로 선언합니다.
	unsigned int number;	// (1~13)
	unsigned int shape;	// (1~4)
	
	// 멤버 함수
public:
	// 카드의 정보를 전달하는 Getter
	unsigned int GetCardNumber() { return number; }
	unsigned int GetCardShape() { return shape; }

	// 카드가 선택되었거나, 사용되었을 때, number와 shape값을 0으로 초기화
	void InitCardInfo() { number = 0; shape = 0; }

	// 생성, 소멸자
public:
	Card() : number(0), shape(0) { }
	Card(unsigned int _Num, unsigned int _Shape) : number(_Num), shape(_Shape) { }
	~Card() { std::cout << "Number: " << number << "	Shape: " << shape << std::endl; }
};
