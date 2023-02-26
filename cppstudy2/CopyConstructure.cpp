#include <iostream>
using namespace std;

class Pet
{
public:
	Pet()
	{
		cout << "~Pet()" << endl;
	}
	~Pet()
	{
		cout << "~Pet()" << endl; 
	}
	Pet(const Pet& pet)
	{
		cout << "Pet(const Pet&)" << endl;
	}
};

class Knight
{
public:
	Knight()
	{
		_pet = new Pet();
	}

	// 복사 생성자
	Knight(const Knight& knight)
	{
		_hp = knight._hp;
		_pet = new Pet(*knight._pet); // _pet = knight._pet; <= 얕은복사 방식
		
	}

	// 복사 대입 연산자
	Knight& operator=(const Knight& knight)
	{
		_hp = knight._hp;
		_pet = new Pet(*knight._pet);
		return *this;
	}

	~Knight()
	{
		delete _pet;
	}
public:
	int _hp = 100;
	Pet* _pet;
};

int main(void) 
{
	// [ 얕은 복사 Shallow Copy ]
	// 멤버 데이터를 비트열 단위로 '똑같이' 복사 (메모리 영역 값을 그대로 복사)
	// 포인터는 주소값 바구니 -> 주소값을 똑같이 복사 -> 동일한 객체를 가리킴

	// [ 깊은 복사 Deep Copy ]
	// 멤버 데이터가 참조(주소) 값이라면, 데이터를 새로 만들어준다. (원본 객체가 참조하는 대상까지 새로 만들어서 복사)
	// 포인터는 주소값 바구니 -> 새로운 객체를 생성 -> 서로다른 객체를 가리키는 상태가 됨.
	Knight k;
	return 0;
}