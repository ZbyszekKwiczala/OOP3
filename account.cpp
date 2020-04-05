#include "account.h"

Account::Account(int n, Client *c)
{
	this->number = n;
	this->owner = c;
	this->balance = 0;
	this->interestRate = 0;
	this->partner = 0;
}

Account::Account(int n, Client *c, double ir)
{
	this->number = n;
	this->owner = c;
	this->balance = 0;
	this->interestRate = ir;
	this->partner = 0;
}

Account::Account(int n, Client *c, Client *p)
{
	this->number = n;
	this->owner = c;
	this->balance = 0;
	this->interestRate = 0;
	this->partner = p;
}

Account::Account(int n, Client *c, Client *p, double ir)
{
	this->number = n;
	this->owner = c;
	this->balance = 0;
	this->interestRate = ir;
	this->partner = p;
}

int Account::GetNumber()
{
	return this->number;
}

double Account::GetBalance()
{
	return this->balance;
}

double Account::GetInterestRate()
{
	return this->interestRate;
}

Client *Account::GetOwner()
{
	return this->owner;
}

Client *Account::GetPartner()
{
	return this->partner;
}

bool Account::CanWithdraw(double a)	//fce jestli vubec mam tolik penez
{
	if (this->balance >= a)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Account::Deposit(double a)
{
	this->balance += a;
}

bool Account::Withdraw(double a)
{
	if (CanWithdraw(a) == 1)
	{
		this->balance -= a;
		return true; //potvrzeni o provedeni transakce
	}
	return false;

}

void Account::AddInterest()
{
	this->balance = this->balance + this->balance * this->interestRate;
}

void Account::TiskUctu()
{
	cout <<GetNumber()<<"\t\t\t";
	GetOwner()->TiskniJednohoClienta();
	cout<<"\t\t"<<GetInterestRate() <<"\t"<< GetBalance();
}
