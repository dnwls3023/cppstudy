/*
* 
* Banking System Ver 0.5
* 내용 : OOP 단계별 프로젝트의 기본 틀 구성
* 
*/

#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

class Account
{
private:
	int accID;
	int balance;
	char* cusName;
public:
	Account(int _accID,int _balance, char* _cusName) : accID(_accID), balance(_balance)
	{ 
		cusName = new char[strlen(_cusName)+1];
		strcpy(cusName, _cusName);
	}
	Account(const Account& copy) : accID(copy.accID), balance(copy.balance)
	{
		cusName = new char[strlen(copy.cusName) + 1];
		strcpy(cusName, copy.cusName);
	}
	~Account()
	{
		delete[] cusName;
	}
	
	void SetAccID(int _accID) { accID = _accID; }
	void SetBalance(int _balance) { balance = _balance; }
	void SetCusName(char* _cusName) { strcpy(cusName,_cusName); }
	int GetAccID() const { return accID; }
	int GetBalance() const { return balance; }
	char* GetCusName() const { return cusName; }
};

class AccountHandler
{
private:
	Account* accArr[100];
	int accNum;
public:
	AccountHandler()
		: accNum(0)
	{
		
	}
	~AccountHandler()
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

		cout << "[계좌개설]" << endl;
		cout << "계좌ID: "; cin >> id;
		cout << "이 름: "; cin >> name;
		cout << "입금액: "; cin >> balance;

		accArr[accNum++] = new Account(id, balance, name);

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
				accArr[i]->SetBalance(accArr[i]->GetBalance() + depositMoney);
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

				accArr[i]->SetBalance(accArr[i]->GetBalance() - withdrawMoney);
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