#ifndef bank
#define bank
#include<iostream>
#include <string>
#include "client.h"
#include "account.h"
using namespace std;

class Bank
{
private:
	Client** clients;
	int clientsCount;
	Account** accounts;
	int accountsCount;
	int MaxCountClients;
	int MaxCountAccounts;
public:
	Bank(int c, int a);

	Client* GetClient(int c);
	Account* GetAccount(int n);

	Client* CreateClient(int c, string n);
	Account* CreateAccount(int n, Client* c);
	Account* CreateAccount(int n, Client* c, double ir);
	Account* CreateAccount(int n, Client* c, Client* p);
	Account* CreateAccount(int n, Client* c, Client* p, double ir);

	void AddInterest();
	void TiskniClienty();
	void TiskniUcty();
	void TiskniCelek();
	~Bank();	//udelal jsem jenom tenhle destruk protoze kdyz mazu ucet tak musim smazat i klinta( plati i naopak)
};
#endif

