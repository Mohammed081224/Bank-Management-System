#pragma once
#include<iostream>
#include<iomanip>
#include"clsUser.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
using namespace std;
class clsAddNewUser :public clsScreen
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
	static void _ReadNewUserInfo(clsUser& User)
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
		char Answer ;
		cout << "Do you want to give User Complet Permission?.Y/N.";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
			return -1;
		cout << "You Want to give user permission: \n";
		cout << "Clients List?Y/N.\n";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pClientsList;
		}

		cout << "Add New Client?Y/N.\n";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pAddClients;
		}
		cout << "Delete Client?Y/N.\n";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pDeleteClients;
		}
		cout << "Update Client?Y/N.\n";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions = clsUser::enPermissions::pUpdateClients;
		}
		cout << "Find Client?Y/N.\n";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::pFindClient;
		}
		cout << "Transaction ?Y/N.\n";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::pTransaction;
		}
		cout << "Manage User?Y/N.\n";
			cin >> Answer;
			if (Answer == 'y' || Answer == 'Y')
			{
				Permissions += clsUser::pManageUsers;
			}
			cout << "Login Register ";
			cin >> Answer;
			if (Answer == 'y' || Answer == 'Y')
			{
				Permissions += clsUser::pLoginRegister;
			}
			return Permissions;
	}
public:
	static void AddNewUserScreen()
	{
		
		string UserName;
		cout << "Please enter User Name..";
		UserName = clsInputValidate::ReadString();
		while (clsUser::IsExist(UserName))
		{
			cout << "Client is already exist,enter another...";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::GetNewObject(UserName);
		_ReadNewUserInfo(User);
		clsUser::enResultsSave ResultsSave;
		ResultsSave = User.Save();
		switch (ResultsSave)
		{
		case clsUser::enResultsSave::svFailedExist:
			cout << "Error , User is already exist " << endl;
			break;
		case clsUser::enResultsSave::svSucceeded:
			cout << "User added successfully ";
			_PrintUserInfo(User);
			break;
		}
	
	}
};

