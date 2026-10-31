#pragma once
#include<iostream>
#include"clsUser.h"
#include"clsScreen.h"
#include"clsBankClient.h"
using namespace std;
class clsTransferLog :protected clsScreen
{
private:
	static void _PrintTransferLog(clsUser::stTransferLog Log)
	{
		cout << setw(20) << left << Log.DateUndTime;
		cout << setw(10) << left << Log.sAccountNumber;
		cout << setw(10) << left << Log.dAccountNumber;
		cout << setw(10) << left << Log.Amount;
		cout << setw(10) << left << Log.sBalance;
		cout << setw(10) << left << Log.dBalance;
		cout << setw(10) << left << Log.UserName;
	}
public:
	static void TransferLogScreen()
	{
		clsUser::stTransferLog Log;
		vector<clsUser::stTransferLog>vLog = clsUser::TransferLogs();
		cout << "\n-----------------------------------------------"
			<<"--Log("<<vLog.size()<<")--------------------------------------\n";
		cout << setw(20) << left << "Time And Date";
		cout << setw(10) << left << "s.Acct";
		cout << setw(10) << left << "d.Acct";
		cout << setw(10) << left << "Amount";
		cout << setw(10) << left << "s.Balance";
		cout << setw(10) << left << "d.Balance";
		cout << setw(10) << left << "UserName";
		cout << "\n---------------------------------------------------------------------------------------------\n";
		for (clsUser::stTransferLog obj : vLog)
		{
			_PrintTransferLog(obj);
			cout << endl;
		}
	}
};

