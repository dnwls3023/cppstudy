#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x =0,int y=0) : xpos(x),ypos(y)
	{}
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	friend Point operator+(const Point& pos1, const Point& pos2);
	friend Point operator-(const Point& pos1, const Point& pos2);
	friend bool operator==(const Point& pos1, const Point& pos2);
	friend bool operator!=(const Point& pos1, const Point& pos2);
	
	// ! 문제 10-1의 2번문제
	Point& operator+=(const Point& ref)
	{
		xpos += ref.xpos;
		ypos += ref.ypos;
		return *this;
	}

	Point& operator-=(const Point& ref)
	{
		xpos -= ref.xpos;
		ypos -= ref.ypos;
		return *this;
	}
};

Point operator+(const Point& pos1, const Point& pos2)
{
	return Point(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
}

// 문제 10-1의 1번문제
Point operator-(const Point& pos1, const Point& pos2)
{
	return Point(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
}

// 문제 10-1의 3번문제
bool operator==(const Point& pos1, const Point& pos2)
{
	return (pos1.xpos == pos2.xpos) && (pos1.ypos == pos2.ypos);
}

bool operator!=(const Point& pos1, const Point& pos2)
{
	return !(pos1 == pos2);
}


int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1 + pos2;

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	return 0;
}