#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h" 
#include "clsString.h"

class clsUpdateCurrencyRateScreen : protected clsScreen
{
private:
	static float _ReadRate()
	{
		cout << "Enter New Rate : ";
		float NewRate = 0;
		NewRate = clsInputValidate::ReadFloatNumber();
		return NewRate;
	}
	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card : ";
		cout << "\n______________________";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate\1$    = " << Currency.Rate();
	}
public:
	static void ShowUpdateCurrencyRateScreen()
	{

		_DrawScreenHeader("\t UpDate Currency Screen");
		string CurrencyCode = "";

		cout << "Please enter Currency Code : ";
		CurrencyCode = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency was not found , choose another one.";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrency(Currency);

		cout << "Are you sure you want to update the rate of this currency y/n?";
		char answer = 'n';
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			cout << "\n\nUpdate Client Info:";
			cout << "\n____________________\n";

			cout << "Enter New Rate ? ";
			Currency.UpDateRate(_ReadRate());

			cout << "\nCurrency Rate Update Successfully :-)";
			_PrintCurrency(Currency);

		}

		
	}

};

