/*
* 
* Banking System Ver 0.6
* ���� : OOP �ܰ躰 ������Ʈ�� �⺻ Ʋ ����
* 
*/

#include <iostream>
#include <cstring>

using namespace std;

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



int main(void)
{
	int select = 0;
	AccountHandler accHandler;

	while (true)
	{
		select = Input();
		switch (select)
		{
		case Type::MakeAccount:
			accHandler.MakeAccount();
			break;
		case Type::Deposit:
			accHandler.Deposit();
			break;
		case Type::Withdraw:
			accHandler.Withdraw();
			break;
		case Type::OutputInfo:
			accHandler.OutputInfo();
			break;
		case Type::Exit:
			accHandler.Exit();
			break;
		}
	}
	return 0;
}