#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account1.h"

class NormalAccount : public Account1
{
	// ¿Ã¿⁄¿≤
private:
	int interestRate;
public:
	NormalAccount(int _accID, int _balance, char* _cusName, int _interestRate)
		: Account1(_accID, _balance, _cusName), interestRate(_interestRate)
	{
	}
	~NormalAccount()
	{

	}

	virtual void Deposit(int money)
	{
		Account1::Deposit(CalcInterestRate(money));
	}
	virtual void Withdraw(int money)
	{
		Account1::WithDraw(money);
	}
	int CalcInterestRate(int money, int plusRate = 0)
	{
		int tRate = interestRate + plusRate;
		return money * (100 + tRate) / 100;
	}
};

#endif