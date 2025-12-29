#pragma once
#include <assert.h>
// 템플릿에 관한 자료
// https://koey.tistory.com/113

// ===================
// TODO 1224: 
// 연결형 리스트 템플릿화
// ===================

// 멤버 함수는 외부에 따로 구현 후 정리해서 보기 편하게 하기
// 생성, 소멸자는 내부에서 모두 구현

// ==========
// Node 선언부
// ==========
template <typename T>
struct Node
{
	T		Data;
	Node*	Next;
	Node*	Prev;

	Node() : Data(), Next(nullptr), Prev(nullptr) {}
	Node(const T& _Data) : Data(_Data), Next(nullptr), Prev(nullptr) {}
	// 인수를 3개 받는 생성자 구현
	Node(const T& _Data, Node* _Next, Node* _Prev) : Data(_Data), Next(_Next), Prev(_Prev) {}
};

// ==========
// List 선언부
// ==========
template <typename T>
class List
{
private:
	Node<T>*		m_Head;
	Node<T>*		m_Tail;
	T				m_Size;	// 연결 리스트의 총 길이

public:
	// 데이터를 맨 뒤에 추가
	void push_back(const T& _Data);

	// 데이터를 맨 앞에 추가
	void push_front(const T& _Data);

	// 맨 뒤 데이터 제거
	void pop_back();

	// 맨 앞 데이터 제거
	void pop_front();

	// reverse_recursive를 호출하여, List가 연결한 Node 데이터를 역순으로 뒤집기
	void reverse();

	class iterator;

	iterator begin() { return iterator(this, m_Head); }
	iterator end() { return iterator(this, nullptr); }
	// iterator가 가리키는 컨테이너를 지우고, iterator가 가리키는 다음 주소를 반환
	iterator erase(const iterator& _iter);
	// 삽입 대상 Node 뒤에다가 데이터를 추가로 삽입
	void insert(const iterator& _iter, const T& _Data);
	// 다른 List의 지정된 시작위치와 끝까지 한꺼번에 삽입대상인 _Where 뒤에다가 복사
	void insert(const iterator& _Where, const iterator& _Begin, const iterator& _End);
	// 대입 연산자(List끼리 모든 요소 복사)
	List<T>& operator=(const List<T>& _Other);
	
private:
	// 재귀함수를 이용해, Node의 연결을 바꾸어 역순으로 뒤집기
	void reverse_recursive(Node<T>* _Node);

public:
	List() : m_Head(nullptr), m_Tail(nullptr), m_Size() {};
	// 소멸자 구현하기, 남아있는 Node가 있다면 해제 작업
	~List()
	{
		// 해당 조건에 걸리면 아직 남아있는 Node가 있다는 뜻이므로 찾아서 해제
		if (m_Size != 0 && m_Head->Next != nullptr && m_Tail->Prev != nullptr)
		{
			while (m_Size != 0)
			{
				pop_back();
			}
		}
	};

// =========================
// List의 iterator class 구현
// =========================
public:
	// 자료구조의 특징을 생각하여 구현하기
	// 연결형 리스트는 연속적인 데이터 구조가 아님
	// -> 많은 데이터가 저장된 상태에서 인덱싱으로 
	// 자료를 찾을 경우에 속도가 많이 느림
	// -> 자기가 가리키고 있는 Node의 주소를 바로 전달
	class iterator
	{
	private:
		List<T>* m_Owner;
		Node<T>* m_Node;	// m_Owner가 nullptr가 아니고 m_Node는 nullptr인 경우
	
	// 멤버 함수
	public:
		// 대입연산은 List를 가리키는 포인터인 m_Owner가 같은 List를 가리키는지 확인, Node도 같은 걸 가리키는지 확인
		bool operator == (const iterator& _other) { return m_Owner == _other.m_Owner && m_Node == _other.m_Node; }

		bool operator != (const iterator& _other) { return m_Owner != _other.m_Owner }

		T& operator*() 
		{
			// 예외처리, iterator가 가리키는게 null이라면
			assert(m_Owner);
			return m_Node->Data; 
		}

