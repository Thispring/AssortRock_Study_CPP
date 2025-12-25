// class를 이용한 연결리스트 구현하기

#include "List.h"
#include <iostream>

int main()
{
    List myList;
    // myList.push_back(10);
    // myList.push_back(20);
    // myList.push_back(30);

    myList.push_front(10);
    myList.push_front(20);
    myList.push_front(30);
    int a = 0;

    return 0;
}