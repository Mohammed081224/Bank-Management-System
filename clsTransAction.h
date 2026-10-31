#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsDeposite.h"
#include"clsWithdraw.h"
#include"clsTransfer.h"
#include"clsTotalBalance.h"
#include"clsTransferLog.h"
using namespace std;
class clsTransaction :protected clsScreen
{
private:
	enum enTransactionOperation{eDeposit=1,eWithdraw=2,eBalanceList=3,eTransfer=4,eTransferLog=5,eGoBackToMainMenu=6};
	static short _ReadTransactionOperationType()
	{
		short Choice;
		cout << "Choose what do you want to do[ 1 to 6 ]...";
		Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter number between 1.to.6 ");
		return Choice;
	}
	static void _TransferLogScreen()
	{
		clsTransferLog::TransferLogScreen();
	}
	static void _Deposite()
	{
		
		clsDeposite::DepositeScreen();
	}
	static void _WithDraw()
	{
		
		clsWithdraw::WithdrawScreen();
	}
	static void _BalanceList()
	{
		
		clsTotalBalance::TotalBalancesScreen();
	}
	static void _TransferOperationScreen()
	{
		clsTransfer::TransferScreen();
	}
	static void _GoBackToTransactionMenu()
	{
		cout << "Press any key to back to transaction menu...";
		system("pause>0");
		ShowTransactionScreen();
	}
	static void _PerformTransactionOperationType(enTransactionOperation Operation)
	{
		switch (Operation)
		{
		case enTransactionOperation::eDeposit:
			system("cls");
			_Deposite();
			_GoBackToTransactionMenu();
			break;
		case enTransactionOperation::eWithdraw:
			system("cls");
			_WithDraw();
			_GoBackToTransactionMenu();
			break;
		case enTransactionOperation::eBalanceList:
			system("cls");
			_BalanceList();
			_GoBackToTransactionMenu();
			break;
		case enTransactionOperation::eTransfer:
			system("cls");
			_TransferOperationScreen();
			_GoBackToTransactionMenu();
			break;
		case enTransactionOperation::eTransferLog:
			system("cls");
			_TransferLogScreen();
			_GoBackToTransactionMenu();
			break;

		case enTransactionOperation::eGoBackToMainMenu:
			system("cls");
			cout << "Do nothing here..." << endl;
		}
	}
public:
	static void ShowTransactionScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pTransaction))
		{
			return;
		}
		system("cls");
		_DrawScreenHeader("Transaction Screen");
			cout <<setw(37)<<left<<" " << "==================================================================================\n";
			cout << setw(37) << left << " " << "                                     Transaction Screen\n";
			cout << setw(37) << left << " " << "\t[1] Deposite\n";
			cout << setw(37) << left << " " << "\t[2] Withdraw\n";
			cout << setw(37) << left << " " << "\t[3] Balance List\n";
			cout << setw(37) << left << " " << "\t[4] Transfer\n";
			cout << setw(37) << left << " " << "\t[5] Transfer Log\n";
			cout << setw(37) << left << " " << "\t[6] Go to Main Menu\n";
			_PerformTransactionOperationType(enTransactionOperation(_ReadTransactionOperationType()));
	}
};
