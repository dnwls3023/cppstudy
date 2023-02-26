#include <iostream>
#include <map>
#include "OOP_Project.h"
using namespace std;

map<int,int> m;
map<int, string> nm;

struct BankData {
	string name;
	int money;
};

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

void MakeAccountFunc() 
{
	int id;string name;int depositMoney;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "이 름: "; cin >> name;
	cout << "입금액: "; cin >> depositMoney;

	m[id] = depositMoney;
	nm[id] = name;
}
void DepositFunc() 
{
	int accountID, depositMoney;
	cout << "[입	금]" << endl;
	cout << "계좌ID: "; cin >> accountID;
	cout << "입금액: "; cin >> depositMoney;
	m[accountID] += depositMoney;
	cout << "입금완료" << endl;
}
void WithdrawFunc() 
{
	int accountID, withdrawMoney;
	cout << "[출	금]" << endl;
	cout << "계좌ID: "; cin >> accountID;
	cout << "출금액: "; cin >> withdrawMoney;
	m[accountID] -= withdrawMoney;
}
void OutputInfoFunc() 
{
	int accountID;
	if (m.size() == 1) {
		for (auto iter = m.begin(); iter != m.end(); iter++) 
		{
			cout << "계좌ID: " << iter->first << endl;
			cout << "이 름:" << nm[iter->first] << endl;
			cout << "잔 액:" << iter->second << endl;
		}
	}
	else 
	{
		cout << "찾으시는 계좌ID를 입력하세요" << endl;
		cin >> accountID;

		for (auto iter = m.begin(); iter != m.end(); iter++)
		{
			if (accountID == iter->first) 
			{
				cout << "계좌ID: " << iter->first << endl;
				cout << "이 름:" << nm[iter->first] << endl;
				cout << "잔 액:" << iter->second << endl;
				return;
			}
		}
		cout << "일치하는 계좌ID가 없습니다" << endl;
	}
}
void ExitFunc() 
{
	exit(0);
}

int main(void)
{
	int select = 0;
	
	while (true)
	{
		select = Input();
		switch (select)
		{
		case Type::MakeAccount:
			MakeAccountFunc();
			break;
		case Type::Deposit:
			DepositFunc();
			break;
		case Type::Withdraw:
			WithdrawFunc();
			break;
		case Type::OutputInfo:
			OutputInfoFunc();
			break;
		case Type::Exit:
			ExitFunc();
			break;
		}
	}
	return 0;
}