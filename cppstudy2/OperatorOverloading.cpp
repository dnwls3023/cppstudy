#include <iostream>
using namespace std;

// ������ �����ε�

// ������ vs �Լ�
// �����ڴ� �ǿ������� ����/Ÿ���� �����Ǿ� ����

// ������ �����ε�?
// �ϴ� [������ �Լ�]�� �����ؾ� ��
// �Լ��� ����Լ� vs �����Լ��� �����ϴ� ��ó��, ������ �Լ��� �ΰ��� ������� ���� �� ����.

// ��� ������ �Լ� version
// - a op b ���¿��� �������� �������� ����� (a�� Ŭ�������� ����. a�� '���� �ǿ�����'��� ��)
// - �Ѱ�) a�� Ŭ������ �ƴϸ� ��� ����

// ���� ������ �Լ� version
// - a op b ���¶��, a, b ��θ� ������ �Լ��� �ǿ����ڷ� ������ش�.

// ���� ���� ������
// - ���� �����ڰ� ���� �迡 [ ���� ���� ������ ]�� ���� �˾ƺ���
// �� �� �򰥸��� [���� ������] [���� ������] [���� ���� ������]
// - ���� ���� ������ = ���� ������ ��, �ڱ� �ڽ��� ���� Ÿ���� ���ڷ� �޴� ��
class Position
{
public:
	Position operator+(const Position& arg)
	{
		Position pos;
		pos._x = _x + arg._x;
		pos._y = _y + arg._y;
		return pos;
	}

	Position operator+(int arg)
	{
		Position pos;
		pos._x = _x + arg;
		pos._y = _y + arg;
		return pos;
	}

	bool operator==(const Position& arg)
	{
		Position pos;
		bool x = pos._x == arg._x;
		bool y = pos._y == arg._y;
		return x && y;
	}
public:
	int _x;
	int _y;
};

Position operator+(int a, const Position& b)
{
	Position ret;
	ret._x = a + b._x;
	ret._y = a + b._y;
}

int main(void)
{
	int a = 1;
	int b = 2;

	int c = a + 3.0f;

	Position pos;
	pos._x = 0;
	pos._y = 0;

	Position pos2;
	pos2._x = 1;
	pos2._y = 1;

	Position pos3 = pos + pos2;
	Position pos4 = 3 + pos;
	return 0;
}