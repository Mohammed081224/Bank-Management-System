#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
using namespace std;
class clsWithdraw :protected clsScreen
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
	static void  WithdrawScreen()
	{
		_DrawScreenHeader("Withdraw Screen");
		cout << "Enter Account Number...";
		string AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "No Client,Enter another...";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_ClientPrint(Client);
		cout << "Enter withdraw Amount...";
		double Amount = clsInputValidate::ReadDblNumber();
		char Answer = 'y';
		cout << "Are you sure to withdraw " << Amount << " ?Y\N...";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			if(Client.Withdraw(Amount))
			cout << "Amount withdrew successfully,New Balance " << Client.AccountBalance << endl;
			
		}
		else
			cout << "Operation was cancelled..\n";
	}
};
