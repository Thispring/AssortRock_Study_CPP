// C++ 객체지향

// 객체지향이란?
// 생산성을 위해 현실에서 존재하는 물건(객체)의 역할을 구현하기 위해
// 객체마다 고유의 역할을 수행하도록 프로그래밍하는 것
// 
// 객체지향의 특징
// 1. 캡슐화
// 2. 상속
// 3. 다형성
// 4. 추상화

// C에서는 구조체(사용자 정의 자료형)이 객체 역할을 할 수 있으나 한계점이 존재
// C++에서는 이를 보완한 class를 만듬

// C struct
struct MyStruct
{
	int i;
	float f;
};

// C++ class의 기능
// 은닉성 - private, protected(상속에서 주로 사용), public
// 멤버를 외부에 쉽게 공개하지않고, 의도한 함수에서만 변경할 수 있도록 하기 위함
// ex)멤버를 외부에 공개한다면, 코드가 복잡해지거나 협업과정 중 의도치않게 멤버의 값이 변경될 수 있음
// 이 때 어떤 이유로 멤버가 변경되었는지 디버깅하기가 어려워짐
class MyClass
{
	// 접근지정자를 명시하지 않으면 기본은 private로 선언
	// private는 외부에 멤버를 공개하지 않는다는 뜻
	int i;
	float f;
public:
	// public은 외부에 멤버를 공개한다는 뜻
	int i2;
	float f2;

	// 멤버 함수
	// public 필드에 선언하여, 해당 클래스를 지원하는 전용 함수
	// Set함수는 외부에서 접근하지 못하는 private 멤버의 값을 변경하기 위해 사용
	// public으로 제공한 멤버함수로만 멤버 변수에 접근 가능

	// 멤버 함수 호출 시 반드시 호출 객체가 있어야 한다.
	// 멤버 함수 안에는 this 지역변수가 있다.(생략가능)
	// this는 멤버 함수를 호출한 객체의 주소를 받는다.
	void SetInt(int data) { i = data; }
	void SetFloat(float data) { f = data; }

	// 생성자
	// 객체 생성 시 호출
	// 멤버 변수의 초기화와 대입이 가능
	MyClass()
		// 초기화, 멤버가 const로 선언된 경우 이니셜라이저로만 초기값을 세팅할 수 있다.
		: i(10), f(3.14)	
	{
		// 대입
		i = 10;
		f = 3.14;
	}

	// 생성자 오버로딩
	// 클래스를 만들때, 정수값을 인자로 주면 해당 생성자가 호출
	MyClass(int a)
		: i(a)
	{

	}

	// 소멸자
	// 객체 소멸 시 호출
	~MyClass()
	{

	}
};

// 이름공간 선언
namespace MY_SPACE
{
	int Global = 0;
	void MyFunc();
}
int Global = 0;

// namespace를 명시적으로 생략하게 할 수 있는 코드
//using namespace MY_SPACE;
// namespace의 특정 기능만 생략하게도 작성 가능
using MY_SPACE::MyFunc;

// C++문법 struct는 C문법 struct와 다르다.
// C++에서 struct는 class와 기능에 차이가 거이 없음
// (C++ struct에서 디폴트 접근지정자는 public, class는 private)
// ex)C++ struct에서도 접근지정자 사용가능
int main()
{
	MyStruct ms;
	ms.i = 10;
	ms.f = 3.14;

	MyClass mc;
	// mc.i,f는 private멤버라 접근 불가
	//mc.i = 10;
	//mc.f = 3.14;

	mc.i2 = 10;
	mc.f2 = 3.14;

	// class의 특징으로 멤버함수 호출 시
	// 자기자신의 클래스 포인터를 매개변수로 받아
	// 클래스의 주소를 참조하여 멤버에 접근 할 수 있다.
	// C++ 문법에서는 클래스 포인터 참조의 명시적 표시를 생략할 수 있다.
	mc.SetInt(10);
	mc.SetFloat(3.14);


	MyClass class1;
	MyClass class2;
	MyClass class3;
	MyClass class4(5);

	// C++에 추가된 것
	// namespace(이름공간)
	// -> 변수명 중복을 피하기 위해 만들어짐
	// -> namespace에 class와 전역함수를 넣어 사용할 수 있다.
	// 
	// 레퍼런스

	// 아래 두 전역변수는 같은 이름이지만 별개의 변수
	Global = 100;
	MY_SPACE::Global = 200;

	return 0;
}