#include<iostream>
#include<string>
#include"clsString.h"
#include<fstream>
#include<vector>
using namespace std;
class clsCurrency
{
private:
	enum enMode{EmptyMode=1,UpdateMode=2};
	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	double _Rate;
	static clsCurrency _ConvertLineToObject(string line, string Separator="#//#")
	{
		vector<string>vCurrency = clsString::Split(line,Separator);
		return clsCurrency(enMode::UpdateMode,vCurrency[0], vCurrency[1], vCurrency[2], stod(vCurrency[3]));
	}
	static string _ConvertObjectToLine(clsCurrency Object,string Separator="#//#")
	{
		string line;
		line += Object.Country() + Separator;
		line += Object.CurrencyCode() + Separator;
		line += Object.CurrencyName() + Separator;
		line += to_string(Object.Rate());
		return line;
	}
	static vector<clsCurrency>_LoadObjectsFromFile(string FileName="Currencies.txt")
	{
		vector<clsCurrency>vCurrency;
		fstream Myfile;
		Myfile.open(FileName, ios::in);
		if (Myfile.is_open())
		{
			string line;
			while (getline(Myfile, line))
			{
				clsCurrency Object = _ConvertLineToObject(line);
				vCurrency.push_back(Object);
			}
			Myfile.close();
		}
		return vCurrency;
	}
	static void _SaveObjectsToFile( vector<clsCurrency>vObject)
	{
		fstream Myfile;
		Myfile.open("Currencies.txt", ios::out);
		if (Myfile.is_open())
		{
			for (clsCurrency object:vObject)
			{
				string line = _ConvertObjectToLine(object);
				Myfile << line << endl;

			}
			Myfile.close();
		}
	}
	void _Update()
	{
		vector<clsCurrency>vCurrency;
		vCurrency = _LoadObjectsFromFile();
		for (clsCurrency& object : vCurrency)
		{
			if (object.CurrencyCode() == CurrencyCode())
			{
				object=*this;
				break;
			}
			_SaveObjectsToFile(vCurrency);
		}
	}
public:
	
	clsCurrency(enMode Mode,string Country, string CurrencyCode, string CurrencyName, double Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}
	string Country()
	{
		return _Country;
	}
	string CurrencyCode()
	{
		return _CurrencyCode;
	}
	string CurrencyName()
	{
		return _CurrencyName;
	}
	void SetRate(double Rate)
	{
		_Rate = Rate;
	}
	void UpdateRate(double Rate)
	{
		_Rate = Rate;
		_Update();
	}
	double Rate()
	{
		return _Rate;
	}
	bool IsEmpty()
	{
		return _Mode == enMode::EmptyMode;
	}
	static clsCurrency FindCurrencyByCurrencyCode(string CurrencyCode)
	{
		fstream Myfile;
		CurrencyCode = clsString::UpperAllString(CurrencyCode);
		Myfile.open("Currencies.txt", ios::in);
		if (Myfile.is_open())
		{
			
			string line;
			while (getline(Myfile, line))
			{
				clsCurrency  Currency = _ConvertLineToObject(line);
				if (clsString::UpperAllString(Currency.CurrencyCode()) == CurrencyCode)
				{
					return Currency;
				}
			}
			Myfile.close();
		}
	}
	static clsCurrency FindCurrencyByCurrencyName(string CurrencyName)
	{
		CurrencyName = clsString::UpperAllString(CurrencyName);
		fstream Myfile;
		Myfile.open("Currencies.txt", ios::in);
		if (Myfile.is_open())
		{
			string line;
			while (getline(Myfile, line))
			{
				clsCurrency Currency = _ConvertLineToObject(line);
				if (clsString::UpperAllString(Currency.CurrencyName()) == CurrencyName)
				{
					return Currency;
				}
			}
			Myfile.close();
		}
	}
	bool IsExisted(string CurrencyCode)
	{
		clsCurrency C = FindCurrencyByCurrencyCode(CurrencyCode);
		return (!C.IsEmpty());
	}
	static vector<clsCurrency>GetCurrencyList()
	{
		return _LoadObjectsFromFile();
	}
};