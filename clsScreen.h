#pragma once
#include<iostream>
#include<iomanip>
#include"Global.h"
#include<ctime>
#include"clsDate.h"
using namespace std;
class clsScreen
{
protected:
	static void _DrawScreenHeader(string Title,string Subtitle="")
	{
		
		cout << setw(37) << left << "" << "--------------------------------------------------------------\n";
		cout << setw(37) << left << "" << "\t\t\t\t" << Title << "\n";
		if (Subtitle != "")
			cout << setw(37) << left << "" << "\t\t\t\t" << Subtitle << "\n";
		cout << setw(37) << left << "" << "--------------------------------------------------------------\n";
		cout << setw(37) << left << "" << "\t\t\t\tUser: " << CurrentUser.UserName() << endl;
		cout << setw(37) << left << "" << "\t\t\t\t" << clsDate::DateToString(clsDate()) << endl;;
	}
	static bool CheckAccessRights(clsUser::enPermissions Permissions)
	{
		if (!CurrentUser.IsAccess(Permissions))
		{
			cout << setw(37) << left << "" << "--------------------------------------------------------------\n";
			cout << setw(37) << left << "" << "\t\t\t\t" << "Access Denied,contact with Admin" << "\n";
			cout << setw(37) << left << "" << "--------------------------------------------------------------\n";
			return false;
		}
		return true;
	}
};

