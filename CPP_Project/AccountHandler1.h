#pragma once
class AccountHandler1
{
private:
	Account1* accArr[100];
	int accNum;
public:
	AccountHandler1();
	~AccountHandler1();
	void MakeAccount();
	void Deposit();
	void Withdraw();
	void OutputInfo();
	void Exit();
};
