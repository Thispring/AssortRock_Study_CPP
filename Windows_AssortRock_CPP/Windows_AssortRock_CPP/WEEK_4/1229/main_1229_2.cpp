// C++ const 함수

class Test
{
private:
	int	m_i;

public:
	// const 맴버함수
	// 이 함수는 호출해도, 맴버를 건드리지 않습니다.
	// const 가 붙은 맴버함수 안에 코드에서는 실제로 맴버를 수정하는 코드가 없어야한다.
	void SetInt(int _Data) //const
	{
		m_i = _Data;
	}

	// 단순히 맴버의 값을 반환하는 Get 류 함수들은 const 맴버함수로 선언해두면 좋다.
	int GetInt() const
	{
		return m_i;
	}

public:
	Test()
		: m_i(0)
	{
	}
};

int main()
{
	Test t;
	t.GetInt();

	return 0;
}