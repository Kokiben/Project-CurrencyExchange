#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"



class clsWithdrawScreen : protected clsScreen
{
private:
	static void _PrintCLient(clsBankClient Client)
	{
		cout << "\nClient Card : ";
		cout << "\n________________________";
		cout << "\nFirst Name        : " << Client.FirstName;
		cout << "\nLast  Name        : " << Client.LastName;
		cout << "\nFull Name         : " << Client.FullName();
		cout << "\nEmail             : " << Client.Email;
		cout << "\nPhone             : " << Client.Phone;
		cout << "\nAcc.Number         : " << Client.AccountNumber();
		cout << "\nPassword            : " << Client.PinCode;
		cout << "\nBalance           : " << Client.AccountBalance;
		cout << "\n________________________\n";

	}
	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "\nPlease enter Account Number ?";
		cin >> AccountNumber;
		return AccountNumber;
	}
public:
	static void ShowWithDrawScreen()
	{
		_DrawScreenHeader("\t WithDraw Screen");

		string AccountNumber = _ReadAccountNumber();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with [" << AccountNumber << "] does not exist .\n";
			AccountNumber = _ReadAccountNumber();
		}
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintCLient(Client1);

		double Amount = 0;
		cout << "\nPlease enter WithDraw amount ? ";
		Amount = clsInputValidate::ReadDblNumber();

		cout << "\nAre you sure you want to perform this transaction ? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			if (Client1.WithDraw(Amount))
			{
				cout << "\nAmount WithDraw Succesfully.\n";
				cout << "\nNew Balance is : " << Client1.AccountBalance;
			}
			else
			{
				cout << "\ncannot withdraw , insuffecient balance !\n";
				cout << "\nAmount to withdraw is : " << Amount;
				cout << "\nYour balance is : " << Client1.AccountBalance;
			}
		}
		else
		{
			cout << "\nOperation was cancelled .\n";
		}
	}
};

