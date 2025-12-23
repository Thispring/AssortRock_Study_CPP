// CPP 연산자

// 프로그램 실행 순서
// 전처리기 -> 컴파일 -> 링킹 -> 실행파일 생성(.exe)
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	// [Lab_0]
	// 실수형과 정수형의 표현방법 차이
	float f = -118.625;
	int* p;
	p = (int*)&f;	// float 변수 f의 주소를 int* 형으로 캐스팅하여 int* 변수 p에 대입
	int testP = *p;	// int* 변수인 p의 역참조값을 testP에 대입
	cout << "testP: " << testP << endl;

	float oriF = (float)*p;	// p의 역참조값을 float로 캐스팅하여 oriF에 대입
	cout << "oriF: " << oriF << endl;
	cout << endl;

	int i = 100;
	float* fp;
	fp = (float*)&i;	// int 변수 i의 주소를 float* 형으로 캐스팅하여 float* 변수 fp에 대입
	float testF = *fp;	// float* 변수인 fp의 역참조값을 testP에 대입
	cout << "testF: " << testF << endl;

	i = 200;
	float testF2 = *fp;
	cout << "testF2: " << testF2 << endl;

	int oriI = (int)*fp;	// fp의 역참조값을 int로 캐스팅하여 oriI에 대입
	cout << "oriI: " << oriI << endl;
	// Q1) 컴파일 후 포인터 변수에 마우스를 올려 나오는 값이 해당 포인터가 가리키는 주소값인지, 포인터 변수의 주소값인지?
	// -> 첫번째 값은 주소이고 {}대괄호 안에 있는 값은 주소에 들어있는 데이터 값
	// 
	// Q2) 포인터 변수도 변수형태에 따라 컴파일러의 해석방법이 다른건지? (정수와 실수 표현 처럼), (포인터 변수는 메모리 주소를 가리키는 변수로 알고있음)
	// -> 포인터도 변수 형태에 따라 숫자해석이 달라짐
	// 
	// Q3) Q1이 주소값을 가리키는게 맞다면, 왜 역참조 값을 출력했을 때 주소의 값이 출력되는지?
	// -> 주소의 값이 아니고 주소에 들어있는 값을 출력, 단 자료형에 따른 해석차이가 존재

	// +, -, *, /, % 연산자
	// 대입 연산자 ('=')
	int iData = 0;	// 초기화
	iData = 100;	// 대입

	iData = (3 + 5) * 2;

	float fData = 3.33333f;

	int a = iData + fData;

	// 연산자 우선순위
	// https://en.cppreference.com/w/c/language/operator_precedence.html

	// (*) int로 설정한 체력 데이터(Cur, Max)를 가지고 현재 체력이 전체체력보다 50%미만으로 내려갔을 때, 특정 이펙트를 출력하려는 예제
	// float HPRatio = Cur / Max; 할 시 정수끼리 나눗셈이 되어 HPRatio에는 0이 들어간다.
	// 게임 로직 의도에 맞게 알맞은 변수타입을 설정하거나, 형변환을 명시적으로 표시하기

	// [Lab_1]
	// 랜덤으로 들어온 숫자의 홀짝 구분 프로그램
	{
		srand(time(NULL));
		int num = rand() % 100 + 1;
		if (num % 2 == 0)
			cout << endl << "num: " << num << "은 짝수" << endl;
		else
			cout << "num: " << num << "은 홀수" << endl;
	}

	// 비교 연산자
	// ==, !=, <, <=, >, >=
	// !: 참을 거짓으로, 거짓을 참으로 변경하는 연산자
	// 
	// 참과 거짓에 대한 개념
	// 0(=false), 0이 아닌 모든 수, 대부분 1을 반환(=true)
	// C에서는 bool을 지원하지 않기에 전처리기로 설정
	// ex) #define TRUE 1
	// 컴파일: 컴파일러가 프로그래밍 언어로 작성한 코드의 문법을 검사하고, 어셈블리 코드(컴퓨터가 이해할 수 있는 언어)로 변환하는 작업
	// 전처리기는 컴파일 단계보다 이전에 수행
	bool isTrue = 3000;
	cout << endl << boolalpha << isTrue << endl;
	isTrue = 0;
	cout << boolalpha << isTrue << endl;

	// 지역
	{
		int iData = 100 == 99;
		cout << endl << iData << endl;
	}

	return 0;
}

// 단축키
// Ctrl + Shift + B			: 빌드 실행
// F5						: 디버깅 실행
// F10						: 한줄만 실행