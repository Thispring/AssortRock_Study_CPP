// C++ iterator (반복자)
// C++에서 제공하는 컨테이너(vector, list)를 관리하게 해주는 라이브러리

#include <iostream>
#include <vector>
#include <list>

using namespace std;

// ===============================================
// 내부(Inner) 클래스, 외부(Outer) 클래스(=포함 클래스)
// ===============================================

class MyClass
{
private:
	int mI;
public:
	MyClass() : mI(0) {}
	~MyClass() {}

	// 내부 클래스, MyClass와 별개의 자료형
	// 접근지정자에 영향을 받음
	// ex) private에 선언하면 은닉됨
	// 각각 별개의 변수이기 때문에 이름 중복을 피할 수 있다.
	// 
	// 내부 클래스는 외부 클래스를 서포팅할 수 있는 기능을
	// 구현할 때, 사용합니다. (논리적으로 연관이 있어야함)
	// -> vector(기타 컨테이너)와 iterator도 같은 관계
	// 컨테이너(외부 클래스), iterator(컨테이너 내부에 구현된 클래스)
	class Inner
	{
	private:
		float mF;
	public:
		Inner() : mF(0.0) {}
		~Inner() {}
	};
};

class OtherClass
{
private:
	char ch;
public:
	class Inner
	{
		long long mLL[100];
	public:
		// 내부 클래스는 외부 클래스의 private 멤버에 접근이 가능
		// -> 더 알아보기
	};
};

int main()
{
	MyClass my;
	MyClass::Inner inner;	// MyClass를 선언하더라도 Inner의 멤버를 직접 사용할 수 없음
	//Inner inner; (이렇게 선언 불가능)
	// 서로 다른 클래스 내부에 구현된 Inner는 별개의 자료형으로, 이름 중복 문제를 피할 수 있다.
	OtherClass::Inner inner2;	

	// =================
	// vector와 iterator
	// =================
	vector<int> vecInt;
	vecInt.push_back(10);
	vecInt.push_back(20);
	vecInt.push_back(30);

	// iterator 객체를 생성하고, vecInt가 관리하고 있는 데이터 중 첫번째 데이터를 가리키는 상태
	vector<int>::iterator vecIter = vecInt.begin();

	// iterator가 가리키고 있는 데이터로 접근한다.
	// 포인터처럼 주소연산자를 사용할 수 있다. (객체의 주소를 가지고 있기에)
	vecIter.operator*() = 100;
	*vecIter = 100;

	// ===============
	// List와 iterator
	// ===============
	list<int> intList;
	intList.push_back(40);
	intList.push_back(50);
	intList.push_back(60);

	list<int>::iterator listIter = intList.begin();
	*listIter = 200;

	// =============
	// iterator 문법
	// =============
	vecIter = vecInt.begin();	// 시작 데이터의 주소
	vecIter = vecInt.end();		// 마지막 데이터가 가리키고 있는 주소(맨 마지막 데이터 자체가 아님)

	// =====================================================================
	// iterator 를 이용해서 컨테이너 안에 들어있는 데이터를 처음부터 끝까지 순회해보기
	// =====================================================================

	// 기존 vector에서 제공해주는 .at() 함수를 사용한 예
	for (int i = 0; i < vecInt.size(); i++)
	{
		std::cout << "vector .at: " << vecInt.at(i) << " ";
	}
	std::cout << std::endl;

	// iterator를 사용한 예
	// iterator를 vector의 시작을 가리키고, vector가 end에 도달할때 까지, iterator를 ++하며 반복
	for (vecIter = vecInt.begin(); vecIter != vecInt.end(); ++vecIter)
	{
		// iterator에 *연산하면 vecIter가 가리키는 주소에 있는 데이터를 출력
		std::cout << "vector iterator: " << *vecIter << " ";
	}
	std::cout << std::endl;

	// List를 iterator로 순회하는 예
	for (listIter = intList.begin(); listIter != intList.end(); ++listIter)
	{
		std::cout << "list iterator: " << *listIter << " ";
		// Vector는 .at()함수나 "vecInt[0];" 와 같이 배열 형식처럼 값을 출력할 수 있지만
		// List는 그것이 불가능해 iterator를 사용해야함
	}
	std::cout << std::endl;

	// ============================================================
	// iterator는 어떤 형태의 컨테이너를 사용하던 (vector, list, set...) 
	// 컨테이너의 주소를 받아와 (.begin(), .end()...) 컨테이너를 제어할 수 있게 도와줄 수 있다.
	// -> 컨테이너에 구애받지 않고, 일관적인 코드를 작성할 수 있고, 컨테이너 내부 구조를 들어낼 필요가 없다.
	// =======================================================================================
	// 
	// -> 수업 때 직접만든 '연결 리스트', '동적배열' 클래스를 제어할 수 있는 iterator를 구현해보기

	// =============================================
	// Vector는 pop_front를 내부 함수로 지원하지 않는다.
	// -> 앞에서 부터 지운다면 뒤에 있는 데이터 만큼 땡겨와야 하기에 비효율적
	// iterator로 vector에 pop_front를 구현하는 방법
	// ==========================================
	vecIter = vecInt.begin();	// vector의 시작주소를 받고

	// 아래 두 동작은 반환값에 따라 동작이 달라짐
	// erase 함수는 입력으로 넣어준 주소가 가리키는 요소를 지우고
	// 지워진 다음 주소를 반환
	// 
	//vecInt.erase(vecIter);
	//vecIter = vecInt.erase(vecIter);

	//intList.erase(intList.begin());

	// ========================================================
	// iterator도 하나의 "사용자 정의 자료형", 포인터와 전혀 다른 개념
	// 컨테이너와도 별개의 자료형 개념, 메모리 공유되는 것이 아님
	// iterator는 std에 컨테이너에 맞게 동작을 수행하게끔 구현되어있다.
	// ========================================================


	// iterator를 이용해서 50보다 작은 수를 반복문으로, 컨테이너 안에서 제거하기
	{
		list<int> myIntList;

		for (int i = 0; i < 100; ++i)
		{
			//myIntList.push_front(i + 1);
			myIntList.push_back(i + 1);
		}

		// 반복문이 의도한대로 조건을 수행하는지 꼭 확인하기
		// 아래 예시 for문에 ++iter를 할 경우 지운뒤에 ++iter를 실행하여 다음 iter를 건너뛰는 현상이 있음
		for (list<int>::iterator iter = myIntList.begin(); iter != myIntList.end();)
		{
			if (*iter < 50)
			{
				if (*iter == 0)
					break;

				// 지워주는 로직
				iter = myIntList.erase(iter);	// 현재 iter가 가리키고 있는 값을 지우고, 다음 iter가 가리키는 요소를 반환
				// 지운뒤에 비어있는 List를 가리키게 반환
				//myIntList.push_back(0);
				//myIntList.push_front(0);
			}
			else
			{
				iter++;
			}
		}
		int a = 0;
		int b = a;

	}

	return 0;
}