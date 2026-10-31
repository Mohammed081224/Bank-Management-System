#pragma once
#include<iostream>
#include<iomanip>
#include"clsCurrencyList.h"
using namespace std;
class clsMainMenu :protected clsScreen
{
	enum enOption{CurrencyList=1,FindCurrency=2,UpdateRate=3,CurrencyCalculate=4,MainMenu=5};
	static void _CurrencyLists()
	{
	 clsCurrencyList::CurrencyListScreen() ;
	}
	static void _FindCurrencies()
	{
		cout << "noch nicht " << endl;
	}
	static void _UpdateRates()
	{
		cout << "noch nicht " << endl;
	}
	static void _CurrencyCalculate()
	{
		cout << "noch nicht " << endl;
	}
	static void _GoBackToMainMenu()
	{
		cout << "No Thing" << endl;
	}

	static void GoBackToCurrencyMainMenu()
	{
		cout << "Press any key to go back to currency main menu..." << endl;
		system("pause>0");
		MainMenuScreen();
	}
    static	int _CurrencyOptions()
	{
		int Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Choose operation between 1,5 ");
		
		return Choice;
	}
	static void _CurrencyOperationType(enOption Option)
	{
		switch (Option)
		{
		case enOption::CurrencyCalculate:
			system("cls");
			_CurrencyCalculate();
			GoBackToCurrencyMainMenu();
			break;
		case enOption::CurrencyList:
			system("cls");
			_CurrencyLists();
			GoBackToCurrencyMainMenu();
			break;
		case enOption::FindCurrency:
			system("cls");
			_FindCurrencies();
			GoBackToCurrencyMainMenu();
			break;
		case enOption::MainMenu:
			system("cls");
			_GoBackToMainMenu();
			break;
		case enOption::UpdateRate:
			system("cls");
			_UpdateRates();
			GoBackToCurrencyMainMenu();
			break;
		}
	}
public:
	
	static void MainMenuScreen()
	{
		system("cls");
		_DrawScreenHeader("Currency Exchange Menu");
		
		cout << setw(25) << left << " " << "=============================================\n\n";
		cout << setw(35) << left << " " << "[1] Currency List" << endl;
		cout << setw(35) << left << " " << "[2] Find Currency" << endl;
		cout << setw(35) << left << " " << "[3] Update Rate" << endl;
		cout << setw(35) << left << " " << "[4] Currency Calculate" << endl;
		cout << setw(35) << left << " " << "[5] Main Menu" << endl;
		cout << setw(25) << left << " " << "=============================================\n";
		 _CurrencyOperationType(enOption(_CurrencyOptions()));
	}

};

