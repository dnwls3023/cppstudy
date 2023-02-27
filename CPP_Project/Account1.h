#pragma once
class Account1
{
private:
	int accID;
	int balance;
	char* cusName;
public:
	Account1(int _accID, int _balance, char* _cusName);
	Account1(const Account1& copy);
	~Account1();

	virtual void Deposit(int money);
	virtual void WithDraw(int money);
	void SetCusName(char* _cusName);
	int GetAccID() const;
	int GetBalance() const;
	char* GetCusName() const;
};