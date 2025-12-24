#include <iostream>
#include <vector>
#include "Arr.h"

using namespace std;

class Test
{
public:
	Test& Output()
	{
		return *this;
	}
};


int main()
{
	Test t;
	t.Output().Output();

	vector<int> vecInt;
	vecInt.push_back(10);
	vecInt.push_back(20);
	vecInt.push_back(30);

	vector<int> vecInt2(vecInt);


	vecInt.swap(vecInt2);


	vector<int>::iterator viter = vecInt.begin();
	(viter++);

	viter = vecInt.begin();
	int Data = *(++viter);
	
	cout << *viter << endl;


	Arr<int> arrInt;
	arrInt.push_back(10);
	arrInt.push_back(20);
	arrInt.push_back(30);

	// 후위 operator++ 은 iterator 가 다음 요소를 가리키고, 내부에서 복사한 객체를 반환한다.
	Arr<int>::iterator myiter = arrInt.begin();
	cout << *(myiter++) << endl;

	
	

	return 0;
}