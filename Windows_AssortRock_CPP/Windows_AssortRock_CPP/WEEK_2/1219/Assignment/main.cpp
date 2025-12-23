#include <iostream>

class Arr
{
private:
	int* pInt;
	int myData;
	int capacity;
	int Size;
public:
	// 1. 데이터 입력함수 push_back 만들기
	void push_back(int _data);
	// 2. 데이터를 꺼내는 GetData 함수 만들기
	int& GetData(int _index);
	// 3. GetData와 동일한 기능을 operator[] 연산자 함수로 구현하기
	int& operator[](int index) 
	{
		return pInt[index];
	}
public:
	// 생성자
	Arr()
	{
		pInt = nullptr;
		myData = 0;
		capacity = 0;
		Size = 0;
	};

	// 소멸자
	~Arr()
	{
		delete[] pInt;
	};
};

void Arr::push_back(int _data)
{
	// 함수 호출시 동적으로 데이터 입력받게 하기
	if (capacity == 0)
	{
		capacity = 4;
		pInt = new int[capacity];	// 동적 공간 capacity크기 만큼 생성
	}
	else if (Size == capacity)
	{
		// 데이터를 유지하면서 재할당
		int* pTemp = new int[capacity * Size];
		for (int i = 0; i < capacity * Size; i++)
		{
			pTemp[i] = pInt[i];
		}
		delete[] pInt;
		pInt = pTemp;

		// 첫 번째 이후 데이터가 들어왔을때, capacity가 4
		// 만약 capacity 보다 Size가 커진다면
	}
	pInt[Size] = _data;
	
	Size++;
}

int& Arr::GetData(int _index)
{
	return pInt[_index];
}

int main()
{
	Arr arr;

	arr.push_back(10);
	arr.push_back(20);
	arr.push_back(30);
	arr.push_back(40);
	arr.push_back(50);
	arr.push_back(60);
	arr.push_back(70);

	std::cout << arr.GetData(0) << std::endl;
	std::cout << arr.GetData(1) << std::endl;
	std::cout << arr.GetData(2) << std::endl;
	std::cout << arr.GetData(3) << std::endl;

	std::cout << std::endl;

	std::cout << arr[4] << std::endl;
	std::cout << arr[5] << std::endl;
	std::cout << arr[6] << std::endl;


	return 0;
}