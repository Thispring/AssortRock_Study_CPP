// C++ inline 함수

#include <iostream>

#define SET_INT(t, data) t.mI = data; 

class Test {
public:
	int mI;
	float mF;

public:
	// inline함수는 실질적으로 호출을 하지않고,
	// 구현부분을 그대로 복사하여 동작을 실행합니다.
	// 매크로함수와 비슷한 기능, inline 함수는
	// 실제로 함수호출이 발생하지 않아 속도면에서 유리합니다.
	
	// 또한 전역함수와 다르게, 헤더에 작성하더라도, 매크로 처럼 동작하기 때문에
	// 해당 헤더파일을 include한 cpp마다 함수 정의가 생겨나지 않는다.
	// -> 이름 중복 문제를 피할 수 있음
	
	// 주로 자주 호출되는 간단한 함수를 inline으로 선언하여 실행시키는게 좋음
	// -> Get, Set 함수 (.h에서 구현)

	// 헤더에 함수를 구현했다고 해서 무조건 inline 함수로 만들어주지 않음, (컴파일러 마다 기준이 있음)
	inline void SetInt(int i) { mI = i; }	// .h 파일 클래스 멤버함수는 inline 취급을 받는다.
	inline void SetFloat(float f) { mF = f; }

public:
	Test() : mI(0), mF(0.0) {}

	~Test() {}
};

int main()
{
	Test t;
	// 두 동작은 동일하지만, 함수를 호출하는 쪽이 더 느리다.
	// 하지만 클래스의 은닉성을 지키기 위해 멤버함수를 호출하여,
	// 멤버변수를 변경하는 식으로 구현한다.
	t.mI = 10;
	t.SetInt(10);
	t.SetFloat(3.14);

	// 매크로 함수는 전처리기 단계에서 치환되기 때문에
	// 디버그 정보를 알 수 없다.
	SET_INT(t, 20);

	return 0;
}

// nullptr과, NULL, delete
// NULL은 stdio에서 int형 0값으로 매크로로 정의되어 있지만, nullptr은 다르다.
// nullptr을 delete했을 경우는 구현에 문제가 있다는 의미일 수 있고, smart pointer를 사용하는것이 아니면
// 런타임에 포인터가 nullptr인지 아닌지 예측할 수 있는 코드를 작성하는 것이 장기적으로 볼때 중요하다.
// https://www.inflearn.com/community/questions/9705/delete-%EC%99%80-nullptr-%EC%A7%88%EB%AC%B8%EC%9E%85%EB%8B%88%EB%8B%A4?srsltid=AfmBOorldXGEYj4qQqbaAwHIYSZHSed-P1UpzKFCSn-5gHP8XizeWFU7
// https://en.cppreference.com/w/cpp/language/delete.html
// https://del4u.tistory.com/41
