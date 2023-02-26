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

	// ���� ������
	Knight(const Knight& knight)
	{
		_hp = knight._hp;
		_pet = new Pet(*knight._pet); // _pet = knight._pet; <= �������� ���
		
	}

	// ���� ���� ������
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
	// [ ���� ���� Shallow Copy ]
	// ��� �����͸� ��Ʈ�� ������ '�Ȱ���' ���� (�޸� ���� ���� �״�� ����)
	// �����ʹ� �ּҰ� �ٱ��� -> �ּҰ��� �Ȱ��� ���� -> ������ ��ü�� ����Ŵ

	// [ ���� ���� Deep Copy ]
	// ��� �����Ͱ� ����(�ּ�) ���̶��, �����͸� ���� ������ش�. (���� ��ü�� �����ϴ� ������ ���� ���� ����)
	// �����ʹ� �ּҰ� �ٱ��� -> ���ο� ��ü�� ���� -> ���δٸ� ��ü�� ����Ű�� ���°� ��.
	Knight k;
	return 0;
}