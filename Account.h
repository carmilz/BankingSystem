/*
* 파일이름: Account.h
* 작성자: CarMilZ
* 업데이트 정보: 2020.10.31 Ver 0.8
*/

#pragma once
#include <string>

class Account
{
private:
	int accID;
	int balance;
	std::string cusName;
public:
	Account(int _accID, int _balance, std::string _cusName);
	Account(const Account& ref);
	Account& operator=(const Account& ref);

	int GetAccID() const;
	virtual void Deposit(int _balance);
	int WithDraw(int _balance);
	void ShowAccInfo() const;
};