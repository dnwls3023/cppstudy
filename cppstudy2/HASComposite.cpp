#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
	int bullet;
public:
	Gun(int bnum) : bullet(bnum)
	{}
	void Shot()
	{
		cout << "BBANG!" << endl;
		bullet--;
	}
	void Print()
	{
		cout << "총알의 개수" << bullet << endl;
	}
};

class Police
{
private:
	int handcuffs; // 소유한 수갑의 수
	Gun* pistol; // 소유하고 있는 권총
public:
	Police(int bnum, int bcuff)
		:handcuffs(bcuff)
	{
		if (bnum > 0)
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}
	// TODO 복사생성자
	Police(const Police& ref)
	{
		handcuffs = ref.handcuffs; 
		if (ref.pistol != NULL)
			pistol = new Gun(*ref.pistol);
		else
			pistol = NULL;
	}
	// TODO 대입연산자
	Police& operator=(const Police& ref)
	{
		if(pistol!= NULL)
			delete pistol;

		if (ref.pistol != NULL)
			pistol = new Gun(*ref.pistol);
		else
			pistol = NULL;

		handcuffs = ref.handcuffs;
		return *this;
	}
	void PrintAll()
	{
		pistol->Print();
		cout << "수갑의 개수" << handcuffs << endl;
		cout << endl;
	}
	void PutHandcuff()
	{
		cout << "SNAP!" << endl;
		handcuffs--;
	}
	void Shot()
	{
		if (pistol == NULL)
			cout << "Hut BBANG!" << endl;
		else
			pistol->Shot();
	}
	~Police()
	{
		if (pistol != NULL)
			delete pistol;
	}
};

int main(void)
{
	// 총알의 개수, 수갑의 개수
	Police pman1(5, 3);
	Police pman2(2, 3);
	Police pman3 = pman1;	// 복사 생성자 (깊은복사)
	pman1 = pman2;			// 대입 연산자 (깊은복사) 

	pman2.Shot();
	pman1.PutHandcuff();

	cout << "pman1" << endl;
	pman1.PrintAll();
	cout << "pman2" << endl;
	pman2.PrintAll();
	cout << "pman3" << endl;
	pman3.PrintAll();
	return 0;
}