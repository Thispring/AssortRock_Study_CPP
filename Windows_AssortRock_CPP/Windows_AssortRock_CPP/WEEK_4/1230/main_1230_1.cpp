// C++ 상속
#include <iostream>

// C++의 객체지향 특성:
// 캡슐화, 상속, 다형성, 추상화

// 상속은 생산성을 위해, 기존에 존재하는 자료형(클래스, 구조체)의
// 기능을 물려받아서, 새로운 자료형을 설계하는 것

// 상속 관련 문법:

class Parent
{
private:
	int m_Private;
public:
	int m_Public;
protected:
	int m_Protected;

public:
	// 함수 오버라이딩
	void Output() { std::cout << "Parent m_Public is: " << m_Public << std::endl; }
	void SetPublic(int _i) { m_Public = _i; }
public:
	Parent() : m_Private(0), m_Public(0), m_Protected(0) {}
	Parent(int _i) : m_Private(_i), m_Public(_i), m_Protected(_i) {}
	~Parent() {}
};

// Child는 Parent를 상속받음
// Parent를 어떤 접근 지정자로 가져올지에 따라
// 접근할 수 있는 멤버나 메서드가 달라진다.
// ex)private로 상속을 받는다면, 부모의 public 멤버도
// private로 바뀌어, 접근할 수 없게 된다.
class Child : public Parent
{
	// ==========================================
	// 상속을 받더라도, Parent와 Child는 별개의 자료형
	// ==========================================
private:
	int m_Child;

public:
	// 부모와 똑같은 함수 이름을 기능만 다르게 하여 오버라이딩
	void Output() { std::cout << "Child m_Public is: " << m_Public << std::endl; }
	void SetParent() { SetPublic(30); }
public:
	Child() : //Parent()	// <- 부모 생성자를 재호출 하지 않아도 됨, 명시적으로 적지 않아도 컴파일러가 자동으로 생성
		Parent(10)// 부모 생성자 중 오버로딩 된 생성자를 호출하려면 명시적으로 작성해야함
		//, m_Public(0)	// 초기화는 각자 클래스에서 이루어져야함, 초기화가 아닌 대입은 가능
		, m_Child(0)
		// 상속과 생성자 호출
		// 자식 클래스의 생성자가 호출
		// 자식 클래스의 생성자에서 다시 부모쪽 생성자 호출
		// 초기화 순서: 부모 -> 자식
	{
		// 부모의 private 멤버는 접근이 불가능하고
		// public과 protected는 가능하다
		//m_Private = 0;
		//m_Public = 0;
		//m_Protected = 0;
	}
	// 소멸 순서: 자식 -> 부모
	~Child() { Parent::~Parent(); }
};

int main()
{
	Parent p(20);
	Child c;
	// 자식 클래스의 크기는 부모 클래스 + 자식 클래스의 크기

	// Protected는 상속받은 자식의 클래스에서만 접근이 가능하고
	// 자식이 외부에서 접근할 수 없다.
	//p.m_Private = 1;
	//p.m_Protected = 1;
	//p.m_Public = 1;

	//c.m_Protected = 1;
	//c.m_Public = 1;
	c.SetParent();
	c.Output();
	p.Output();
	std::cout << p.m_Public << std::endl;
	std::cout << c.m_Public << std::endl;


	return 0;
}