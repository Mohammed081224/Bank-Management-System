#pragma once
#include<iostream>
#include"clsClientsList.h"
#include"clsScreen.h";
#include"clsInputValidate.h"
#include<iomanip>
#include"clsAddNewClient.h"
#include"clsDeleteClient.h"
#include"clsUpdateClient.h"
#include"clsFindClient.h"
#include"clsTransAction.h"
#include"clsDeposite.h"
#include"clsWithdraw.h"
#include"clsManageUsers.h"
#include"clsLogInRegister.h"
#include"Global.h"
#include"clsMainMenu.h"

using namespace std;
class clsMainScreen :protected clsScreen
{
private:
enum enOperationType{eClientsList=1,eAddClient=2,eDeleteClient=3,eUpdateClient=4,eFindClient=5,Transaction=6,MangeUsers=7,LoginRegister=8,CurrencyMainMenu=9,LogOut=10};
	static short _ReadOptionType()
	{
		short Choice;
		cout <<setw(37)<<"" << "Choose what do you want to do (1to 10)";
		Choice = clsInputValidate::ReadShortNumberBetween(1, 10, "Please enter a number between 1 and 10 ");
		return Choice;
	}
	static void _ShowClientsList()
	{
		clsClientsList::ClientsList();
	}
	static void _AddClientScreen()
	{
		
		clsAddNewClient::AddNewClient();
	}
	static void _UpdateClientScreen()
	{
		
		clsUpdateClient::UpdateClientScreen();
	}
	static void _DeleteClientScreen()
	{
		
		clsDeleteClient::DeleteClientScreen();
	}
	static void _FindClientScreen()
	{
		clsFindClient::FindClientScreen();
	}
	static void _TransactionScreen()
	{
		
		clsTransaction::ShowTransactionScreen();
	}
	static void _MangeUsersScreen()
	{
		
		clsManageUsers::ManageUsersScreen();
	}
	static void _LoginRegisterScreen()
	{
		clsLogInRegister::ShowLogInRegister();
	}
	static void _Logout()
	{
		
		CurrentUser = clsUser::Find("", "");
	}
	static void _CurrencyMainMenu()
	{
		clsMainMenu::MainMenuScreen();
	}
	static void _PerformOperationType(enOperationType OperationType)
	{
		switch (OperationType)
		{
		case enOperationType::eAddClient:
			system("cls");
			_AddClientScreen();
			_GoBackToMainMenu();
			break;
		case enOperationType::eClientsList:
			system("cls");
			_ShowClientsList();
			_GoBackToMainMenu();
			break;
		case enOperationType::eDeleteClient:
			system("cls");
			_DeleteClientScreen();
			_GoBackToMainMenu();
			break;
		case enOperationType::eFindClient:
			system("cls");
			_FindClientScreen();
			_GoBackToMainMenu();
			break;
		case enOperationType::eUpdateClient:
			system("cls");
			_UpdateClientScreen();
			_GoBackToMainMenu();
			break;
		case enOperationType::LogOut:
			system("cls");
			_Logout();
			break;
		case enOperationType::MangeUsers:
			system("cls");
			_MangeUsersScreen();
			_GoBackToMainMenu();
			break;
		case enOperationType::LoginRegister:
			system("cls");
			_LoginRegisterScreen();
			_GoBackToMainMenu();
			break;
		case enOperationType::Transaction:
			system("cls");
			_TransactionScreen();
			_GoBackToMainMenu();
			break;
		case enOperationType::CurrencyMainMenu:
			system("cls");
			_CurrencyMainMenu();
			_GoBackToMainMenu();
			break;
		}
	 }
	static void _GoBackToMainMenu()
	{
		cout << "Press any key to go back to main menu...";
		system("pause>0");
		MainMenuScreen();
	}
public:
	static void MainMenuScreen()
	{
		system("cls");
		_DrawScreenHeader("Main Screen");
		cout << setw(37) << left << "" << "==============================================\n";
		cout << setw(37) << left << "" << "\t\t" << "Main Menu Screen\n";
		cout << setw(37) << left << "" << "==============================================\n";
		cout << setw(37) << left << "" << "\t[01] Clients List\n";
		cout << setw(37) << left << "" << "\t[02] Add Client\n";
		cout << setw(37) << left << "" << "\t[03] Delete Client\n";
		cout << setw(37) << left << "" << "\t[04] Update Client\n";
		cout << setw(37) << left << "" << "\t[05] Find Client\n";
		cout << setw(37) << left << "" << "\t[06] Transaction\n";
		cout << setw(37) << left << "" << "\t[07] Mangement Users\n";
		cout << setw(37) << left << "" << "\t[08] LoginRegister\n";
		cout << setw(37) << left << "" << "\t[09] CurrencyMainScreen\n";
		cout << setw(37) << left << "" << "\t[10] LogOut\n";
		cout << setw(37) << left << "" << "==============================================\n";
		_PerformOperationType(enOperationType(_ReadOptionType()));
	}
};

