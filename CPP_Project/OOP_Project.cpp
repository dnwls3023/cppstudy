/*
* 
* Banking System Ver 0.6
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
	
	virtual void Deposit(int money)
	{
		balance += money;
	}
	virtual void WithDraw(int money)
	{
		// 출금하려는 돈이 지금 가지고 있는 돈보다 많을 경우
		if (balance < money)
		{
			cout << "잔액이 부족합니다." << endl;
			return;
		}

		balance -= money;
	}
	void SetCusName(char* _cusName) { strcpy(cusName,_cusName); }
	int GetAccID() const { return accID; }
	int GetBalance() const { return balance; }
	char* GetCusName() const { return cusName; }
};

class NormalAccount : public Account
{
	// 이자율
private:
	int interestRate;
public:
	NormalAccount(int _accID,int _balance,char* _cusName, int _interestRate)
		: Account(_accID,_balance,_cusName), interestRate(_interestRate)
	{
	}
	~NormalAccount()
	{

	}

	virtual void Deposit(int money)
	{
		Account::Deposit(CalcInterestRate(money));
	}
	virtual void Withdraw(int money)
	{
		Account::WithDraw(money);
	}
	int CalcInterestRate(int money,int plusRate=0)
	{
		int tRate = interestRate + plusRate;
		return money * (100 + tRate) / 100;
	}
};

class HighCreditAccount : public NormalAccount
{
	// 신용등급
private:
	int creditRate;
public:
	enum CreditRate { A = 1, B, C };
	HighCreditAccount(int _accID, int _balance, char* _cusName, int _interestRate, int _creditRate)
		: NormalAccount(_accID,_balance, _cusName,_interestRate),creditRate(_creditRate)
	{

	}
	~HighCreditAccount()
	{

	}
	virtual void Deposit(int money)
	{
		Account::Deposit(CalcInterestRate(money, CalcCreditRate(creditRate) ) );
	}
	virtual void WithDraw(int money)
	{
		Account::WithDraw(money);
	}
	int CalcCreditRate(int credit)
	{
		switch (credit)
		{
		case A:
			return 7;
		case B:
			return 4;
		case C:
			return 2;
		}
	}
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