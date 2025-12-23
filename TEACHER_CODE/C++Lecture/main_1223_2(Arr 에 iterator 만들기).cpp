#include <iostream>
#include <vector>
#include "Arr.h"

using namespace std;


int main()
{
	vector<int> vecInt;
	vecInt.push_back(10);
	vecInt.push_back(20);
	vecInt.push_back(30);

	vector<int>::iterator viter = vecInt.begin();
	++viter;
	++viter;
//	++viter;
	//++viter;

	viter = vecInt.begin();
	int Data = *(++viter);
	//int Data = *(viter++);


	cout << *viter << endl;


	Arr<int> arrInt;
	arrInt.push_back(10);
	arrInt.push_back(20);
	arrInt.push_back(30);

	Arr<int>::iterator myiter = arrInt.begin();
	++myiter;
	++myiter;
	++myiter;

	++myiter;

	// 후위 연산자 모양으로 호출한다고 해서, 근본적인 맴버함수 호출 원리가 바뀌지는 않는다.
	// 그냥 맴버함수를 연산자 모양으로 호출하는 것이기 때문에, 호출 우선순위가 나중으로 밀리거나 하지 않는다.
	// 후위 연산을 한 느낌을 주려면, 트릭을 사용해야 한다.
	myiter++;

	int a = 0;
	//int b = ++a + 10;
	int c = a++ + 10;


	

	cout << *myiter << endl;


	return 0;
}