#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFIndCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
class clsCurrencyExchangeMainScreen: protected clsScreen
{
private:
	enum enCurrencyMainMenueOption{pListCurrencies = 1, pFindCurrency = 2, pUpDateRate = 3, pCurrencyCalculator = 4, eShowMainMenue = 5};

	static short _ReadMainMenueOption()
	{
		cout << setw(37) << left<<"" << "Choose what do you want to do ? 1 to 5?";
		short choice = clsInputValidate::ReadIntNumberBetween(1, 5, "Enter number between 1 to 5?");
		return choice;
	}
	static void _GoBackToMainMenue()
	{
		cout << "\nPress Any key to go back to main menue...\n";
		system("pause>0");
		ShowCurrencyMainScreen();
	}
	static void _ShowAllListCurrenciesScreen()
	{
		//cout << "\n List Currencies Screen  will be here...\n";
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}
	static void _ShowFindCurrenciesScreen()
	{
		//cout << "\nFind Currencies screen will be here...\n";
		clsFIndCurrencyScreen::ShowFindCurrencyScreen();
}
	static void _ShowUpdateRateScreen()
	{
		//cout << "\n Update rate Screen will be here...\n";
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}
	static void _ShowCurrencyCalculatorScreen()
	{
		//cout << "\ncurrency calculator Screen will be here...\n";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculator();
	}

	static void _PerformCurrencyMainMenue(enCurrencyMainMenueOption CurrencyMainMenueOption)
	{
		switch (CurrencyMainMenueOption)
		{


		case enCurrencyMainMenueOption::pListCurrencies:
		{
			system("cls");
			_ShowAllListCurrenciesScreen();
			_GoBackToMainMenue();
			break;
		}
		case enCurrencyMainMenueOption::pFindCurrency:
		{
			system("cls");
			_ShowFindCurrenciesScreen();
			_GoBackToMainMenue();
			break;
		}
		case enCurrencyMainMenueOption::pUpDateRate:
		{
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToMainMenue();
			break;
		}
		case enCurrencyMainMenueOption::pCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToMainMenue();
			break;
		}
		case enCurrencyMainMenueOption::eShowMainMenue:
		{
			//do nothing here the main screen will hande it ...
		}
		}
	}





public:
	static void  ShowCurrencyMainScreen()
	{
		system("cls");

		_DrawScreenHeader("\tCurrency Exchange Main Screen \n");

		cout << setw(37) << left << "" << "=============================================\n";
		cout << setw(37) << left << "" << "\t\tCurrency Exchange Menue \n";
		cout << setw(37) << left << "" << "=============================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currency.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "============================================\n\n";
		_PerformCurrencyMainMenue((enCurrencyMainMenueOption)_ReadMainMenueOption());



	}
};

