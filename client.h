#ifndef client
#define client
#include <string>
#include <iostream>

using namespace std;

class Client
{
private:
	int code;
	string name;

public:
	Client(int c, string n);
	int GetCode();
	string GetName();
	void TiskniJednohoClienta();
	//~Client();
};
#endif

