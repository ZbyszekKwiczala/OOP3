#include "bank.h"

using namespace std;

Bank::Bank(int c, int a)
{
	clients = new Client *[c];
	clientsCount = 0;
	MaxCountClients = c;
	accounts = new Account *[a];
	accountsCount = 0;
	MaxCountAccounts = a;
}

Client *Bank::GetClient(int c)
{
	for (int i = 0; i < clientsCount; i++)
	{
		if (clients[i]->GetCode() == c)
		{
			return clients[i];
		}
	}
	return 0;	//nemusi se nikdo takovz nachazet v seznamu
}

Account *Bank::GetAccount(int n)
{
	for (int i = 0; i < accountsCount; i++)	//stejna smycka jako s klientama
	{
		if (accounts[i]->GetNumber() == n)
		{
			return accounts[i];
		}
	}
	return 0;
}

Client *Bank::CreateClient(int c, string n)
{
	clients[clientsCount] = new Client(c, n);
	clientsCount+=1;
	return clients[clientsCount - 1];
}

Account *Bank::CreateAccount(int n, Client *c)
{
	accounts[accountsCount] = new Account(n, c);
	accountsCount++;
	return accounts[accountsCount - 1];
}

Account *Bank::CreateAccount(int n, Client *c, double ir)
{
	accounts[accountsCount] = new Account(n, c, ir);
	accountsCount+=1;
	return accounts[accountsCount - 1];
}

Account *Bank::CreateAccount(int n, Client *c, Client *p)
{
	accounts[accountsCount] = new Account(n, c, p);
	accountsCount+=1;
	return accounts[accountsCount - 1];
}
Account *Bank::CreateAccount(int n, Client *c, Client *p, double ir)
{
	accounts[accountsCount] = new Account(n, c, p, ir);
	accountsCount++;
	return accounts[accountsCount - 1];
}

void Bank::AddInterest()
{
	for (int i = 0; i < accountsCount; i++)
	{
		accounts[i]->AddInterest(); //v klase account navysi interestrate
	}
}

void Bank::TiskniClienty()
{
	for (int i = 0; i < clientsCount; i++)
	{
		clients[i]->TiskniJednohoClienta();
		cout << endl;	//v class.cpp nemam odradkovani endl
	}
}
void Bank::TiskniUcty()
{
	for (int i = 0; i < accountsCount; i++)
	{
		accounts[i]->TiskUctu();
		cout << endl;	//v account.cpp nemam odradkovani endl
	} 
}
void Bank::TiskniCelek()
{
	cout << "\n Clienti:" << endl;
	cout<<"CISLO \t JMENO"<<endl;
	TiskniClienty();
	cout << "\n Ucty:" << endl;
	cout<<"CISLO UCTU \t CISLO CLIENTA \t JMENO \t\t UROK\t ZUSTATEK" <<endl;
	TiskniUcty();
	cout<<"-------------------------------------------------------------";
}

Bank::~Bank()
{
	for (int i = 0; i < clientsCount; i++) //uvolnovani jednotlivzch klientu
	{
		delete clients[i];
	}
	for (int j = 0; j < accountsCount; j++) //nemuze byt v jednom foru protoze pocet polozek se lisi
	{
		delete accounts[j];
	}
	delete[] accounts;
	delete[] clients;
}
