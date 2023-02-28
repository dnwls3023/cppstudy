#include "Account1.h"
#include <iostream>
#include <cstring>
using namespace std;

Account1::Account1(int _accID, int _balance, char* _cusName) : accID(_accID), balance(_balance)
{
	cusName = new char[strlen(_cusName) + 1];
	strcpy(cusName, _cusName);
}

Account1::Account1(const Account1& copy) : accID(copy.accID), balance(copy.balance)
{
	cusName = new char[strlen(copy.cusName) + 1];
	strcpy(cusName, copy.cusName);
}

Account1::~Account1()
{
	delete[] cusName;
}

void Account1::Deposit(int money)
{
	balance += money;
}
void Account1::WithDraw(int money)
{
	// ����Ϸ��� ���� ���� ������ �ִ� ������ ���� ���
	if (balance < money)
	{
		cout << "�ܾ��� �����մϴ�." << endl;
		return;
	}

	balance -= money;
}
void Account1::SetCusName(char* _cusName) { strcpy(cusName, _cusName); }
int Account1::GetAccID() const { return accID; }
int Account1::GetBalance() const { return balance; }
char* Account1::GetCusName() const { return cusName; }