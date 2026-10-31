#pragma once
#include<iostream>
#include<fstream>
#include"clsString.h"
#include"clsUtil.h"
#include"Global.h"
#include"clsPerson.h"
using namespace std;
class clsUser :public clsPerson
{
private:
	enum enMode{UpdateMode=1,EmptyMode=2,AddNewMode=3};
	enMode _Mode;
	string _UserName;
	string _PassWord;
	int _Permissions;
	bool _MarkToDelete = false;
	struct stLoginRegister;
	struct stTransferLog;
	static clsUser	_ConvertLineToObjectUser(string line, string Separator = "#//#")
	{
		vector<string>vString = clsString::Split(line,Separator);
		return clsUser(enMode::UpdateMode, vString[0], vString[1], vString[2], vString[3], vString[4],clsString::DecryptPassWord( vString[5]),stoi( vString[6]));
    }
	static stTransferLog _ConvertLineToOpject(string line,string Separator="#//#")
	{
		stTransferLog Log;
		vector<string>vString = clsString::Split(line, Separator);
		Log.DateUndTime = vString[0];
		Log.sAccountNumber = vString[1];
		Log.dAccountNumber = vString[2];
		Log.Amount =stoi( vString[3]);
		Log.sBalance = stod(vString[4]);
		Log.dBalance =stod( vString[5]);
		Log.UserName = vString[6];
		return Log;
	}
	static vector<stTransferLog> _LoadTransferLog()
	{
		vector<stTransferLog>vLog;
		fstream Myfile;
		Myfile.open("Transfer_.txt", ios::in);
		if (Myfile.is_open())
		{
			string line;
			while (getline(Myfile, line))
			{
				stTransferLog Log = _ConvertLineToOpject(line);
				vLog.push_back(Log);
			}
			Myfile.close();
		}
		return vLog;
	}

	static stLoginRegister _ConvertLoginRegisterLineToStruct(string line, string Separator = "#//#")
	{
		stLoginRegister Login;
		vector<string>vString = clsString::Split(line, Separator);
		Login.DateAndTime = vString[0];
		Login.UserName = vString[1];
		Login.PassWord =clsString::DecryptPassWord( vString[2]);
		Login.Permissions = stoi(vString[3]);
		return Login;
	}
	static vector<stLoginRegister> _LoadFileLinesToVector()
	{
		vector<stLoginRegister>vLogin;
		fstream Myfile;
		Myfile.open("Login.txt", ios::in);
		if (Myfile.is_open())
		{
			string line;
			while (getline(Myfile, line))
			{
				stLoginRegister Login = _ConvertLoginRegisterLineToStruct(line);
				vLogin.push_back(Login);
			}
			Myfile.close();
		}
		return vLogin;
	}
	static string _ConvertObjectUserToLine(clsUser User, string Separator = "#//#")
	{
		string S = "";
		S += User.FirstName + Separator;
		S += User.LastName + Separator;
		S += User.Email + Separator;
		S += User.Phone + Separator;
		S += User.UserName() + Separator;
		S += clsString::EncryptPassWord(User.PassWord) + Separator;
		S += to_string(User.Permissions);
		return S;
	}
	static vector<clsUser>_LoadUsersObjectFromFile()
	{
		vector<clsUser>vUser;
		fstream Myfile;
		Myfile.open("Users.txt", ios::in);
		if (Myfile.is_open())
		{
			string line;
			while (getline(Myfile, line))
			{
				clsUser User = _ConvertLineToObjectUser(line);
				vUser.push_back(User);
			}
			Myfile.close();
		}
		return vUser;
	}
	static void _SaveUsersObjectToFile(vector<clsUser>vUser)
	{
		fstream Myfile;
		Myfile.open("Users.txt", ios::out);
		if (Myfile.is_open())
		{
			for (clsUser obj : vUser)
			{
				Myfile << _ConvertObjectUserToLine(obj) << endl;
			}
			Myfile.close();
		}
	}
	static void _AddUserObjectToFile(clsUser User)
	{
		fstream Myfile;
		Myfile.open("Users.txt", ios::out | ios::app);
		if (Myfile.is_open())
		{
			Myfile << _ConvertObjectUserToLine(User) << endl;
			Myfile.close();
		}
	}
	static void _SaveUsersObjectExceptMarkToDelete(vector<clsUser>vUser)
	{
		fstream Myfile;
		Myfile.open("Users.txt", ios::out);
		if (Myfile.is_open())
		{
			for (clsUser obj : vUser)
			{
				if (obj.MarkToDelete == false)
				{
					Myfile << _ConvertObjectUserToLine(obj) << endl;

				}
				
			}
			Myfile.close();
		}
	}

