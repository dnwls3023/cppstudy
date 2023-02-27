class HighCreditAccount : public NormalAccount
{
	// �ſ���
private:
	int creditRate;
public:
	enum CreditRate { A = 1, B, C };
	HighCreditAccount(int _accID, int _balance, char* _cusName, int _interestRate, int _creditRate)
		: NormalAccount(_accID, _balance, _cusName, _interestRate), creditRate(_creditRate)
	{

	}
	~HighCreditAccount()
	{

	}
	virtual void Deposit(int money)
	{
		Account1::Deposit(CalcInterestRate(money, CalcCreditRate(creditRate)));
	}
	virtual void WithDraw(int money)
	{
		Account1::WithDraw(money);
	}
	int CalcCreditRate(int credit)
	{
		switch (credit)
		{
		case A:
			return 7;
		case B:
			return 4;
		case C:
			return 2;
		}
	}
};
