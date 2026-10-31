#include<iostream>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsWithdraw.h"
#include"clsDeposite.h"
using namespace std;
class clsTransfer :protected clsScreen
{
private:
	static void _PrintClient(clsBankClient& Client)
	{
		cout << "Account Number = " << Client.AccountNumber() << endl;
		cout << "Name           = " << Client.FullName() << endl;
		cout << "Balance        = " << Client.AccountBalance << endl;
	}
public:
	static void TransferScreen()
	{
		cout << "Please enter Account Number to transfer from...";
		string AccountNumber = clsInputValidate::ReadString();
		clsBankClient Client = clsBankClient::Find(AccountNumber);
	     while (Client.IsEmpty())
		{
			cout << "No User ,enter another ";
	        AccountNumber = clsInputValidate::ReadString();
		}
		 _PrintClient(Client);
		 cout << "Please enter Account Number to transfer to...";
		 string AccountNumber1 = clsInputValidate::ReadString();
		 clsBankClient Client1 = clsBankClient::Find(AccountNumber1);
		 while (Client1 .IsEmpty())
		 {
			 cout << "No User ,enter another ";
			 AccountNumber1 = clsInputValidate::ReadString();
		 }
		 _PrintClient(Client1);
		 int Amount;
		 cout << "Please enter Amount ...";
		 cin >> Amount;
		 while (Amount > Client.AccountBalance)
		 {
			 cout << "Amount>AccountBalance,please enter another...";
			 cin >> Amount;
		 }
		 char Answer = 'n';
		 cout << "Do you want to perform transfer operation?Y/N.";
		 cin >> Answer;
		 if (Answer == 'y' || Answer == 'Y')
		 {
			 if (Client.Transfer(Amount, Client1))
			 {
				 cout << "Transfer done successfully" << endl;
				 _PrintClient(Client);
				 _PrintClient(Client1);
			 }
			 else
			 {
				 cout << "Transfer Faild " << endl;
			 }
		 }

	}
};

