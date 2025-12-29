// C++ 디폴트 복사 생성자 (객체 복사)
#include <iostream>

class CTest {
private:
	int mI;
	float mF;
public:
	void setData(int i, float f) { mI = i; mF = f; }

	// 디폴트 대입 연산자
	void operator = (const CTest& other)
	{
		mI = other.mI;
		mF = other.mF;
		std::cout << "invoke default operator =" << std::endl;
	}
	
	// + 연산자 오버로딩을 통해 객체의 멤버 변수를 더해서 해당 결과를 반환
	CTest operator + (const CTest& other)
	{
		//(*) 컴파일러의 최적화로 지역변수 객체인 temp는 반환받을 CTest를 가리키는
		// 포인터로 변환하여, 실제로 지역에 CTest temp 객체를 만들지 않고, 가리켜진 객체를
		// 참조하여 연산을 수행한다.
		CTest temp;	// 계산을 위한 임시 객체
		
		// temp의 주소값 출력해보기
		// -> temp의 주소는 함수 호출 시, 대상이 되는 객체의 주소와 같다.
		std::cout << "temp Addr: " <<  &temp << std::endl;

		// 호출된 객체의 멤버와, 매개변수로 받아온 객체의 멤버를 더한 값을 리턴
		temp.mI = this->mI + other.mI;
		temp.mF = this->mF + other.mF;

		return temp;
	}

	// 생성자
	CTest() 
		: mI(0), mF(0.f)
	{
		std::cout << "invoke default constructor" << std::endl;
	}

	// 디폴트 복사 생성자
	CTest(const CTest& other)
		: mI(other.mI), mF(other.mF)
	{
		std::cout << "invoke default copy constructor" << std::endl;
	}
};

int main()
{
	CTest t1;
	CTest t2;
	CTest t3;
	t1.setData(10, 10.f);
	t2.setData(20, 20.f);

	// 해당 과정을 호출하면, 디폴트 생성자 -> 디폴트 대입 연산자 -> 디폴트 복사 생성자 순으로 실행
	// 디폴트 대입 연산자와, 복사 생성자는 명시적으로 표시하지 않더라도
	// 컴파일러가 자동으로 해당 기능을 호출
	t3 = t1;	// 디폴트 대입연산자 호출

	// 해당 과정을 호출하면 어떻게 되는지 콘솔에 print 해보기
	CTest t4(t2);	// 복사 생성자 호출
	CTest t5 = t2;	// 객체 생성과 함께 =을 하면, 디폴트 대입연산자가 생략되고 복사 생성자 호출

	// 복사 생성자는 최적화를 위해
	// 디폴트 생성자 -> 디폴트 대입 연산자 -> 디폴트 복사 생성자의 과정 중
	// 디폴트 복사 생성자만 호출함

	// t1과 t2의 멤버 변수를 더한 값을 t6에 전달하는 방법
	// 연산자 오버로딩을 통해 구현
	CTest t6 = t1 + t2;

	// t6의 주소값 확인해보기
	std::cout << "t6 Addr: " << &t6 << std::endl;

	return 0;
}