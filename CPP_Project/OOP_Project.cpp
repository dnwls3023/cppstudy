/*
* 
* Banking System Ver 0.1
* 내용 : OOP 단계별 프로젝트의 기본 틀 구성
* 
*/

#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
const int NAME_LEN = 20;

typedef struct{
	int accID;
	int balance;
	char cusName[NAME_LEN];
}Account;

Account accArr[100];
int accNum;

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
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "이 름: "; cin >> name;
	cout << "입금액: "; cin >> balance;

	accArr[accNum].accID = id;
	accArr[accNum].balance = balance;
	strcpy(accArr[accNum].cusName, name);
	accNum++;
}
void DepositFunc() 
{
	int accountID, depositMoney;
	cout << "[입	금]" << endl;
	cout << "계좌ID: "; cin >> accountID;
	cout << "입금액: "; cin >> depositMoney;

	for (int i = 0; i < accNum; ++i) 
	{
		if (accArr[i].accID == accountID)
		{
			accArr[i].balance += depositMoney;
			cout << "입금완료" << endl << endl;
			return;
		}
	}
}
void WithdrawFunc() 
{
	int accountID, withdrawMoney;
	cout << "[출	금]" << endl;
	cout << "계좌ID: "; cin >> accountID;
	cout << "출금액: "; cin >> withdrawMoney;

	for (int i = 0; i < accNum; ++i)
	{
		if (accArr[i].accID == accountID)
		{
			if (accArr[i].balance < withdrawMoney)
			{
				cout << "잔액부족" << endl << endl;
				return;
			}

			accArr[i].balance -= withdrawMoney;
			cout << "출금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl;
}
void OutputInfoFunc() 
{
	for (int i = 0; i < accNum; ++i) 
	{
		cout << "계좌ID: " << accArr[i].accID << endl;
		cout << "이 름: " << accArr[i].cusName << endl;
		cout << "잔 액: " << accArr[i].balance << endl;
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