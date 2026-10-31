#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsUser.h"
#include<iomanip>
using namespace std;
class clsClientsList :protected clsScreen
{
private:
static	void _PrintClientInfo(clsBankClient Client)
	{
		cout << setw(14) << left << Client.FirstName;
		cout << setw(12) << left << Client.LastName;
		cout << setw(25) << left << Client.Email;
		cout << setw(14) << left << Client.Phone;
		cout << setw(20) << left << Client.AccountNumber();
		cout << setw(10) << left << Client.PinCode;
		cout << setw(14) << left << Client.AccountBalance;
	}
public:
	static void ClientsList()
	{			  
		if (!CheckAccessRights(clsUser::enPermissions::pClientsList))
		{
			return;
		}
		vector<clsBankClient>vClient = clsBankClient::GetClientsList();
		string SubTitle = to_string(vClient.size()) + " Clients";
		_DrawScreenHeader("Clients List", SubTitle);
		cout << "========================================================================================================\n";
		cout << setw(14) << left << "First Name";
		cout << setw(12) << left << "Last Name";
		cout << setw(25) << left << "Email";
		cout << setw(14) << left << "Phone";
		cout << setw(20) << left << "Account Number";
		cout << setw(10) << left << "PinCode";
		cout << setw(14) << left << "Balance";
		cout << "\n========================================================================================================\n";
		if (vClient.size() == 0)
			cout << "                               No Client                     \n";
		else
			for (clsBankClient obj : vClient)
			{
				_PrintClientInfo(obj);
				cout << endl;
			}
		cout << "\n========================================================================================================\n";
	}
};

