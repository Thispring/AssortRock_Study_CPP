#include <stdio.h>
#include <wchar.h>
#include <iostream>
#include <io.h>
#include <fcntl.h>

// 유저 정보 입력 프로그램
struct UserInfo
{
	wchar_t ID[20];
	wchar_t Adress[256];
	int		Age;
};


// 전역변수
// 데이터 영역 - 프로그램 시작시, 종료시
UserInfo g_UserInfo[100] = {};
int		 g_UserCount = 0;


// 문제점 
// 1. 프로그램이 실행 도중에, 가변적인 유저 수에 대응이 안됨
// 2. 프로그램이 종료되면 입력한 정보가 다 사라진다. 
//    ==> 파일 입출력을 통해서, 유저정보를 파일로 저장해놨어야 한다.



void InputUserInfo()
{
	wprintf(L"ID 를 입력하세요\n");
	wscanf_s(L"%s", g_UserInfo[g_UserCount].ID, 20);

	wprintf(L"주소를 입력하세요\n");
	wscanf_s(L"%s", g_UserInfo[g_UserCount].Adress, 256);

	wprintf(L"나이 를 입력하세요\n");
	wscanf_s(L"%d", &g_UserInfo[g_UserCount].Age);		

	++g_UserCount;
}

void SearchUserInfo()
{

}

int main()
{
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);
		
	fflush(stdin);

	int Input = 0;

	while (1)
	{
		wprintf(L"1. 유저 정보 입력\n");
		wprintf(L"2. 유저 정보 확인\n");
		wprintf(L"3. 종료\n");
				
		wscanf_s(L"%d", &Input);

		bool Exit = false;

		switch (Input)
		{
		case 1:
			InputUserInfo();
			break;

		case 2:
			SearchUserInfo();
			break;

		case 3:
			Exit = true;
			break;
		default:
			break;
		}

		if (Exit)
			break;

		system("cls");
	}

	return 0;
}

