#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account1.h"

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

#endif