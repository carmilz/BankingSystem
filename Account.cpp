/*
* 파일이름: Account.cpp
* 작성자: CarMilZ
* 업데이트 정보: 2020.10.31 Ver 0.8
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
	std::cout << "계좌 ID: " << accID << std::endl;
	std::cout << "이름: " << cusName << std::endl;
	std::cout << "잔액: " << balance << std::endl;
}
