#pragma once
#include <iomanip>
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsFIndCurrencyScreen : protected clsScreen
{
private:
	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "Currency Card : ";
		cout << "\n______________________";
		cout << "\nCountry       : " << Currency.Country();
		cout << "\nCode          : " << Currency.CurrencyCode();
		cout << "\nName          : " << Currency.CurrencyName();
		cout << "\nRate(1$)      : " << Currency.Rate();
		cout << "\n____________________\n";
	}
	static void _ShowResult(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\n Currency Found :-)";
			_PrintCurrency(Currency);
		}
		else
		{
			cout << "\ncurrency was not found:-(";
		}
	}
public:
	static void ShowFindCurrencyScreen()
	{
		system("cls");
		_DrawScreenHeader("\t Find Currency Screen");

		cout << "\nFind by code : [1] or by Country : [2] ?";
		short Answer = 1;
		cin >> Answer;
		if (Answer == 1)
		{
			string CurrencyCode;
			cout << "Please enter Currencycode?";
			CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		    _ShowResult(Currency);

		}
		else
		{
			string Country;
			cout << "Please enter country?";
			Country= clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			_ShowResult(Currency);
		}
		



	}
};

