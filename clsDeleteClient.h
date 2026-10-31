#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include"clsScreen.h"
using namespace std;
class clsDeleteClient :protected clsScreen
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
	static void DeleteClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClients))
		{
			return;
		}
		_DrawScreenHeader("Delete Client Screen");
		string AccountNumber;
		cout << "Enter Account Number...";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << " No Client,Enter another...";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_ClientPrint(Client);
		char Answer = 'y';
		cout << "Are you sure you want to delete this Client...";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			if (Client.Delete())
			{
				cout << "Client deleted successfully..."<<endl;
				_ClientPrint(Client);
			}
			else
				cout << "Client not deleted..." << endl;
			}
		}
	
};
