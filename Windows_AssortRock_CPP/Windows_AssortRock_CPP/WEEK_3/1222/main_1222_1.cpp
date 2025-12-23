// C++ 벡터와 리스트

#include <iostream>
#include <vector>
#include <list>

using std::vector;
using std::list;

int main()
{
	// =================================================================
	// STL (Standard Template Library)
	// Vector: 동적배열 구조로 데이터를 저장 및 관리 가능한 컨테이너 클래스 템플릿
	// 
	// 메모리 공간이 연속적인 것이 특징 -> push_back 함수만 있는 이유
	// 
	// 동적배열은 메모리가 연속적이여야 하기 때문에, 효율성을 생각하면 
	// push_back 함수가 알맞음
	// =================================================================
	vector<int> vecInt;
	
	vecInt.push_back(10);
	vecInt.push_back(20);
	vecInt.push_back(30);

	vecInt.at(0) = 200;	// 0번째 벡터 인덱스의 값을 200으로 변경
	vecInt[1] = 300;	// []연산자 오버로딩으로 배열처럼 사용 가능

	std::cout << "vector 입력 데이터 확인" << std::endl;
	for (int i = 0; i < vecInt.size(); i++)
	{
		std::cout << vecInt[i] << std::endl;
	}

	// ======================================================
	// list: 데이터를 노드단위로 저장하고, 서로 연결한 구조(비연속적)
	// 
	// 연결 리스트 방식으로, Head가 첫번째 노드를 가리키는
	// 구조로 되어있어서 push_front 함수가 존재
	// 
	// 리스트에 저장된 데이터에 접근하기 위해서, iterator가 필요하다.
	// ======================================================
	list<int> intList;

	// vector와 다른점은 list는 push_front 멤버 함수가 존재
	intList.push_back(10);
	intList.push_front(20);
	// .at()함수나 []인덱스 오퍼레이터 함수가 존재하지 않다.
	// STL은 자료구조에 알맞은 효율적인 함수만 존재

	// =====================================================
	// iterator: 반복자
	// 컨테이너안에 저장되어 있는 데이터를 접근할 수 있는 기능
	// 특정 컨테이너에 구애받지 않는, 일관적인 코드를 작성할 수 있다.
	// 컨테이너 내부 구현을 외부에 숨길 수 있다.
	// =====================================================
	list<int>::iterator iter;	// iterator도 하나의 class
	iter = intList.begin();		// intList의 시작을 가리키는 상태
	*iter = 200;				// 접근해서 수정도 가능
	*(++iter);						// intList의 두 번째 주소


	return 0;
}