#include <crtdbg.h>
#include "List.h"

#include "Arr.h"

#include <vector>
#include <list>

using namespace std;


class MyClass
{
private:
	int m_i;

public:
	MyClass()
		:m_i(0)
	{}
};


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//list<int> intList;
	//intList.pop_back();

	List mylist;

	mylist.push_back(1);
	mylist.push_back(2);
	mylist.push_back(3);

	mylist.reverse();


	Arr<int> arrInt;
	//arrInt.reserve(100); // Size : 0, Capacity : 100
	arrInt.resize(100); // Size : 100, Capacity : 100
	arrInt.push_back(100);


	for (int i = 0; i < 100; ++i)
	{
		arrInt.push_back(i + 1);
	}


	vector<int> vecInt;
	for (int i = 0; i < 100; ++i)
	{
		vecInt.push_back(i + 1);
	}
	vecInt.reserve(50);

	//MyClass* pMy = new MyClass;

	MyClass* pMy = (MyClass*)malloc(sizeof(MyClass));
	//pMy->MyClass::MyClass();
	*pMy = MyClass();

	int* pInt = (int*)malloc(sizeof(int));
	*pInt = int();

	return 0;
}

