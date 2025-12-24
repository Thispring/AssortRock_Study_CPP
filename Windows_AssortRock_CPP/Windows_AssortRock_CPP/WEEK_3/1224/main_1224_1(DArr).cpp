// C++ iterator erase와 insert
#include <vector>
#include <iostream>
#include "C:\Users\141245124\Documents\GitHub\AssortRock_Study_CPP\Windows_AssortRock_CPP\Windows_AssortRock_CPP\WEEK_3\1223\DynamicArr.h"

using namespace std;

int main()
{
	DynamicArr<int>myArr;
	myArr.push_back(10);
	myArr.push_back(20);
	myArr.push_back(30);
	DynamicArr<int>::iterator Iter = myArr.begin();

	myArr.insert(Iter, 40);
	++Iter;
	myArr.insert(Iter, 50);

	for (int i = 0; i < myArr.size(); i++)
	{
		std::cout << myArr.GetData(i) << " ";
	}
	std::cout << std::endl;

	return 0;
}