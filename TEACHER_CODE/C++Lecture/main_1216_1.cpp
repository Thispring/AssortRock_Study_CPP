#include <stdlib.h>
#include <string>


// _Src1 이 더 우열이 높으면 -1 반환
// _Src2 이 더 우열이 높으면 1 반환
// 두 문자열이 모두 일치하면, 0 반환
int StrCmp(const char* _Src1, const char* _Src2)
{
	// 두 문자열중, 두 길이가 작은 문자열의 길이를 가져온다.
	int LeftLen = strlen(_Src1);
	int RightLen = strlen(_Src2);

	int Len = 0;

	// 삼항 연산자
	LeftLen < RightLen ? Len = LeftLen : Len = RightLen;

	/*if (LeftLen < RightLen)
		Len = LeftLen;
	else
		Len = RightLen;*/

	for (int i = 0; i < Len; ++i)
	{
		if (_Src1[i] < _Src2[i])
		{
			return -1;
		}
		else if(_Src1[i] > _Src2[i])
		{
			return 1;
		}
	}

	if (LeftLen == RightLen)
		return 0;
	else if (LeftLen < RightLen)
		return -1;
	else 
		return 1;
}

// abc abcd






// 지역변수, 전역변수, 정적변수, 외부변수
// 스택      데이터

// 스택
// 데이터
// 코드(ROM)
// 힙 (동적할당)

int main()
{
	void* pVoid = nullptr;
	//char* pChar = pVoid;


	// 동적할당
	// 힙 메모리 영역에, 필요한 바이트 수 만큼 메모리를 요청하고, 할당 된 메모리의 시작 주소를 받는다.
	// 메모리의 시작 주소는 void* 타입이다. 요청한 쪽에서 어떤 용도로 사용할지 모르기 때문
	// 동적할당을 요청한 측에서는, 자신이 요청한 메모리 공간을 어떤 목적으로 사용할 것인지에 따라
	// 알맞은 자료형 포인터를 이용해서 할당받은 곳을 가리키고, 접근한다.

	// Memory Allocate
	// 4바이트 동적할당, int 1개 저장 목적으로 사용
	int* pInt = (int*)malloc(4);
	*pInt = 100;

	// 4바이트 동적할당, char 4개 배열목적으로 사용
	char* pChar = (char*)malloc(4);
	pChar[0] = 1;
	pChar[1] = 2;
	pChar[2] = 3;
	pChar[3] = 4;

	// 프로그램 종료 전에, 동적할당 받은 힙 공간을 메모리 해제시켜야 한다.
	free(pInt);
	free(pChar);

	// 문자열 비교
	char ID[20] = "abcde";
	char ID_OTHER[20] = "kbcd";

	int result = StrCmp(ID, ID_OTHER);
	
	//wcscmp();
	//strcmp();

	return 0;
}