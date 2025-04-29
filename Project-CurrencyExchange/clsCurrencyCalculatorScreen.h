#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include"clsCurrency.h"

class clsCurrencyCalculatorScreen: protected clsScreen
{
private:
	static float _ReadAmount()
	{
		cout << "\n Enter Amount to exchange : ";
		float Amount = 0;
		Amount = clsInputValidate::ReadFloatNumber();
		return Amount;
	}

	static clsCurrency _GetCurrency(string Message)
	{
		string CurrencyCode;
		cout << Message << endl;
		CurrencyCode = clsInputValidate::ReadString();
		if (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency was not found , choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return Currency;

	}
	static void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card : ")
	{
		cout << "\n" << Title << "\n";;
		cout << "\n______________________";
		cout << "\nCountry      : " << Currency.Country();
		cout << "\nCOde         : " << Currency.CurrencyCode();
		cout << "\nName         : " << Currency.CurrencyName();
		cout << "\nRate(1$)     : " << Currency.Rate();
		cout << "\n_______________________\n";
	}
	static void _PrintCalculationRecult(float Amount, clsCurrency Currency1, clsCurrency Currency2)
	{
		_PrintCurrencyCard(Currency1, "Convert From : ");
		float AmountInUsd = Currency1.ConvertToUsd(Amount);


		cout << Amount << " " << Currency1.CurrencyCode() << " = " << AmountInUsd << "USD\n";


		if (Currency2.CurrencyCode() == "USD")
		{
			return;
		}
		cout << "\nConverting from Usd to : \n";
		_PrintCurrencyCard(Currency2, "To : ");
		float AmountInCurrency2 = Currency1.ConverttoOtherCurrency(Amount, Currency2);

		cout << Amount << " " << Currency2.CurrencyCode() << " = " << AmountInCurrency2 << " " << Currency2.CurrencyCode();

	}







public:

	static void ShowCurrencyCalculator()
	{
		char Continue = 'y';
		while (Continue == 'Y' || Continue == 'y')
		{
			system("cls");
			_DrawScreenHeader("\t UpDate Currency Screen ");

			clsCurrency CurrencyFrom = _GetCurrency("\n Please enter corrency1 Code : ");
			clsCurrency Currencyto = _GetCurrency("\n Please enter corrency2 code : ");

			float Amount = _ReadAmount();

			_PrintCalculationRecult(Amount, CurrencyFrom, Currencyto);
			cout << "\nDo you want to perform another calculation ? y/n?";
			cin >> Continue;
		}


	}


};

