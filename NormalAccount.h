/*
* 파일이름: NormalAccount.h
* 작성자: CarMilZ
* 업데이트 정보: 2020.10.31 Ver 0.7
*/

#pragma once
#include "Account.h"

class NormalAccount : public Account
{
private:
	int interRate;
public:
	NormalAccount(int _accID, int _balance, std::string _cusName, int _interRate) : Account(_accID, _balance, _cusName), interRate(_interRate) {}
	virtual void Deposit(int _balance)
	{
		Account::Deposit(_balance);
		Account::Deposit(_balance * (interRate / 100.0));
	}
};