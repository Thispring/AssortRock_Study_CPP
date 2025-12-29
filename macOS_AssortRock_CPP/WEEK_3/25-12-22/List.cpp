#include "List.h"
#include <iostream>

// 생성자 소멸자
List::List() : mSize(0), mHead(nullptr), mTail(nullptr) {}

List::~List() { std::cout << "List Out" << std::endl; }

// 데이터를 맨 뒤에 추가
void List::push_back(const int &_Data) {
  // 데이터가 들어왔을 때 Node를 새로 생성
  // new로 동적할당하여 생성
  Node *newNode = new Node(_Data);

  if (mSize == 0) {
    // 첫 생성 시 Head와 Tail 모두 newNode를 가리킴
    mHead = newNode;
    mTail = newNode;
  }
  // 첫 생성이 아닐때
  else {
    // mHead는 첫 생성 노드를 가리키고 있는 상태
    mTail->Next = newNode;
    // 새로 생성된 노드의 Prev가 List의 mTail를 가리키게 하는 상태
    newNode->Prev = mTail;
    // mTail은 마지막 노드를 가리고 있는 상태
    mTail = newNode;
  }
  // 생성이 끝나면 데이터가 1개 추가된 것으로 mSize +1연산
  ++mSize;
}

// 데이터를 맨 앞에 추가
void List::push_front(const int &_Data) {
  // 데이터가 들어왔을 때 Node를 새로 생성
  // new로 동적할당하여 생성
  Node *newNode = new Node(_Data);

  if (mSize == 0) {
    // push_back과 동일
    mHead = newNode;
    mTail = newNode;
  }
  else {
    // 꼬리 설정
    newNode->Prev = mTail;
    mTail = mHead->Prev;  
    // 머리 설정
    newNode->Next = mHead;
    mHead = newNode;
  }

  ++mSize;
}