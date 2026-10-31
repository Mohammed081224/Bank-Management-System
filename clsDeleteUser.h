#pragma once
#include<iostream>
#include"clsUser.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
using namespace std;
class clsDeleteUser :protected clsScreen
{
private:
	static void _PrintUserInfo(clsUser User)
	{
		cout << "User Card      :\n";
		cout << "====================================================================================\n";
		cout << "First Name     : " << User.FirstName << endl;
		cout << "Last Name      : " << User.LastName << endl;
		cout << "Email          : " << User.Email << endl;
		cout << "Phone          : " << User.Phone << endl;
		cout << "Account Number : " << User.UserName() << endl;
		cout << "PinCode        : " << User.PassWord << endl;
		cout << "Permissions    : " << User.Permissions << endl;
		cout << "\n====================================================================================\n";
	}
public:
	static void DeleteUserScreen()
	{
		_DrawScreenHeader("Delete User Screen");
		string UserName;
		cout << "Enter Account Number.." << endl;
		UserName = clsInputValidate::ReadString();
		while (!clsUser::IsExist(UserName))
		{
			cout << "No User,Enter Another..." << endl;
			UserName = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::Find(UserName);
		_PrintUserInfo(User);
		char Answer;
		cout << "Do you want to delete this user.Y/N..."<<endl;
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			if (User.Delete())
			{
				cout << "User deleted successfully..." << endl;
				_PrintUserInfo(User);
			}
			else
			{
				cout << "Error No User." << endl;
			}
		}
	}
};

