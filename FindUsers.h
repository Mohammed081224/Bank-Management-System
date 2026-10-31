#include<iostream>
#include"clsInputValidate.h"
#include"clsUser.h"
#include"clsScreen.h"
using namespace std;
class clsFindUser :protected clsScreen
{
private:
	static void _PrintUserInfo(clsUser User)
	{
		cout << "User Card      :\n";
		cout << "====================================================================================\n";
		cout << "First Name     : " << User.FirstName << endl;
		cout << "Last Name      : " << User.LastName << endl;
		cout << "Email          : " << User.Email << endl;
		cout << "Phone          : " << User.Phone << endl;
		cout << "User Number : " << User.UserName() << endl;
		cout << "PinCode        : " << User.PassWord << endl;
		cout << "Permissions    : " << User.Permissions << endl;
		cout << "\n====================================================================================\n";
	}
public:
	static void FindUserScreen()
	{
		_DrawScreenHeader("Find User Screen");
		string UserName;
		cout << "Enter User Name...";
		UserName = clsInputValidate::ReadString();
		while (!clsUser::IsExist(UserName))
		{
			cout << "No Client,Enter Another User Name ...";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::Find(UserName);
		if (!User.IsEmpty())
		{
			cout << "User found successfully." << endl;
		}
		else
		{
			cout << "No User Available in System " << endl;
		}
		_PrintUserInfo(User);
	 }
};

