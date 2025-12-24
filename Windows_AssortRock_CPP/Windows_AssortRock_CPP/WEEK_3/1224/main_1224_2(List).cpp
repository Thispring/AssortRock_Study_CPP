#include "List.h"
#include <iostream>
#include <list>

int main()
{
	// 어떤 컨테이너든 데이터를 입력받은 적이 없을 때, begin() 호출 시 end의 주소를 반환
	// -> 데이터가 없다면 시작지점과 끝 지점이 동일
	// -> 데이터가 추가되면 끝 지점은 시작지점 + 1
	// 직접만든 동적배열에도 begin()에 예외처리가 필요함
	List<int> myList;
	myList.push_back(10);
	myList.push_back(20);
	myList.push_back(30);
	int a = 0;

	return 0;
}