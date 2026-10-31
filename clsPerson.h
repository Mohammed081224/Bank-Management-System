#pragma once
#include<iostream>
#include<string>
using namespace std;
class clsPerson
{
private:
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;
public:
	clsPerson(string FirstName, string LastName, string Email, string Phone)
	{
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
	}
	void SetFirstName(string F)
	{
		_FirstName = F;
	}
	string GetFirstName()
	{
		return _FirstName;
	}
	__declspec(property(get = GetFirstName, put = SetFirstName))string FirstName;
	void SetLastName(string L)
	{
		_LastName = L;
	}
	string GetLastName()
	{
		return _LastName;
	}
	__declspec(property(get = GetLastName, put = SetLastName))string LastName;
	string FullName()
	{
		return _FirstName + " " + _LastName;
	}
	void SetEmail(string E)
	{
		_Email = E;
	}
	string GetEmail()
	{
		return _Email;
	}
	__declspec(property(get = GetEmail, put = SetEmail))string Email;
	void SetPhone(string P)
	{
		_Phone = P;
	}
	string GetPhone()
	{
		return _Phone;
	}
	__declspec(property(get = GetPhone, put = SetPhone))string Phone;
	void Print()
	{
		cout << "Person Info:\n\n";
		cout << "First Name :" << _FirstName << endl;
		cout << "Last Name  :" << _LastName << endl;
		cout << "Email      :" << _Email << endl;
		cout << "Phone      :" << _Phone << endl;
	}
};