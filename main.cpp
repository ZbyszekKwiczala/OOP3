#include <iostream>
#include "client.h"
#include "account.h"
#include "bank.h"

using namespace std;

int main()
{
	//vytvoreni banky:
	Bank* BohataBanka=new Bank(50,50);
	//vytvoreni clientu:
	Client* klient0=BohataBanka->CreateClient(0,"Vojta Krakonos");
	Client* klient1=BohataBanka->CreateClient(1,"Adela Bila");
	Client* klient2=BohataBanka->CreateClient(2,"Filip Cerny");
	Client* klient3=BohataBanka->CreateClient(3,"Beata Fialova");
	Client* klient4=BohataBanka->CreateClient(4,"Patrik Cerveny");
	Client* klient5=BohataBanka->CreateClient(5,"Tomas Zluty");
	Client* klient6=BohataBanka->CreateClient(6,"Daniel Modry");
	Client* klient7=BohataBanka->CreateClient(7,"Michal Oranzovy");
	Client* klient8=BohataBanka->CreateClient(8,"Magdalena Oranzova");
	//vytvoreni uctu:
	BohataBanka->CreateAccount(0,klient0);
	BohataBanka->CreateAccount(1,klient1);
	BohataBanka->CreateAccount(2,klient2,7.0);
	BohataBanka->CreateAccount(3,klient3,0.4);
	BohataBanka->CreateAccount(4,klient4,0.11);
	BohataBanka->CreateAccount(5,klient5,0.17);
	BohataBanka->CreateAccount(6,klient6,0.18);
	BohataBanka->CreateAccount(7,klient7,klient8,0.1);
	//bezne transakce:
	BohataBanka->GetAccount(0)->Deposit(8500);	//zadavani podle cisla uctu
	BohataBanka->GetAccount(1)->Deposit(4000);
	BohataBanka->GetAccount(2)->Deposit(300);
	BohataBanka->GetAccount(3)->Deposit(79000);
	BohataBanka->GetAccount(4)->Deposit(12);
	BohataBanka->GetAccount(5)->Deposit(56000);
	BohataBanka->GetAccount(6)->Deposit(11000);
	BohataBanka->GetAccount(7)->Deposit(7050);
	cout<<"Vypis za leden 2020"<<endl;
	BohataBanka->TiskniCelek();
	cout<<"\nVypis za unor 2020"<<endl;
	BohataBanka->AddInterest();
	BohataBanka->GetAccount(0)->Withdraw(5000);
	BohataBanka->GetAccount(1)->Withdraw(5000);	//chtel vybrat vic nez ma,nic se nestalo,neprosel podminkou canWithdraw
	BohataBanka->GetAccount(2)->Withdraw(100);
	BohataBanka->GetAccount(3)->Withdraw(800);
	BohataBanka->GetAccount(4)->Withdraw(900);
	BohataBanka->GetAccount(5)->Withdraw(895);
	BohataBanka->GetAccount(6)->Withdraw(1200);
	BohataBanka->GetAccount(7)->Withdraw(2700);
							
	BohataBanka->TiskniCelek();
	delete BohataBanka;
	return 0;
}
