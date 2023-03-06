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
	// override = 최초 가상함수가 아닌 것을 알려줌.
	virtual void Attack() override
	{
		cout << "Player!" << endl;
	}
};

class Knight : public Player
{
public:
	// final = 더이상 오버라이드를 하지 않겠다는 의미
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