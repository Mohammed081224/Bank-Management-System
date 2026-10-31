#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
using namespace std;
class clsDeposite :protected clsScreen
{
private:
	
	static	void _ClientPrint(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}
public:
	static void DepositeScreen()
	{
		_DrawScreenHeader("Deposite Screen");
		cout << "Enter Account Number...";
		string AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "No Client,Enter Another...";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_ClientPrint(Client);
		double Amount = 0;
		cout << "Please enter deposite amount...";
		Amount = clsInputValidate::ReadDblNumber();
		char Answer;
		cout << "Are you sure to deposite " << Amount<<" Y/N...";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Client.Deposite(Amount);
			cout << "Amount deposited successfully,New Balance= " << Client.AccountBalance << endl;
		}
		else
		{
			cout << "Operation was cancelled\n";
		}
		

	}
};

