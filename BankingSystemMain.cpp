/*
* ����Ʈ���� ����: Bangking System Ver 0.7
* 
* �����̸�: Account.cpp
* �ۼ���: CarMilZ
* ������Ʈ ����: 2020.10.31 Ver 0.7
*/

#include "BankingCommonDecl.h"
#include "AccountHandler.h"

int main()
{
	AccountHandler manager;
	int choice;

	while (1)
	{
		manager.ShowMenu();
		std::cout << "����: ";
		std::cin >> choice;
		std::cout << std::endl;

		switch (choice)
		{
		case MAKE:
			manager.MakeAccount();
			break;
		case DEPOSIT:
			manager.DepositMoney();
			break;
		case WITHDRAW:
			manager.WithdrawMoney();
			break;
		case INQUIRE:
			manager.ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			std::cout << "����: �߸��� �����Դϴ�." << std::endl << std::endl;
		}
	}

	return 0;
}