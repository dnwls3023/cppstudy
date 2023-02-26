/*
* 
* Banking System Ver 0.1
* ���� : OOP �ܰ躰 ������Ʈ�� �⺻ Ʋ ����
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
	char name[NAME_LEN];
	int balance;

	cout << "[���°���]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�� ��: "; cin >> name;
	cout << "�Աݾ�: "; cin >> balance;

	accArr[accNum].accID = id;
	accArr[accNum].balance = balance;
	strcpy(accArr[accNum].cusName, name);
	accNum++;
}
void DepositFunc() 
{
	int accountID, depositMoney;
	cout << "[��	��]" << endl;
	cout << "����ID: "; cin >> accountID;
	cout << "�Աݾ�: "; cin >> depositMoney;

	for (int i = 0; i < accNum; ++i) 
	{
		if (accArr[i].accID == accountID)
		{
			accArr[i].balance += depositMoney;
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
		if (accArr[i].accID == accountID)
		{
			if (accArr[i].balance < withdrawMoney)
			{
				cout << "�ܾ׺���" << endl << endl;
				return;
			}

			accArr[i].balance -= withdrawMoney;
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
		cout << "����ID: " << accArr[i].accID << endl;
		cout << "�� ��: " << accArr[i].cusName << endl;
		cout << "�� ��: " << accArr[i].balance << endl;
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