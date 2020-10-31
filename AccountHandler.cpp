/*
* �����̸�: AccountHandler.cpp
* �ۼ���: CarMilZ
* ������Ʈ ����: 2020.10.31 Ver 0.7
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
	std::cout << "1. ���°���" << std::endl;
	std::cout << "2. �� ��" << std::endl;
	std::cout << "3. �� ��" << std::endl;
	std::cout << "4. �������� ��ü ���" << std::endl;
	std::cout << "5. ���α׷� ����" << std::endl;
}

void AccountHandler::MakeAccount()
{
	int sel;
	std::cout << "[������������]" << std::endl;
	std::cout << "1. ���뿹�ݰ��� ";
	std::cout << "2. �ſ�ŷڰ���" << std::endl;

	std::cout << "����: ";
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
	
	std::cout << "[��  ��]" << std::endl;
	std::cout << "���� ID: "; std::cin >> id;
	std::cout << "�Աݾ�: "; std::cin >> money;
	
	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);
			std::cout << "�ԱݿϷ�" << std::endl << std::endl;
			return;
		}
	}
	std::cout << "��ȿ���� ���� ID�Դϴ�." << std::endl << std::endl;
}

void AccountHandler::WithdrawMoney()
{
	int money;
	int id;

	std::cout << "[��  ��]" << std::endl;
	std::cout << "���� ID: "; std::cin >> id;
	std::cout << "��ݾ�: "; std::cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if(accArr[i]->GetAccID() == id)
		{
			if (accArr[i]->WithDraw(money) == 0)
			{
				std::cout << "�ܾ׺���" << std::endl << std::endl;
			}
			std::cout << "��ݿϷ�" << std::endl << std::endl;
			return;
		}
	}
	std::cout << "��ȿ���� ���� ID�Դϴ�." << std::endl << std::endl;
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

	std::cout << "[���뿹�ݰ��� ����]" << std::endl;
	std::cout << "���� ID: "; std::cin >> id;
	std::cout << "�� ��: "; std::cin >> name;
	std::cout << "�Աݾ�: "; std::cin >> balance;
	std::cout << "������: "; std::cin >> interRate;
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

	std::cout << "[�ſ�ŷڰ��� ����]" << std::endl;
	std::cout << "���� ID: "; std::cin >> id;
	std::cout << "�� ��: "; std::cin >> name;
	std::cout << "�Աݾ�: "; std::cin >> balance;
	std::cout << "������: "; std::cin >> interRate;
	std::cout << "�ſ���(1toA, 2toB, 3toC): "; std::cin >> creditLevel;
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