		iterator& operator ++()
		{
			// 예외처리
			assert(m_Owner);

			// 호출된 iterator의 Node 포인터가 다음을 가리킬 수 있게 대입
			this->m_Node = this->m_Node->Next;

			return *this;
		}

		iterator& operator ++(int)
		{
			// 예외처리
			assert(m_Owner);

			// 후위연산의 동작 방식은 시퀀스 포인트가 모두 끝난 후 +1을 연산
			// 비슷한 동작을 하기 위해 임시 List 객체를 생성하고, 호출한 객체의 값을 복사
			// 호출한 객체는 다음 객체를 가리킬 수 있게 변경한 후
			// 실제 return의 주소는 임시 List의 주소를 전달

			iterator Copy = *this;
			++(*this);
			return Copy;
		}

		iterator& operator --()
		{
			// 예외처리
			assert(m_Owner);

			// 호출된 위치에 따라 분기 만약 end()를 가리킨 상태라면?
			// m_Node이 -1이면 end라고 약속함
			if (m_Node == nullptr)
			{
				// end의 이전을 가리키게 변경
				// 실제 Node의 마지막을 가리키는건 Tail
				m_Node = m_Owner->m_Tail;
			}
			else
			{
				// 예외처리
				if (m_Node->Prev != nullptr)
				{
					// 호출된 iterator의 Node 포인터가 이전을 가리킬 수 있게 대입
					m_Node = m_Node->Prev;
				}
			}

			return *this;
		}

		iterator& operator --(int)
		{
			// 예외처리
			assert(m_Owner);

			iterator Copy = *this;
			--(*this);
			return Copy;
		}

	// 생성, 소멸자
	public:
		iterator() : m_Owner(nullptr), m_Node(nullptr) {}
		iterator(List<T>* _Owner, Node<T>* _Node) : m_Owner(_Owner), m_Node(_Node) {}
		// 디폴트 소멸자 사용
	};
};

// ===================
// List 멤버 함수 구현부
// ===================

template <typename T>
void List<T>::push_back(const T& _Data) {
	
	// new 키워드를 사용해서 Node<T>만큼 객체를 새로 생성
	Node<T>* pNewNode = new Node<T>(_Data);

	// 분기를 최초 생성과 최초 생성이 아닐때로 나눔
	if (m_Size == 0)
	{
		// Head와 Tail모두 새 노드를 가리킴
		m_Head = m_Tail = pNewNode;
	}
	else
	{
		// Tail이 가리키고 있던 노드(이전 생성 노드)의 Next를 새로 생성한 노드로 연결
		m_Tail->Next = pNewNode;
		// 새로 생성한 노드의 이전을 가리키는 포인터는(현재 null) Tail(이전 생성 노드를 가리킴)을 가리키게 함
		pNewNode->Prev = m_Tail;
		// Tail을 새로 생성한 노드로 연결(함수 다시 실행 시, Tail은 이전 생성 노드를 가리키게 됨)
		m_Tail = pNewNode;
	}

	++m_Size;
}

template <typename T>
void List<T>::push_front(const T& _Data) {
	// 호출 시 Node*를 만들어 동적할당, Node 생성자에 _Data인자를 받아 int 인자를 받는 생성자 호출
	Node<T>* pNewNode = new Node<T>(_Data);

	// 추가된 데이터 개수에 따라 조건 분기
	if (m_Size == 0)
	{
		m_Head = m_Tail = pNewNode;
	}
	else
	{
		pNewNode->Next = m_Head;
		m_Head->Prev = pNewNode;
		m_Head = pNewNode;
	}

	// 추가될 때마다 +1
	++m_Size;
}

