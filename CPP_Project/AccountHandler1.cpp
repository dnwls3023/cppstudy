#include "AccountHandler1.h"
#include <iostream>
#include <cstring>

#include "NormalAccount.h"
#include "HighCreditAccount.h"

using namespace std;

const int NAME_LEN = 20;

AccountHandler1::AccountHandler1()
	: accNum(0)
{

}
AccountHandler1::~AccountHandler1()
{
	for (int i = 0; i < 100; ++i)
	{
		delete accArr[i];
	}
}
void AccountHandler1::MakeAccount()
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
void AccountHandler1::Deposit()
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
void AccountHandler1::Withdraw()
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
void AccountHandler1::OutputInfo()
{
	for (int i = 0; i < accNum; ++i)
	{
		cout << "����ID: " << accArr[i]->GetAccID() << endl;
		cout << "�� ��: " << accArr[i]->GetCusName() << endl;
		cout << "�� ��: " << accArr[i]->GetBalance() << endl;
	}
}
void AccountHandler1::Exit()
{
	exit(0);
}