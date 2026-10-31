#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsCurrency.h"
using namespace std;
class clsCurrencyList:protected clsScreen
{
private:
	static void _PrintCurrentInfo(clsCurrency Currency)
	{
		cout << setw(25) << Currency.Country();
		cout << setw(10) << Currency.CurrencyCode();
		cout << setw(40) << Currency.CurrencyName();
		cout << setw(15) << Currency.Rate();
	}
public:
	static void CurrencyListScreen()
	{  
		
		_DrawScreenHeader("Currency List");
		vector<clsCurrency>vCurrency =clsCurrency:: GetCurrencyList();
		cout << "----------------------------Currency(" << vCurrency.size() << ")---------------------------------------------\n";
		cout << setw(30) << left << "Country";
		cout << setw(8) << left << "Code";
		cout << setw(45) << left << "Name";
		cout << setw(10) << left << "Rate(1$)";
		cout << "\n-------------------------------------------------------------------------------------\n";
		for (clsCurrency object : vCurrency)
		{
			_PrintCurrentInfo(object);
			cout << endl;
		}
	}
};



