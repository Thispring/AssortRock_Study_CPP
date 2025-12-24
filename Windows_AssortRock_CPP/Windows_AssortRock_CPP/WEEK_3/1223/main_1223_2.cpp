// 직접구현하는 동적배열 iterator
// iterator에 대한 설명:
// https://velog.io/@200woni/C-iterator-l4xbxmw6
#include <vector>
#include <iostream>
#include "DynamicArr.h"

using namespace std;

int main()
{
	DynamicArr <int>arrInt;
	arrInt.push_back(10);
	arrInt.push_back(20);
	arrInt.push_back(30);

	DynamicArr<int>::iterator myIter = arrInt.begin();

	// vector에서 end로 마지막 데이터를 가리킨 후, 해당 vector의 값을 참조하면
	// end는 마지막 데이터의 다음 주소를 리턴하기 때문에 범위를 벗어나는 값을 참조하게됨
	DynamicArr<int>::iterator myIter2 = arrInt.end();
	
	// ++ 연산자 구현
	{
		DynamicArr <int>arrInt;
		arrInt.push_back(10);
		arrInt.push_back(20);
		arrInt.push_back(30);
		arrInt.push_back(40);
		arrInt.push_back(50);
		arrInt.push_back(60);

		DynamicArr<int>::iterator myIter = arrInt.begin();

		// 전위 ++ 연산자 구현
		++myIter;
		++(++myIter); //<- vector 컨테이너에서는 이 문법이 가능, 연산자 함수에서 리턴값을 본인으로 설정하면 가능
	
		// 후위 ++ 연산자 구현
		myIter++;
		*(myIter++);
	}

	// -- 연산자 구현
	{
		DynamicArr <int>arrInt;
		arrInt.push_back(10);
		arrInt.push_back(20);
		arrInt.push_back(30);
		DynamicArr<int>::iterator myIter = arrInt.begin();
		++myIter;
		--myIter;
		std::cout << *(myIter) << std::endl;
		myIter++;
		myIter--;
		std::cout << *(myIter) << std::endl;
	}

	// 연산자 우선순위의 동작원리
	// 시퀀스 포인트: 모든 부수 효과가 완료되는 것이 보장되는 지점
	// 
	// 연산자 우선순위와 시퀀스 포인트는 각자 다른 개념
	// 연산자 우선순위: 표현식을 어떻게 묶을지 (파싱 규칙)
	// 시퀀스 포인트 : 부수 효과가 언제 완료될지(실행 시점 규칙)
	{
		int i = 1;
		// 연산자 우선순위 테스트
		int result1 = i++ * 2;
		cout << "result1: " << result1 << ", i: " << i << endl;
		// 출력: result1: 10, i: 6

		i = 5;
		//int result2 = (i * 2)++;  // 에러!  후위++는 우선순위가 높아서 i*2에 적용 불가
		// 에러: lvalue required as increment operand
	}

	{
		DynamicArr<int> myArr;
		myArr.push_back(10);
		myArr.push_back(20);
		myArr.push_back(30);

		DynamicArr<int> otherArr;
		otherArr.push_back(40);
		otherArr.push_back(50);
		otherArr.push_back(60);

		myArr.swap(otherArr);

		for (int i = 0; i < 3; i++)
		{
			std::cout << myArr[i] << " ";
		}
		std::cout << std::endl;

		for (int i = 0; i < 3; i++)
		{
			std::cout << otherArr[i] << " ";
		}
		std::cout << std::endl;

		int a = 0;
	}

	{
		DynamicArr<int> myArr;
		myArr.push_back(10);
		myArr.push_back(20);
		myArr.push_back(30);

		DynamicArr<int> otherArr;

		otherArr = myArr;
		
		int a = 0;
	}

	{
		DynamicArr<int> myArr;
		myArr.push_back(10);
		myArr.push_back(20);
		myArr.push_back(30);

		DynamicArr<int> otherArr(myArr);

		int a = 0;
	}


	return 0;
}