/*
* 
* Banking System Ver 0.1
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
	~Account()
	{
		delete[] cusName;
	}
	
	void SetAccID(int _accID) { accID = _accID; }
	void SetBalance(int _balance) { balance = _balance; }
	void SetCusName(char* _cusName) { strcpy(cusName,_cusName); }
	int GetAccID() { return accID; }
	int GetBalance() { return balance; }
	char* GetCusName() { return cusName; }
};

Account* accArr[100];
int accNum;

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

void MakeAccountFunc() 
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
void DepositFunc() 
{
	int accountID, depositMoney;
	cout << "[��	��]" << endl;
	cout << "����ID: "; cin >> accountID;
	cout << "�Աݾ�: "; cin >> depositMoney;

	for (int i = 0; i < accNum; ++i) 
	{
		if (accArr[i]->GetAccID() == accountID)
		{
			accArr[i].SetBalance(accArr[i].GetBalance() + depositMoney);
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
	}
}
void WithdrawFunc() 
{
	int accountID, withdrawMoney;
	cout << "[��	��]" << endl;
	cout << "����ID: "; cin >> accountID;
	cout << "��ݾ�: "; cin >> withdrawMoney;

	for (int i = 0; i < accNum; ++i)
	{
		if (accArr[i].GetAccID() == accountID)
		{
			if (accArr[i].GetBalance() < withdrawMoney)
			{
				cout << "�ܾ׺���" << endl << endl;
				return;
			}

			accArr[i].SetBalance(accArr[i].GetBalance() - withdrawMoney);
			cout << "��ݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl;
}
void OutputInfoFunc() 
{
	for (int i = 0; i < accNum; ++i) 
	{
		cout << "����ID: " << accArr[i].GetAccID() << endl;
		cout << "�� ��: " << accArr[i].GetCusName() << endl;
		cout << "�� ��: " << accArr[i].GetBalance() << endl;
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