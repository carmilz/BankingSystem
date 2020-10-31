/*
* 파일이름: AccountHandler.cpp
* 작성자: CarMilZ
* 업데이트 정보: 2020.10.31 Ver 0.7
*/

#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

AccountHandler::AccountHandler() : accNum(0) {}

void AccountHandler::ShowMenu() const
{
	std::cout << "-----Menu-----" << std::endl;
	std::cout << "1. 계좌개설" << std::endl;
	std::cout << "2. 입 금" << std::endl;
	std::cout << "3. 출 금" << std::endl;
	std::cout << "4. 계좌정보 전체 출력" << std::endl;
	std::cout << "5. 프로그램 종료" << std::endl;
}

void AccountHandler::MakeAccount()
{
	int sel;
	std::cout << "[계좌종류선택]" << std::endl;
	std::cout << "1. 보통예금계좌 ";
	std::cout << "2. 신용신뢰계좌" << std::endl;

	std::cout << "선택: ";
	std::cin >> sel;

	std::cout << std::endl;

	if (sel == NORMAL)
		MakeNormalAccount();
	else
		MakeCreditAccount();
}

void AccountHandler::DepositMoney()
{
	int money;
	int id;
	
	std::cout << "[입  금]" << std::endl;
	std::cout << "계좌 ID: "; std::cin >> id;
	std::cout << "입금액: "; std::cin >> money;
	
	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);
			std::cout << "입금완료" << std::endl << std::endl;
			return;
		}
	}
	std::cout << "유효하지 않은 ID입니다." << std::endl << std::endl;
}

void AccountHandler::WithdrawMoney()
{
	int money;
	int id;

	std::cout << "[출  금]" << std::endl;
	std::cout << "계좌 ID: "; std::cin >> id;
	std::cout << "출금액: "; std::cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if(accArr[i]->GetAccID() == id)
		{
			if (accArr[i]->WithDraw(money) == 0)
			{
				std::cout << "잔액부족" << std::endl << std::endl;
			}
			std::cout << "출금완료" << std::endl << std::endl;
			return;
		}
	}
	std::cout << "유효하지 않은 ID입니다." << std::endl << std::endl;
}

void AccountHandler::ShowAllAccInfo() const
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		std::cout << std::endl;
	}
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
		delete accArr[i];
}

void AccountHandler::MakeNormalAccount()
{
	int id;
	std::string name;
	int balance;
	int interRate;

	std::cout << "[보통예금계좌 개설]" << std::endl;
	std::cout << "계좌 ID: "; std::cin >> id;
	std::cout << "이 름: "; std::cin >> name;
	std::cout << "입금액: "; std::cin >> balance;
	std::cout << "이자율: "; std::cin >> interRate;
	std::cout << std::endl;

	accArr[accNum++] = new NormalAccount(id, balance, name, interRate);
}

void AccountHandler::MakeCreditAccount()
{
	int id;
	std::string name;
	int balance;
	int interRate;
	int creditLevel;

	std::cout << "[신용신뢰계좌 개설]" << std::endl;
	std::cout << "계좌 ID: "; std::cin >> id;
	std::cout << "이 름: "; std::cin >> name;
	std::cout << "입금액: "; std::cin >> balance;
	std::cout << "이자율: "; std::cin >> interRate;
	std::cout << "신용등급(1toA, 2toB, 3toC): "; std::cin >> creditLevel;
	std::cout << std::endl;

	switch (creditLevel)
	{
	case 1:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_A);
		break;
	case 2:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
		break;
	case 3:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_C);
		break;
	}
}
