#include "List.h"

int main()
{
	List myList;

	myList.push_back(10);
	myList.push_back(20);
	myList.push_back(30);
	myList.push_front(40);
	myList.push_front(50);
	myList.push_front(60);

	List myList2;
	myList2.push_front(10);
	myList2.push_front(20);
	myList2.push_front(30);
	int a = 0;

	return 0;
}