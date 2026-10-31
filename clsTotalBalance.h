#include<iostream>
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include"clsScreen.h"
using namespace std;
class clsTotalBalance :protected clsScreen
{
private:
	static void _PrintBalance(clsBankClient Client)
	{
		cout << setw(20) << left << Client.AccountNumber();
		cout << setw(25) << left << Client.FullName();
		cout << setw(15) << left << Client.AccountBalance;
	}
public:
	static void TotalBalancesScreen()
	{
		vector<clsBankClient>vClient = clsBankClient::GetClientsList();
		_DrawScreenHeader("Total Balances Screen",to_string(vClient.size())+" Clients");
		
		cout << "=================================================================================\n";
		cout << setw(20) << left << "Account Number";
		cout << setw(25) << left << "Full Name";
		cout << setw(15) << left << "Balance";
		cout << "\n=================================================================================\n";
		if (vClient.size() == 0)
		{
			cout << "No Client Available in system"<<endl;
		}
		else
		{
			for (clsBankClient obj : vClient)
			{
				_PrintBalance(obj);
				cout << endl;
			}
			cout << "\n=================================================================================\n";
		}
	}
};

