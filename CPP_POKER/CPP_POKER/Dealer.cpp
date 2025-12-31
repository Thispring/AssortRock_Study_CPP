// 사용자 정의 헤더
#include "Dealer.h"
// 표준 헤더
#include <iostream>
#include <ctime>

// 컴퓨터의 연산속도가 빠른 문제로 인해, rand함수의 시드값은
// main에서 한번만 호출하게 합니다.

// 무작위로 카드 숫자를 반환하는 함수(1 ~ 13)
//int Dealer::RandomNumber() {
//	return rand()% NUMBER_LIMIT + 1;
//}
// 무작위로 카드 문양 번호를 반환하는 함수()
// 문양 판별 계산은 계산된 카운트만큼을 반환하여, 
// 1회는 DIA, 2회는 CLUB, 3회는 HEART, 4회는 SPADE로 설정합니다.
// 현재 24를 예로들어 2로도 나뉘어지고, 3으로도 나뉘어지고 4로도 나뉘어지며,
// 나뉜값이 1~13범위에 들어가기에, 24는 검사 시 CLUB QUEEN(12)으로 고정되는 문제발견
//int Dealer::RandomShape() {
//	return rand()% SHAPE_LIMIT + 1;
//}
