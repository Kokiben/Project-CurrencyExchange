#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUtil.h"
#include <iomanip>

class clsTotalBalancesScreen : protected clsScreen
{
private:
	static void PrintClientRecordBalanceLine(clsBankClient Client)
	{
		cout << setw(37) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(40) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.AccountBalance;
	}
public:
	static void ShowTotalBalances()
	{
		vector<clsBankClient> vClients = clsBankClient::GetClientsList();
		string Tilte = "\tBalance list Screen ";
		string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s)";
		_DrawScreenHeader("Title, SubTitle");
		cout << setw(25) << left << "" << "\n\t\t_______________________________________________";
		cout << "________________________________________\n" << endl;

		cout << setw(25) << left << "" << "| " << left << setw(15) << "Account Number ";
		cout << "| " << left << setw(40) << "client Name";
		cout << "| " << left << setw(12) << "balance ";
		cout << setw(25) << left << "" << "\t\t_________________________________________________";
		cout << "_________________________________________\n" << endl;

		double TotalBalance = clsBankClient::GetTotalBalance();

		if (vClients.size() == 0)
			cout << "\t\t\tNo Clients Available In the system!";
		else
			for (clsBankClient client : vClients)
			{
				PrintClientRecordBalanceLine(client);
				cout << endl;
			}
		cout << setw(25) << left << "" << "\n\t\t_________________________________________________";
		cout << "____________________________________________\n" << endl;
		cout << setw(8) << left << "" << "\t\t\t\t\t\t\t   Total Balances = " << TotalBalance << endl;
		cout << setw(8) << left << "" << "\t\t\t\t\ (" << clsUtil::NumberToText(TotalBalance) << ")";

	}
};



