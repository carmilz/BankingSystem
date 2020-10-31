/*
* 파일이름: HighCreditAccount.h
* 작성자: CarMilZ
* 업데이트 정보: 2020.10.31 Ver 0.7
*/

#pragma once
#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount
{
private:
	int specialRate;
public:
	HighCreditAccount(int _accID, int _balance, std::string _cusName, int _interRate, int _specialRate) : NormalAccount(_accID, _balance, _cusName, _interRate), specialRate(_specialRate) {}
	virtual void Deposit(int _balance)
	{
		NormalAccount::Deposit(_balance);
		Account::Deposit(_balance * (specialRate / 100.0));
	}
};