/*
* 
* Banking System Ver 0.6
* 내용 : OOP 단계별 프로젝트의 기본 틀 구성
* 
*/

#include <iostream>
#include <cstring>

using namespace std;

int Input()
{
	int selector = 0;
	cout << "-----Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택: "; cin >> selector;
	return selector;
}

enum Type
{
	MakeAccount = 1,// 1. 계좌 개설
	Deposit,		// 2. 입금
	Withdraw,		// 3. 출금
	OutputInfo,		// 4. 계좌정보 전체 출력
	Exit,			// 5. 프로그램 종료
};



int main(void)
{
	int select = 0;
	AccountHandler accHandler;

	while (true)
	{
		select = Input();
		switch (select)
		{
		case Type::MakeAccount:
			accHandler.MakeAccount();
			break;
		case Type::Deposit:
			accHandler.Deposit();
			break;
		case Type::Withdraw:
			accHandler.Withdraw();
			break;
		case Type::OutputInfo:
			accHandler.OutputInfo();
			break;
		case Type::Exit:
			accHandler.Exit();
			break;
		}
	}
	return 0;
}