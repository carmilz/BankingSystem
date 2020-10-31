/*
* 소프트웨어 버전: Bangking System Ver 0.7
* 
* 파일이름: Account.cpp
* 작성자: CarMilZ
* 업데이트 정보: 2020.10.31 Ver 0.7
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
		std::cout << "선택: ";
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
			std::cout << "오류: 잘못된 선택입니다." << std::endl << std::endl;
		}
	}

	return 0;
}