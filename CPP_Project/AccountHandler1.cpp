#include "AccountHandler1.h"
#include <iostream>
#include <cstring>
using namespace std;

const int NAME_LEN = 20;

class AccountHandler1
{
private:
	Account1* accArr[100];
	int accNum;
public:
	AccountHandler1()
		: accNum(0)
	{

	}
	~AccountHandler1()
	{
		for (int i = 0; i < 100; ++i)
		{
			delete accArr[i];
		}
	}
	void MakeAccount()
	{
		int id;
		char* name = new char[NAME_LEN];
		int balance;
		cout << "[계좌종류 선택]" << endl;
		// 선택계좌, 이자율, 신용등급
		int selectAcc, interestRate, creditRate;
		cout << "1. 보통예금계좌 2.신용신뢰계좌" << endl;
		cin >> selectAcc;
		if (selectAcc == 1)
		{
			cout << "[계좌개설]" << endl;
			cout << "계좌ID: "; cin >> id;
			cout << "이 름: "; cin >> name;
			cout << "입금액: "; cin >> balance;
			cout << "이자율: "; cin >> interestRate;
			accArr[accNum++] = new NormalAccount(id, balance, name, interestRate);
		}
		else if (selectAcc == 2)
		{

			cout << "[계좌개설]" << endl;
			cout << "계좌ID: "; cin >> id;
			cout << "이 름: "; cin >> name;
			cout << "입금액: "; cin >> balance;
			cout << "이자율: "; cin >> interestRate;
			cout << "신용등급(1toA,2toB,3toC)"; cin >> creditRate;
			accArr[accNum++] = new HighCreditAccount(id, balance, name, interestRate, creditRate);
		}
		else
		{
			cout << "잘못된 접근입니다." << endl;
			return;
		}
	}
	void Deposit()
	{
		int accountID, depositMoney;
		cout << "[입	금]" << endl;
		cout << "계좌ID: "; cin >> accountID;
		cout << "입금액: "; cin >> depositMoney;

		for (int i = 0; i < accNum; ++i)
		{
			if (accArr[i]->GetAccID() == accountID)
			{
				accArr[i]->Deposit(depositMoney);
				cout << "입금완료" << endl << endl;
				return;
			}
		}
	}
	void Withdraw()
	{
		int accountID, withdrawMoney;
		cout << "[출	금]" << endl;
		cout << "계좌ID: "; cin >> accountID;
		cout << "출금액: "; cin >> withdrawMoney;

		for (int i = 0; i < accNum; ++i)
		{
			if (accArr[i]->GetAccID() == accountID)
			{
				if (accArr[i]->GetBalance() < withdrawMoney)
				{
					cout << "잔액부족" << endl << endl;
					return;
				}

				accArr[i]->WithDraw(withdrawMoney);
				cout << "출금완료" << endl << endl;
				return;
			}
		}
		cout << "유효하지 않은 ID 입니다." << endl;
	}
	void OutputInfo()
	{
		for (int i = 0; i < accNum; ++i)
		{
			cout << "계좌ID: " << accArr[i]->GetAccID() << endl;
			cout << "이 름: " << accArr[i]->GetCusName() << endl;
			cout << "잔 액: " << accArr[i]->GetBalance() << endl;
		}
	}
	void Exit()
	{
		exit(0);
	}
};