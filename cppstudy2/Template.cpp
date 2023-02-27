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

// ���ø� Ư��ȭ
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

// ������ �����ε� (�����Լ� ����)
ostream& operator<<(ostream& os, const Knight& k)
{
	os << k._hp;
	return os;
}

int main(void)
{
	// ���ø� : �Լ��� Ŭ������ ���� ��
	// 1) �Լ� ���ø�
	// 2) Ŭ���� ���ø�

	Print<int>(50);
	Print(50.0f);
	Print(50.0);
	Print("Hello World!");
	
	Knight k;
	Print(k);
}