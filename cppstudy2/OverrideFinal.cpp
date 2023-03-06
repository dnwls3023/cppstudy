#include <iostream>
using namespace std;

// override final
class Creature
{
	virtual void Attack()
	{
		cout << "Creature!" << endl;
	}
};

class Player : public Creature
{
public:
	// override = ���� �����Լ��� �ƴ� ���� �˷���.
	virtual void Attack() override
	{
		cout << "Player!" << endl;
	}
};

class Knight : public Player
{
public:
	// final = ���̻� �������̵带 ���� �ʰڴٴ� �ǹ�
	virtual void Attack() final
	{
		cout << "Knight!" << endl;
	}
};

int main(void)
{
	Player* p = new Knight();
	p->Attack();
	return 0;
}