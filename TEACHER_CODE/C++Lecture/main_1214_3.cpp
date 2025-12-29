


// 입력으로 들어온 문자열의 문자 개수가 몇개인지 알려주는 
// 문자열에 끝에는 0(널문자)
int GetStrLen(const char* _Str)
{
	int Len = 0;
	
	while (0 != _Str[Len])
	{		
		++Len;
	}

	return Len;
}

// _Dest 은 복사받을 목적지 주소, _Src 는 복사시킬 원본 문자열 시작 주소, _Len 목적지의 허용가능한 공간 개수
bool StrCpy(char* _Dest, const char* _Src, int _Len)
{
	int SrcLen = GetStrLen(_Src);

	// 목적지 공간의 허용치가, Src 문자열을 복사받을만큼 충분하지 않은 경우
	// 실패할 경우 0 반환
	if (_Len <= SrcLen)
		return false;

	for (int i = 0; i < SrcLen + 1; ++i)
	{
		_Dest[i] = _Src[i];
	}

	// 성공 시 1 반환	
	return true;
}

// _Dst 에 문자열 끝에, _Src 가 가리크는 문자열을 이어 붙이기
bool StrCat(char* _Dest, const char* _Src, int _MaxLen)
{
	int DestLen = GetStrLen(_Dest);
	int SrcLen = GetStrLen(_Src);

	// 이어붙인 문자열 길이가, 목적지 허용치를 초과하는 경우
	// 실패할 경우 0 반환
	if (_MaxLen <= DestLen + SrcLen)
		return false;
	
	for (int i = 0; i < SrcLen + 1; ++i)
	{
		_Dest[DestLen + i] = _Src[i];
	}

	// 성공 시 1 반환
	return true;
}


int main()
{
	// 문자열 끝을 알리는 값은 0(널문자)
	char a = 0;

	// 배열을 리터럴로 초기화 할 경우도, 초기화 받을 배열의 요소 개수가 
	// 문자열의 개수 + 1칸 더 여유가 있어야 한다. 널문자가 들어갈 여유공간 1칸
	char Name[6] = "abc";

	// 3 이 반환
	int Len = GetStrLen(Name);
	Len = GetStrLen("Hello");

	char Name2[10] = {};

	// 문자열 복사 함수
	StrCpy(Name2, Name, 10);

	{
		char Test1[10] = "abcdef";
		char Test2[10] = "ghi";

		// Test1 의 문자열이 "abcdefghi" 가 되어야 한다/
		StrCat(Test1, Test2, 10);
	}


	{
		//const char* pStr = "abc";
		//char* pStr2 = pStr;

		char c = 0;
		char* pStr = &c;
		const char* pStr2 = pStr;
	}


	struct CharInfo
	{
		char szName[21];
		int Att;
		int Def;
	};
	int size = sizeof(CharInfo);

	struct Test
	{
		char c;			
		short s;
		short s2;
		int i;
	};

	size = sizeof(Test);


	CharInfo info = {};
	StrCpy(info.szName, "Raimond", 20);

	// 메모리 정렬
	// 구조체 크기
	// 가장 큰 맴버를 기준으로, 메모리 정렬 규칙을 따른다.
	// 가장 큰 맴버 크기의 배수단위로 메모리상에 맴버들이 배치되어야 한다.
	// #pragma pack(1) 전처리를 사용하면, 컴파일러가 구조체의 크기를 맴버의 총 합산으로 계산한다.





	return 0;
}