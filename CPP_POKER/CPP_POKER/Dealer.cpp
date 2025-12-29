// 사용자 정의 헤더
#include "Card.h"
#include "Dealer.h"
// 표준 헤더
#include <iostream>
#include <ctime>

// 컴퓨터의 연산속도가 빠른 문제로 인해, rand함수의 시드값은
// main에서 한번만 호출하게 합니다.

// 무작위로 카드 숫자를 반환하는 함수(1 ~ 13)
int Dealer::RandomNumber() {
	return rand()% NUMBER_LIMIT + 1;
}
// 무작위로 카드 문양 번호를 반환하는 함수(1 ~ 4)
int Dealer::RandomShape() {
	return rand()% SHAPE_LIMIT + 1;
}
