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
	int a = *myIter;

	// vector에서 end로 마지막 데이터를 가리킨 후, 해당 vector의 값을 참조하면
	// end는 마지막 데이터의 다음 주소를 리턴하기 때문에 범위를 벗어나는 값을 참조하게됨
	DynamicArr<int>::iterator myIter = arrInt.end();
	int b = *myIter;

	// ++ 연산자 구현

	return 0;
}