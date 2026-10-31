#include<iostream>
#include<iomanip>
#include"clsUser.h"
#include"clsInputValidate.h"
using namespace std;
class clsLogInRegister :protected clsScreen
{
private:
static	void _PrintRegisterInfo(clsUser::stLoginRegister Login)
	{
		cout << setw(50) << left << Login.DateAndTime;
		cout << setw(25) << left << Login.UserName;
		cout << setw(25) << left << Login.PassWord;
		cout << setw(25) << left << Login.Permissions;
	}
public:
	static void ShowLogInRegister()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
		{
		
			return;
		}
		vector<clsUser::stLoginRegister>vLogin = clsUser::GetLoginRegisterList();
		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
		cout << setw(50) << left << "Time and Date";
		cout << setw(25) << left << "User Name";
		cout << setw(25) << left << "PassWord";
		cout << setw(25) << left << "Permissions";
		cout << "\n-----------------------------------------------------------------------------------------------------------------------\n" << endl;
		for (clsUser::stLoginRegister obj : vLogin)
		{
			_PrintRegisterInfo(obj);
			cout << endl;
		}
	}
};

