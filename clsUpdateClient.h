#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
using namespace std;
class clsUpdateClient :protected clsScreen
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
	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "Enter First Name..";
		Client.FirstName = clsInputValidate::ReadString();
		cout << "Enter Last Name..";
		Client.LastName = clsInputValidate::ReadString();
		cout << "Enter Email..";
		Client.Email = clsInputValidate::ReadString();
		cout << "Enter Phone..";
		Client.Phone = clsInputValidate::ReadString();
		cout << "Enter Account Number..";
		Client.AccountNumber() = clsInputValidate::ReadString();
		cout << "Enter PinCode..";
		Client.PinCode = clsInputValidate::ReadString();
		cout << "Enter Account Balance..";
		Client.AccountBalance = clsInputValidate::ReadDblNumber();
	}
public:
	static void UpdateClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
		{
			return;
		}
		_DrawScreenHeader("Update Client Screen");
		string AccountNumber;
		cout << "Enter Account Number...";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "No Client,Enter another...";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_ClientPrint(Client);
		char Answer = 'y';
		cout << "Are you sure you want to update this client...";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			_ReadClientInfo(Client);
			clsBankClient::enSaveResults SaveResults;
			SaveResults = Client.Save();
			switch (SaveResults)
			{
			case clsBankClient::svSucceeded:
				cout << "Client updated successfully.";
				_ClientPrint(Client);
				break;
			case clsBankClient::svFaildEmptyObject:
				cout << "Client not Updated.";
				break;
			}
		}
	}
};

