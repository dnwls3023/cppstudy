/*
* 
* Banking System Ver 0.5
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

		cout << "[���°���]" << endl;
		cout << "����ID: "; cin >> id;
		cout << "�� ��: "; cin >> name;
		cout << "�Աݾ�: "; cin >> balance;

		accArr[accNum++] = new Account(id, balance, name);

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
				accArr[i]->SetBalance(accArr[i]->GetBalance() + depositMoney);
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

				accArr[i]->SetBalance(accArr[i]->GetBalance() - withdrawMoney);
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