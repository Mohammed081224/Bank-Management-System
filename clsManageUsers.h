#include<iostream>
#include<iomanip>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsUsersList.h"
#include"clsAddNewUser.h"
#include"clsDeleteUser.h"
#include"clsUpdateUser.h"
#include"FindUsers.h"
#include"Global.h"
using namespace std;
class clsManageUsers :protected clsScreen
{
private:
	enum enOperationType{eUsersList=1,eAddUsers=2,eDeleteUsers=3,eUpdateUsers=4,eFindUsers=5,eMainMenu=6};
	static short _ReadOperationType()
	{
		short Choice;
		cout << "Choose what do you do.1.to.6.";
		Choice = clsInputValidate::ReadShortNumberBetween(1, 6);
		return Choice;
	}
	static void _GoBackToManageUsers()
	{
		cout << "Press any key to go back to manage users...";
		system("pause>0");
		ManageUsersScreen();
	}
	static void _UsersListScreen()
	{
		//cout << "Users List Screen will be here..." << endl;
		clsUsersList::UsersList();
	}
	static void _AddNewUsers()
	{
		//cout << "Add New Users Screen will be here..." << endl;
		clsAddNewUser::AddNewUserScreen();
	}
	static void _DeleteUsersScreen()
	{
		//cout << "Delete Users Screen will be here..." << endl;
		clsDeleteUser::DeleteUserScreen();
	}
	static void _UpdateUsersScreen()
	{
		clsUpdateUser::UpdateUserScreen();
		//cout << "Update Users Screen will be here..." << endl;
	}
	static void _FindUsersScreen()
	{
		clsFindUser::FindUserScreen();
		// cout << "Update Users Screen will be here..." << endl;
	}
	static void _GoBackToMainMenu()
	{
		cout << "...Nothing..." << endl;
	}
	static void _PerformOperationType(enOperationType Operation)
	{
		switch (Operation)
		{
		case enOperationType::eAddUsers:
			system("cls");
			_AddNewUsers();
			_GoBackToManageUsers();
			break;
		case enOperationType::eDeleteUsers:
			system("cls");
			_DeleteUsersScreen();
			_GoBackToManageUsers();
			break;
		case enOperationType::eUpdateUsers:
			system("cls");
			_UpdateUsersScreen();
			_GoBackToManageUsers();
			break;
		case enOperationType::eFindUsers:
			system("cls");
			_FindUsersScreen();
			_GoBackToManageUsers();
			break;
		case enOperationType::eMainMenu:
			system("cls");
			_GoBackToMainMenu();
			break;
		case enOperationType::eUsersList:
			system("cls");
			_UsersListScreen();
			_GoBackToManageUsers();
			break;
		}
	}
public:
	static void ManageUsersScreen()
	{
		system("cls");
		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return;
		}
		
		_DrawScreenHeader("Manage Users Screen");
		cout<<setw(37)<<left <<" "<<"===========================================================================\n";
		cout << setw(37) << left << " " << "\t                             Manage Main Menu\n";
		cout<<setw(37)<<left<<" "<<"=========================================================================== \n";
		cout << setw(37) << left << " " << "\t[1] Users List\n";
		cout << setw(37) << left << " " << "\t[2] Add New User\n";
		cout << setw(37) << left << " " << "\t[3] Delete User\n";
		cout << setw(37) << left << " " << "\t[4] Update User\n";
		cout << setw(37) << left << " " << "\t[5] Find User\n";
		cout << setw(37) << left << " " << "\t[6] Main Menu\n";
		cout << setw(37) << left << " " << "=========================================================================== \n";
		_PerformOperationType(enOperationType(_ReadOperationType()));
	}
};
