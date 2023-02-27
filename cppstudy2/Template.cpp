#include <iostream>
using namespace std;

class Knight
{
public:
	int _hp;
};

template<typename T>
void Print(T a)
{
	cout << a << endl;
}

// 템플릿 특수화
template<>
void Print(Knight k)
{
	cout << "Knight" << endl;
	cout << k._hp << endl;
}

template<typename T1, typename T2>
void Print(T1 a, T2 b)
{
	cout << a << " " << b << endl;
}

// 연산자 오버로딩 (전역함수 버전)
ostream& operator<<(ostream& os, const Knight& k)
{
	os << k._hp;
	return os;
}

int main(void)
{
	// 템플릿 : 함수나 클래스를 찍어내는 툴
	// 1) 함수 템플릿
	// 2) 클래스 템플릿

	Print<int>(50);
	Print(50.0f);
	Print(50.0);
	Print("Hello World!");
	
	Knight k;
	Print(k);
}