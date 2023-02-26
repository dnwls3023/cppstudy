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
	int id;string name;int depositMoney;

	cout << "[���°���]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�� ��: "; cin >> name;
	cout << "�Աݾ�: "; cin >> depositMoney;

	m[id] = depositMoney;
	nm[id] = name;
}
void DepositFunc() 
{
	int accountID, depositMoney;
	cout << "[��	��]" << endl;
	cout << "����ID: "; cin >> accountID;
	cout << "�Աݾ�: "; cin >> depositMoney;
	m[accountID] += depositMoney;
	cout << "�ԱݿϷ�" << endl;
}
void WithdrawFunc() 
{
	int accountID, withdrawMoney;
	cout << "[��	��]" << endl;
	cout << "����ID: "; cin >> accountID;
	cout << "��ݾ�: "; cin >> withdrawMoney;
	m[accountID] -= withdrawMoney;
}
void OutputInfoFunc() 
{
	int accountID;
	if (m.size() == 1) {
		for (auto iter = m.begin(); iter != m.end(); iter++) 
		{
			cout << "����ID: " << iter->first << endl;
			cout << "�� ��:" << nm[iter->first] << endl;
			cout << "�� ��:" << iter->second << endl;
		}
	}
	else 
	{
		cout << "ã���ô� ����ID�� �Է��ϼ���" << endl;
		cin >> accountID;

		for (auto iter = m.begin(); iter != m.end(); iter++)
		{
			if (accountID == iter->first) 
			{
				cout << "����ID: " << iter->first << endl;
				cout << "�� ��:" << nm[iter->first] << endl;
				cout << "�� ��:" << iter->second << endl;
				return;
			}
		}
		cout << "��ġ�ϴ� ����ID�� �����ϴ�" << endl;
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