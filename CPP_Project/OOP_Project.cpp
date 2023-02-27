/*
* 
* Banking System Ver 0.6
* ���� : OOP �ܰ躰 ������Ʈ�� �⺻ Ʋ ����
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
		// ����Ϸ��� ���� ���� ������ �ִ� ������ ���� ���
		if (balance < money)
		{
			cout << "�ܾ��� �����մϴ�." << endl;
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
	// ������
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
	// �ſ���
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
		cout << "[�������� ����]" << endl;
		// ���ð���, ������, �ſ���
		int selectAcc, interestRate, creditRate;
		cout << "1. ���뿹�ݰ��� 2.�ſ�ŷڰ���" << endl;
		cin >> selectAcc;
		if (selectAcc == 1)
		{
			cout << "[���°���]" << endl;
			cout << "����ID: "; cin >> id;
			cout << "�� ��: "; cin >> name;
			cout << "�Աݾ�: "; cin >> balance;
			cout << "������: "; cin >> interestRate;
			accArr[accNum++] = new NormalAccount(id, balance, name, interestRate);
		}
		else if (selectAcc == 2)
		{

			cout << "[���°���]" << endl;
			cout << "����ID: "; cin >> id;
			cout << "�� ��: "; cin >> name;
			cout << "�Աݾ�: "; cin >> balance;
			cout << "������: "; cin >> interestRate;
			cout << "�ſ���(1toA,2toB,3toC)"; cin >> creditRate;
			accArr[accNum++] = new HighCreditAccount(id, balance, name, interestRate, creditRate);
		}
		else
		{
			cout << "�߸��� �����Դϴ�." << endl;
			return;
		}
	}
	void Deposit()
	{
		int accountID, depositMoney;
		cout << "[��	��]" << endl;
		cout << "����ID: "; cin >> accountID;
		cout << "�Աݾ�: "; cin >> depositMoney;

		for (int i = 0; i < accNum; ++i)
		{
			if (accArr[i]->GetAccID() == accountID)
			{
				accArr[i]->Deposit(depositMoney);
				cout << "�ԱݿϷ�" << endl << endl;
				return;
			}
		}
	}
	void Withdraw()
	{
		int accountID, withdrawMoney;
		cout << "[��	��]" << endl;
		cout << "����ID: "; cin >> accountID;
		cout << "��ݾ�: "; cin >> withdrawMoney;

		for (int i = 0; i < accNum; ++i)
		{
			if (accArr[i]->GetAccID() == accountID)
			{
				if (accArr[i]->GetBalance() < withdrawMoney)
				{
					cout << "�ܾ׺���" << endl << endl;
					return;
				}

				accArr[i]->WithDraw(withdrawMoney);
				cout << "��ݿϷ�" << endl << endl;
				return;
			}
		}
		cout << "��ȿ���� ���� ID �Դϴ�." << endl;
	}
	void OutputInfo()
	{
		for (int i = 0; i < accNum; ++i)
		{
			cout << "����ID: " << accArr[i]->GetAccID() << endl;
			cout << "�� ��: " << accArr[i]->GetCusName() << endl;
			cout << "�� ��: " << accArr[i]->GetBalance() << endl;
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
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "����: "; cin >> selector;
	return selector;
}

enum Type
{
	MakeAccount = 1,// 1. ���� ����
	Deposit,		// 2. �Ա�
	Withdraw,		// 3. ���
	OutputInfo,		// 4. �������� ��ü ���
	Exit,			// 5. ���α׷� ����
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