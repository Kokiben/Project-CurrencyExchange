#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsDepositScreen : protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card :";
		cout << "\n_________________________";
		cout << "\nFirst Name       : " << Client.FirstName;
		cout << "\nLast Name        : " << Client.LastName;
		cout << "\nFull Name        : " << Client.FullName();
		cout << "\nEmail            : " << Client.Email;
		cout << "\nPhone            : " << Client.Phone;
		cout << "\nAcc.Number       : " << Client.AccountNumber();
		cout << "\nBalance          : " << Client.PinCode;
		cout << "\n_________________________\n";
	}

	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "\nPlease enter accountNumber? ";
		cin >> AccountNumber;
		return AccountNumber;
	}
public:
	static void ShowDepositScreen()
	{
		_DrawScreenHeader("\tDeposit Screen");
		string AccountNumber = _ReadAccountNumber();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient Wiht [" << AccountNumber << "] does not exist .\n";
			AccountNumber = _ReadAccountNumber();

		}
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		double Amount = 0;
		cout << "\nPlease enter  Transfer amount ? ";
		Amount = clsInputValidate::ReadDblNumber();


		Client1.WithDraw(Amount);







		cout << "\nAre you sure you want to perform this transaction? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Client1.Deposit(Amount);
			cout << "\nAmount Deposited Successfully.\n";
			cout << "\nNew Balance is : " << Client1.AccountBalance;
		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}
	}
};