// delete[] vs delete 사용 오류
// pTemp 없이 pop함수 구현해보기
template <typename T>
void List<T>::pop_back() {
	// 데이터가 없는 상태에서 호출하면 안되므로, 오류 호출
	assert(m_Size != 0);

	// 데이터가 1개만 있다면
	if (m_Size == 1)
	{
		// Head가 가리키는 공간 데이터 해제
		delete m_Head;
		// 가리키는 포인터가 사라졌으므로 nullptr로 초기화
		m_Head = m_Tail = nullptr;
	}
	// 데이터가 여러 개 라면
	else
	{
		// 임시 주소를 저장할 Node를 생성하고, Tail의 Prev(삭제할 Node의 이전) 주소를 저장
		Node<T>* pTemp = m_Tail->Prev;
		delete m_Tail;	// Tail이 가리키고 있는 마지막 Node 해제
		m_Tail = pTemp;	// pTemp의 주소를 백업 받음
		m_Tail->Next = nullptr;
	}
	
	// 삭제가 완료되면 -1
	--m_Size;
}

template <typename T>
void List<T>::pop_front() {
	// 데이터가 없는 상태에서 호출하면 안되므로, 오류 호출
	assert(m_Size != 0);

	if (m_Size == 1)
	{
		delete m_Head;
		// 가리키는 포인터가 사라졌으므로 nullptr로 초기화
		m_Head = m_Tail = nullptr;
	}
	else
	{
		// Head가 가리키는 Next의 주소를 백업하고, Head가 가리키는
		// 맨 앞 노드를 해제 후, 해당 주소를 가져오기
		Node<T>* pTemp = m_Head->Next;
		delete m_Head;
		m_Head = pTemp;
		m_Head->Prev = nullptr;
	}

	// 삭제가 완료되면 -1
	--m_Size;
}

template <typename T>
void List<T>::reverse() {
	reverse_recursive(m_Head);
}

template<typename T>
void List<T>::reverse_recursive(Node<T>* _Node) {
	// 자기 자신을 다시 호출해야하므로, _Node가 가리키는 주소가 nullptr일 때를 종료 조건으로 설정
	if (_Node->Next == nullptr)
	{
		// 종료조건
	}
	// 스택이 풀리면서 가리키는 곳을 바꾸도록 구현하기
}

// =====================
// iterator 멤버 함수 구현
// =====================
// template <typename T>
// 반환타입 외부클래스<T>::중첩클래스::함수명(매개변수)

template<typename T>
typename List<T>::iterator List<T>::erase(const iterator& _iter) {
	// iterator 레퍼런스를 매개변수로 받아, 현재 iterator가 가리키는 컨테이너에 접근해
	// 해당 컨테이너를 delete하고(new로 동적할당하여, 공간을 추가했기 때문) 반환값으로
	// 지워진 iterator의 다음을 반환

	// 예외처리로 매개변수 _iter가 가리키는 곳이 nullptr이거나, Data가 없는 상황에서 호출을 방지
	// 혹은 end위치에서 호출하려고 했을 때
	assert(_iter.m_Owner != nullptr || _iter.m_Node != -1);
	
	// 만약 삭제시킬 Node가 첫번째라면
	if (_iter.m_Owner == _iter.begin())
	{

	}
	// 만약 삭제시킬 Node가 마지막이라면
	else if (_iter.m_Owner == _iter.end())
	{

	}
	// 지우려는 Node 앞, 뒤로 Node가 있는 상황이라면
	// 현재 Node의 Next가 가리키는 곳을 이전 Node가 가리키게
	// 현재 Node의 Prev가 가리키는 곳을 다음 Node가 가리키게 바꿔주기
	//
	// 매개변수로 받은 iter가 가리키는 Node의 Next는 다음 Node를 가리킴
	else
	{
		_iter.m_Node->Next->Prev = _iter.m_Node->Prev;
		_iter.m_Node->Prev->Next = _iter.m_Node->Next;
		--m_Size;
	}


	return iterator();
}

template<typename T>
void List<T>::insert(const iterator& _iter, const T& _Data) {

}

template<typename T>
void List<T>::insert(const iterator& _Where, const iterator& _Begin, const iterator& _End) {

}

template <typename T>
List<T>& List<T>::operator=(const List<T>& _Other) {

}