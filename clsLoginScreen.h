#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsMainScreen.h"
#include"clsUser.h"
#include"Global.h"
using namespace std;
class clsLoginScreen :protected clsScreen
{
private:
	static bool _Login()
	{
		string UserName, PassWord;
		bool LoginFaild = false;
		short Trials = 0;
		do
		{
			if (LoginFaild)
			{
				Trials++;
				cout << "Invalid User Name/Pass Wort..."<<endl;
				cout << "You have " << 3 - Trials << " Trials to login" << endl;
			}
			if (Trials == 3)
			{
				cout << "You are locked after 3 faild trials " << endl;
				return false;
			}
			cout << "Enter User Name...";
		UserName=clsInputValidate::ReadString();
		cout << "Enter PassWord...";
	    PassWord=	clsInputValidate::ReadString();
		 CurrentUser = clsUser::Find(UserName, PassWord);
		LoginFaild = CurrentUser.IsEmpty();
		} while (LoginFaild);
		CurrentUser.RegisterLogIn();
		clsMainScreen::MainMenuScreen();
		return true;
	}
public:
	static bool LoginScreen()
	{
		
		_DrawScreenHeader("Login Screen");
	return	_Login();
		
	}
};
