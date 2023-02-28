#include <iostream>
using namespace std;

// 연산자 오버로딩

// 연산자 vs 함수
// 연산자는 피연산자의 개수/타입이 고정되어 있음

// 연산자 오버로딩?
// 일단 [연산자 함수]를 정의해야 함
// 함수도 멤버함수 vs 전역함수가 존재하는 것처럼, 연산자 함수도 두가지 방식으로 만들 수 있음.

// 멤버 연산자 함수 version
// - a op b 형태에서 왼쪽으로 기준으로 실행됨 (a가 클래스여야 가능. a를 '기준 피연산자'라고 함)
// - 한계) a가 클래스가 아니면 사용 못함

// 전역 연산자 함수 version
// - a op b 형태라면, a, b 모두를 연산자 함수의 피연산자로 만들어준다.

// 복사 대입 연산자
// - 대입 연산자가 나온 김에 [ 복사 대입 연산자 ]에 대해 알아보자
// 용어가 좀 헷갈린다 [복사 생성자] [대입 연산자] [복사 대입 연산자]
// - 복사 대입 연산자 = 대입 연산자 중, 자기 자신의 참조 타입을 인자로 받는 것
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