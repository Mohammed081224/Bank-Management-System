#include<iostream>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsBankClient.h"
#include"Global.h"
using namespace std;
class clsAddNewClient :protected clsScreen
{
private:
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
		cout << "Enter PinCode..";
		Client.PinCode = clsInputValidate::ReadString();
		cout << "Enter Account Balance..";
		Client.AccountBalance = clsInputValidate::ReadDblNumber();
	}
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
		cout << "\nPassword    : " <<Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}
public:
	static void AddNewClient()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pAddClients))
		{
			return;
		}
		_DrawScreenHeader("Add New Client ");
		string AccountNumber = "";
		AccountNumber = clsInputValidate::ReadString();
		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Client already exist ,Enter another... ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::GetAddNewClientObject(AccountNumber);
		_ReadClientInfo(Client);
		clsBankClient::enSaveResults SaveResults;
		SaveResults = Client.Save();
		switch (SaveResults)
		{
		case clsBankClient::enSaveResults::svFaildAccountNumberExists:
			cout << "Error Client already exist...";
			break;
		case clsBankClient::enSaveResults::svSucceeded:
			cout << "Client added Successfully";
			_ClientPrint(Client);
			break;
		}
	}
};