	static clsUser _GetEmptyObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	static clsUser _GetNewObject(string AccountNumber)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}
	void _Update()
	{
		vector<clsUser>vUser = _LoadUsersObjectFromFile();
		for (clsUser&  obj : vUser)
		{
			if (obj.UserName() == UserName())
			{
				obj = *this;
				break;
			}
		}
		_SaveUsersObjectToFile(vUser);
	}
	void _AddNew()
	{
		_AddUserObjectToFile(*this);
	}
	string _PrepareLogInRecord(string Separator="#//#")
	{
		string LogInRecord = "";
		 LogInRecord+=clsDate::GetCurrentTimeUndDate() + Separator;
		 LogInRecord += _UserName + Separator;
		 LogInRecord += _PassWord + Separator;
		 LogInRecord += to_string(_Permissions);
		 return LogInRecord;
	}
	
public:
	struct stLoginRegister
	{
		string DateAndTime;
		string UserName;
		string PassWord;
		int Permissions;
	};
	struct stTransferLog

	{
		string DateUndTime;
		int Amount;
		string sAccountNumber;
		string dAccountNumber;
		double sBalance;
		double dBalance;
		string UserName;
	};
	
	static vector<stLoginRegister> GetLoginRegisterList()
	{
		return _LoadFileLinesToVector();
	}
	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string PassWord, int Permissions)
		:clsPerson(FirstName, LastName, Email, Phone)

	{
		_Mode = Mode;
		_UserName = UserName;
		_PassWord = PassWord;
		_Permissions = Permissions;
	}
	
	static vector<clsUser> GetUsersList()
	{
		return _LoadUsersObjectFromFile();
	}
	string UserName()
	{
		return _UserName;
	}

	void SetPassWord(string PassWord)
	{
		_PassWord = PassWord;
	}
	string GetPassWord()
	{
		return _PassWord;
	}
	__declspec(property(get = GetPassWord, put = SetPassWord))string PassWord;
	void SetPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}
	int GetPermissions()
	{
		return _Permissions;
	}
	__declspec(property(get = GetPermissions, put = SetPermissions))int Permissions;
	void SetMarkToDelete(bool Mark)
	{
		_MarkToDelete = Mark;
	}
	bool GetMarkToDelete()
	{
		return _MarkToDelete;
	}
	__declspec(property(get = GetMarkToDelete, put = SetMarkToDelete))bool MarkToDelete;
	bool Delete()
	{
		vector<clsUser>vUser = _LoadUsersObjectFromFile();
		for (clsUser& obj : vUser)
		{
			if (obj.UserName() == UserName())
			{
				obj.MarkToDelete = true;
				break;
			}
		}
		_SaveUsersObjectExceptMarkToDelete(vUser);
		*this = _GetEmptyObject();
		return true;
	}
	static	clsUser Find(string UserName)
	{
		vector<clsUser>vUser = _LoadUsersObjectFromFile();
		for (clsUser obj : vUser)
		{
			if (obj.UserName() == UserName)
			{
				return obj;
			}
		}
		return _GetEmptyObject();
    }
	static	clsUser Find(string UserName,string PassWord)
	{
		vector<clsUser>vUser = _LoadUsersObjectFromFile();
		for (clsUser obj : vUser)
		{
			if (obj.UserName() == UserName&&obj.PassWord==PassWord)
			{
				return obj;
			}
		}
		return _GetEmptyObject();
	}
	bool IsEmpty()
	{
		return _Mode == enMode::EmptyMode;
	}
static	bool IsExist(string UserName)
	{
		clsUser User = Find(UserName);
		return (!User.IsEmpty());
	}
static clsUser GetNewObject(string UserName)
{
	return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
}
enum enPermissions { pAll = -1, pClientsList = 1, pAddClients = 2, pDeleteClients = 4, pUpdateClients = 8, pFindClient = 16, pTransaction = 32, pManageUsers = 64
,pLoginRegister=128};
 bool IsAccess(enPermissions Permissions)
{
	 if (this ->Permissions == enPermissions::pAll)
		 return true;
	 if ((this->Permissions & Permissions) == Permissions)
		 return true;
	 else
		 return false;
}
	enum enResultsSave{svSucceeded=1,svFailedExist=2,svFailedEmpty=3};
	enResultsSave Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
			return svFailedEmpty;
		case enMode::UpdateMode:
			_Update();
			return svSucceeded;
		case enMode::AddNewMode:
			if (IsExist(UserName()))
				return svFailedExist;
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return svSucceeded;
			}
		}
	}
	 void RegisterLogIn()
	{
		fstream Myfile;
		string Date=_PrepareLogInRecord();
		Myfile.open("Login.txt", ios::out | ios::app);
		if (Myfile.is_open())
		{
			Myfile << Date << endl;
			Myfile.close();
		}
	}
	static string Info()
	{
		return clsDate::GetCurrentTimeUndDate();
	}
	static vector<stTransferLog> TransferLogs()
	{
		return _LoadTransferLog();
	}
};

