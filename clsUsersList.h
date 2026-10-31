#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsUser.h"

using namespace std;
class clsUsersList :protected clsScreen
{
private:
	static void _UserCardPrint(clsUser User)
	{
		cout << setw(10) << left << User.UserName();
		cout << setw(25) << left << User.FullName();
		cout << setw(25) << left << User.Email;
		cout << setw(15) << left << User.Phone;
		cout << setw(10) << left << User.PassWord;
		cout << setw(12) << left << User.Permissions;
	}
public:
	static void UsersList()
	{
		vector<clsUser>vUser = clsUser::GetUsersList();
		_DrawScreenHeader("Users List", to_string(vUser.size()) + " Users");
		cout << "=================================================================================================\n";
		cout << setw(10) << left << "User Name";
		cout << setw(25) << left << "Full Name";
		cout << setw(25) << left << "Email";
		cout << setw(15) << left << "Phone";
		cout << setw(10) << left << "Pass Word";
		cout << setw(12) << left << "Permission";
		cout << "\n=================================================================================================\n";
		if (vUser.size() == 0)
		{
			cout << "No User available in system" << endl;
		}
		else
		{
			for (clsUser obj : vUser)
			{
				_UserCardPrint(obj);
				cout << endl;
			}
			cout << "\n=================================================================================================\n";
		}
	}
};

