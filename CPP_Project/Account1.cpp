#include "Account1.h"
#include <iostream>
#include <cstring>
using namespace std;

class Account1
{
private:
	int accID;
	int balance;
	char* cusName;
public:
	Account1(int _accID, int _balance, char* _cusName) : accID(_accID), balance(_balance)
	{
		cusName = new char[strlen(_cusName) + 1];
		strcpy(cusName, _cusName);
	}
	Account1(const Account1& copy) : accID(copy.accID), balance(copy.balance)
	{
		cusName = new char[strlen(copy.cusName) + 1];
		strcpy(cusName, copy.cusName);
	}
	~Account1()
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
	void SetCusName(char* _cusName) { strcpy(cusName, _cusName); }
	int GetAccID() const { return accID; }
	int GetBalance() const { return balance; }
	char* GetCusName() const { return cusName; }
};