#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsUser.h"
using namespace std;
class clsUpdateUser :protected clsScreen
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
	static void _UpdateUserInfo(clsUser& User)
	{
		cout << "Enter First Name.";
		User.FirstName = clsInputValidate::ReadString();
		cout << "Enter Last Name.";
		User.LastName = clsInputValidate::ReadString();
		cout << "Enter Email..";
		User.Email = clsInputValidate::ReadString();
		cout << "Enter Phone.";
		User.Phone = clsInputValidate::ReadString();
		cout << "Enter Password.";
		User.PassWord = clsInputValidate::ReadString();
		cout << "Enter Permissions..";
		User.Permissions = _ReadPermissionToSet();
	}
	static int _ReadPermissionToSet()
	{
		int Permissions = 0;
		char Answer;
		cout << "Do you want to give User Full Permission?Y/N...";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			return -1;
		}
		cout << "Do you want to give User  Permission?...\n";
		cout << "Clints List?Y/N...";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pClientsList;
		}
		cout << "Add New Client?Y/N...";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pAddClients;
		}
		cout << "Clints Delete?Y/N...";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pDeleteClients;
		}
		cout << "Clints Update?Y/N...";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pUpdateClients;
		}
		cout << "Find Clints ?Y/N...";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pFindClient;
		}
		cout << " Transaction?Y/N...";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pTransaction;
		}
		cout << "Manage Users?Y/N...";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pManageUsers;
		}
		cout << "Login Register ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions |= clsUser::enPermissions::pLoginRegister;
		}
		return Permissions;
	}
public:
	static void UpdateUserScreen()
	{
		_DrawScreenHeader("Update User Screen");
		string UserName;
		cout << "Enter User Name..";
		UserName = clsInputValidate::ReadString();
		while (!clsUser::IsExist(UserName))
		{
			cout << "No User,Enter another...";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::Find(UserName);
		_PrintUserInfo(User);
		_UpdateUserInfo(User);
		clsUser::enResultsSave ResultSave;
		ResultSave = User.Save();
		switch (ResultSave)
		{
		case clsUser::enResultsSave::svFailedEmpty:
			cout << "No User " << endl;
			break;
		case clsUser::enResultsSave::svSucceeded:
			cout << "User Updated successfully " << endl;
			_PrintUserInfo(User);
			break;
		}
	}
};

