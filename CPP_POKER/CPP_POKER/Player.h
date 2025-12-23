// Player는 멤버 변수로 전달받은 카드를 저장하는 배열과, 승패 상태를 나타내는 변수를 가지고 있습니다.
// 멤버 함수로는 카드를 받아오는 함수와, 배열의 인덱스를 탐색하는 함수, 카드를 고르고 포커 카드로 만드는 함수를 작성합니다.
#pragma once

#define HAND_LIMIT 9			// Player의 손패는 9장으로 제한합니다.
#define SELECT_CARD_LIMIT 5		// 포커 족보를 만들기 위해 선택한 카드는 5장으로 제한합니다. (현실 포커 족보를 따름)
#define POKER_CARD_LIMIT 3		// Poker 카드는 3장으로 제한합니다.

// TODO(12/17): public, protected 멤버 변수 private로 변경하고, 접근가능한 멤버 함수 구현하기
// -> Player 클래스를 상속하여 자식클래스를 만들게되면 멤버 변수 protected로 변경
class Player {
private:
	// Player의 승리, 패배, 무승부 여부를 저장하는 변수
	int status;
	// Player가 카드를 선택할 때마다 증가하는 인덱스, selectCards의 오버 플로를 방지하는데 사용
	// selectCards 탐색 인덱스는 분리해서 사용
	int selectCount = 0;
	// Dealer로 부터 받은 무작위 카드를 저장하는 Player의 손패
	int hands[HAND_LIMIT] = {};
	// Player가 포커를 만들기 위해 선택한 카드를 모아두는 배열
	int selectCards[SELECT_CARD_LIMIT] = {};
	// Player가 만든 포커 카드를 모아두는 배열
	int pokerCards[POKER_CARD_LIMIT] = {};
public:
	// Dealer로 부터 랜덤한 값을 받아 카드를 얻는 함수
	// randCardNum을 얻어 hands 배열에 순차적으로 추가
	void SetCard();

	// hands의 시작주소를 리턴하여 접근하게 하는 함수
	int* GetHands();

	// selectCards의 시작주소를 리턴하여 접근하게 하는 함수
	int* GetselectCards();

	// Player의 손패에 있는 Card 데이터의 정수 값을 출력하는 함수(테스트용)
	// Card는 Dealer가 반환한 두 무작위 숫자의 곱으로 이루어져있음
	void ShowHandsInfo();

	// hands, selectCards 중 어느 배열을 선택할 것인지를 반환하는 함수
	// isSelectHands가 true면 hands를 가리키고 있는 상태, false면 selectCards를 가리키는 상태
	bool ToggleHandMode(bool state);

	// Player가 키보드(WASD 입력)로 배열을 순회하여 1개의 카드를 선택하는 함수
	// 현재 배열의 인덱스값을 반환하여, 반환값을 다른함수에서 접근하도록 구현
	//
	// hands 배열 탐색을 위한 인덱스를 반환하는 함수, A키는 -1연산, D키는 +1연산으로 정의
	// refHandIndex는 main.cpp에서 선언된 변수의 레퍼런스를 사용
	void GetPickCardIndex(int& refHandIndex, bool isNegative);

	// selectCards 배열 탐색을 위한 인덱스를 반환하는 함수, A키는 -1연산, D키는 +1연산으로 정의
	// refPickCardIndex는 main.cpp에서 선언된 변수의 레퍼런스를 사용
	// GetPickCardIndex와 로직 동일
	void GetReturnCardIndex(int& refPickCardIndex, bool isNegative);

	// Player가 포커 족보를 생성하기 위해 hands에서 하나의 카드를 고르는 함수
	// hands[curHandIndex]로 현재 접근한 인덱스의 값을 selectCards에 빈 공간에 순차적으로 옮김
	void PickCard(int curHandIndex);

	// 선택된 카드를 다시 hands에 돌려놓는 함수
	// PickCard와 옮기는 규칙(=옮겨진 배열에 0대입) 동일
	void ReturnSelectCard(int curIndex);

	// selectCards를 읽어와, 알맞은 포커족보를 반환하는 함수
	void PokerChecker();
};
