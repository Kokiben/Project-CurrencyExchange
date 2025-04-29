#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "clsString.h"

class clsCurrency
{
private:
	enum enMode{EmptyMode = 0, UpdateMode = 1};
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;
	static clsCurrency _ConvertLinetoCurrencyObject(string Line, string Seprator = "#//#")
	{
		vector<string> vCurrencyData;
		vCurrencyData = clsString::Split(Line, Seprator);
		return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stof(vCurrencyData[3]));
	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string seprator = "#//#")
	{
		string stCurrencyRecord = "";
		stCurrencyRecord += Currency.Country() + seprator;
		stCurrencyRecord += Currency.CurrencyCode() + seprator;
		stCurrencyRecord += Currency.CurrencyName() + seprator;
		stCurrencyRecord += to_string(Currency.Rate());
		return stCurrencyRecord;
	}

	static vector<clsCurrency> _LoadCurrencyDataFromFile()
	{
		vector <clsCurrency> vCurrency;
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
				vCurrency.push_back(Currency);
			}
			MyFile.close();
		}
		return vCurrency;
	}
	static void _SaveCurrencyDatatoFile(vector<clsCurrency> vCurrency)
	{
		fstream MyFile;
		MyFile.open("currencies.txt", ios::out);//overwrite
		string DataLine;
		if(MyFile.is_open())
        {
			for (clsCurrency currency : vCurrency)
			{
				DataLine = _ConvertCurrencyObjectToLine(currency);
				MyFile << DataLine << endl;
			}
			MyFile.close();
		}
		
	}
	void _UpDate()
	{
		vector <clsCurrency> _vCurrencys;
		_vCurrencys = _LoadCurrencyDataFromFile();

		for (clsCurrency c : _vCurrencys)
		{
			if (c.CurrencyCode() == CurrencyCode())
			{
				c = *this;
				this;
			}
		}
		_SaveCurrencyDatatoFile(_vCurrencys);

	}



	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

public:
	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	static vector <clsCurrency> GetAllUSDRates()
	{
		return _LoadCurrencyDataFromFile();
	}



	bool IsEmpty()
	{
		return (_Mode = enMode::EmptyMode);
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
	void UpDateRate(float NewRate)
	{
		_Rate = NewRate;
		_UpDate();
	}
	float Rate()
	{
		return _Rate;
	}
	


	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read mode
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
				if (Currency.CurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}
			MyFile.close();
		}
		return _GetEmptyCurrencyObject();
	}
	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read mode
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
				if (clsString::UpperAllString(Currency.Country()) == Country)
				{
					MyFile.close();
					return Currency;
				}
			}
			MyFile.close();

		}
		return _GetEmptyCurrencyObject();

	}
	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return (!Currency.IsEmpty());
	}
	static vector<clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrencyDataFromFile();
	}
	float  ConvertToUsd(float  Amount)
	{
	return  (float)(Amount / Rate());

	}
	static float ConverttoOtherCurrency(float Amount, clsCurrency Currency2)
	{
		float AmountTInUsd = Currency2.ConvertToUsd(Amount);
		if (Currency2.CurrencyCode() == "USD")
		{
			return AmountTInUsd;
		}
		return (float)(AmountTInUsd * Currency2.Rate());


	}
};

