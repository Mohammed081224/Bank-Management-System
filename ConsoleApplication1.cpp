#include<iostream>
#include"clsMainScreen.h"
#include"Global.h"
#include"clsLoginScreen.h"
using namespace std;
int main()
{
	//	clsMainScreen::MainMenuScreen();
	
	while(true)
	{
		if (!clsLoginScreen::LoginScreen())
		{
			break;
		}
	}
	return 0;
}
/*
#include<iostream>
#include"clsCurrency.h"


using namespace std;

static void PrintCurrencyInfo(clsCurrency Currency)
{
	cout << "Currency Country: " << Currency.Country() << endl;
	cout << "Currency Code: " << Currency.CurrencyCode() << endl;
	cout << "Currency Name: " << Currency.CurrencyName() << endl;
	cout << "Currency Rate: " << Currency.Rate() << endl;
}
int main()
{
	
	clsCurrency Currency = clsCurrency::FindCurrencyByCurrencyCode("eur");
	if (Currency.IsEmpty())
	{
		cout << "No Currency " << endl;
	}
	else
	{
		PrintCurrencyInfo(Currency);
	}
	clsCurrency Currency1 = clsCurrency::FindCurrencyByCurrencyName("euro");
	if (Currency1.IsEmpty())
	{
		cout << "No Currency " << endl;
	}
	else
	{
		PrintCurrencyInfo(Currency1);
	} 
	Currency1.UpdateRate(0.034);
	cout<<Currency1.Rate()<<endl;

}*/