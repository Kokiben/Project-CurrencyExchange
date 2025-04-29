#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTransferScreen.h"
#include "clsTotalBalancesScreen.h"

class clsTransactionsScreen : protected clsScreen
{
private:
	enum enTransactionsMenueOption { eDeposite = 1, eWithdraw = 2, eShowTotalBalance = 3, eTransferLog = 4, eShowMainMenue = 5 };

	static short ReadTransactionsOption()
	{
		cout << setw(37) << left << "\n\t\t\t\t\tChoose what do you want to do ? 1 to 5?";
		short choice = clsInputValidate::ReadDblNumberBetween(1, 5, "Enter Number bewteen 1 to 5");
		return choice;
	}
	static void _ShowDepositeScreen()
	{
		clsDepositScreen::ShowDepositScreen();
	}
	static void _ShowWithDrawScreen()
	{
		clsWithdrawScreen::ShowWithDrawScreen();
	}
	static void _ShowTotalBalanceScreen()
	{
		clsTotalBalancesScreen::ShowTotalBalances();
	}
	static void _ShowTransferLog()
	{
		clsTransferScreen::ShowTransferScreen();
	}
	static void _GoBackTransctionMenue()
	{
		cout << "\nPress any key to go back to transaction Meune ...",
			system("pause>0");
		ShowTransactionsMenue();
	}
	static void _PerformTransacionsMenue(enTransactionsMenueOption TransactionsMenueOption)
	{
		switch (TransactionsMenueOption)
		{
		case enTransactionsMenueOption::eDeposite:
		{
			system("cls");
			_ShowDepositeScreen();
			_GoBackTransctionMenue();
			break;
		}
		case enTransactionsMenueOption::eWithdraw:
		{
			system("cls");
			_ShowWithDrawScreen();
			_GoBackTransctionMenue();
			break;
		}
		case enTransactionsMenueOption::eShowTotalBalance:
		{
			system("cls");
			_ShowTotalBalanceScreen();
			_GoBackTransctionMenue();
			break;
		}
		case enTransactionsMenueOption::eTransferLog:
		{
			system("cls");
			_ShowTransferLog();
			_GoBackTransctionMenue();
			break;
		}
		case enTransactionsMenueOption::eShowMainMenue:
		{
			// do nothing here the main screen will handle it :-)
			//_GoBackTransctionMenue();

		}
		}

	}


public:
	static void ShowTransactionsMenue()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
		{
			return;// this will exit the function and it will not continue
		}

		system("cls");
		_DrawScreenHeader("\tTransaction Screen ");

		cout << setw(37) << left << "" << "\t=============================================\n";
		cout << setw(37) << left << "" << "\t\t Transaction Menue\n ";
		cout << setw(37) << left << "" << "\t=============================================\n";
		cout << setw(37) << left << "" << "\t [1] Deposite Screen.\n";
		cout << setw(37) << left << "" << "\t [2] WithDraw Screen.\n";
		cout << setw(37) << left << "" << "\t [3] Total Balance.\n";
		cout << setw(37) << left << "" << "\t [4] Transfer Log .\n";
		cout << setw(37) << left << "" << "\t [5] Main Menue.\n";
		cout << setw(37) << left << "" << "\t==============================================";

		_PerformTransacionsMenue((enTransactionsMenueOption)ReadTransactionsOption());


	}

};

