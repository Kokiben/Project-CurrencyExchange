#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsCurrency.h"

class clsCurrenciesListScreen:protected clsScreen
{
private:
	static void _PrintCurrenciesRecordLine(clsCurrency Currency)
	{
		cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
		cout << "| " << setw(8) << left << Currency.CurrencyCode();
		cout << "| " << setw(45) << left << Currency.CurrencyName();
		cout << "| " << setw(10) << left << Currency.Rate();

	}




public:
	static void ShowCurrenciesListScreen()
	{
		system("cls");
		vector<clsCurrency> vCurrency = clsCurrency::GetCurrenciesList();
		string Title = "\tCurrencies List Screen ";
		string SubTitle = "\t (" + to_string(vCurrency.size()) + ") Currencies";
		_DrawScreenHeader(Title, SubTitle);


		cout << setw(8) << left << "" << "\n\t_____________________________________________________";
		cout << "_________________________________________________\n" << endl;
		
		cout << setw(8) << left << "" << "| " << setw(30) << left << "Country";
		cout << "| " << left << setw(8) << "code";
		cout << "| " << left << setw(45) << "Name";
		cout << "| " << left << setw(10) << "Rate/1$";

		cout << setw(8) << left << "" << "\n\t___________________________________________________________";
		cout << "___________________________________________\n" << endl;
		 
		if (vCurrency.size() == 0)
			cout << "\t\t\t\tNo Currencies Available in the system.\n";
		else
			for (clsCurrency Currency : vCurrency)
			{
				_PrintCurrenciesRecordLine(Currency);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t________________________________________________________";
		cout << "_________________________________________________\n" << endl;

	}
};

