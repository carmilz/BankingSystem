/*
* �����̸�: Account.cpp
* �ۼ���: CarMilZ
* ������Ʈ ����: 2020.10.31 Ver 0.8
*/

#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int _accID, int _balance, std::string _cusName) : accID(_accID), balance(_balance), cusName(_cusName) {}

Account::Account(const Account& ref) : accID(ref.accID), balance(ref.balance), cusName(ref.cusName) {}

Account& Account::operator=(const Account& ref)
{
	accID = ref.accID;
	balance = ref.balance;
	cusName = ref.cusName;
	return *this;
}

int Account::GetAccID() const { return accID; }

void Account::Deposit(int _balance) { balance += _balance; }

int Account::WithDraw(int _balance)
{
	if (balance < _balance)
		return 0;
	balance -= _balance;
	return _balance;
}

void Account::ShowAccInfo() const
{
	std::cout << "���� ID: " << accID << std::endl;
	std::cout << "�̸�: " << cusName << std::endl;
	std::cout << "�ܾ�: " << balance << std::endl;
}
