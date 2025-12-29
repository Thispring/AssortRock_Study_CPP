#include <iostream>
#include <list>

#include "List.h"

using namespace std;

int main()
{
	// STL list Insert Test
	{
		list<int> stlList1;
		stlList1.push_back(10);
		stlList1.push_back(20);
		stlList1.push_back(30);
		stlList1.insert(stlList1.begin(), stlList1.begin(), stlList1.end());
		

		list<int> stlList2;
		stlList2.push_back(40);
		stlList2.push_back(50);
		stlList2.push_back(60);
		
		list<int>::iterator iter;
		iter = stlList1.insert(stlList1.begin(), stlList2.begin(), stlList2.end());
	}
	



	// erase 구현 테스트
	//{
	//	List<int> myList;
	//	myList.push_back(10);
	//	myList.push_back(20);
	//	myList.push_back(30);

	//	List<int>::iterator iter;

	//	iter = myList.begin();
	//	++iter;
	//	++iter;
	//	iter = myList.erase(iter);

	//	for (iter = myList.begin(); iter != myList.end(); ++iter)
	//	{
	//		cout << *iter << endl;
	//	}
	//}


	// Insert 구현 테스트
	//{
	//	List<int> myList;
	//	myList.push_back(10);
	//	myList.push_back(20);
	//	myList.push_back(30);

	//	List<int>::iterator iter;

	//	iter = myList.begin();
	//	++iter;
	//	myList.insert(iter, 15);

	//	for (iter = myList.begin(); iter != myList.end(); ++iter)
	//	{
	//		cout << *iter << endl;
	//	}
	//}


	//// Insert 구현 테스트
	//{
	//	List<int> stlList1;
	//	stlList1.push_back(10);
	//	stlList1.push_back(20);
	//	stlList1.push_back(30);
	//
	//	List<int> stlList2;
	//	stlList2.push_back(40);
	//	stlList2.push_back(50);
	//	stlList2.push_back(60);

	//	
	//	stlList1.insert(stlList1.begin(), stlList2.begin(), stlList2.end());

	//	List<int>::iterator iter = stlList1.begin();
	//	for (; iter != stlList1.end(); ++iter)
	//	{
	//		cout << *iter << endl;
	//	}
	//}

	// Insert 구현 테스트
	{
		List<int> stlList1;

		List<int> stlList2;
		stlList2.push_back(40);
		stlList2.push_back(50);
		stlList2.push_back(60);

		stlList1 = stlList2;

		List<int>::iterator iter = stlList1.begin();
		for (; iter != stlList1.end(); ++iter)
		{
			cout << *iter << endl;
		}
	}

	

	return 0;
}