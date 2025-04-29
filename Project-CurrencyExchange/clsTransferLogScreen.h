#pragma once

#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include <fstream>
#include "clsBankClient.h"

class clsTransferLogScreen : protected clsScreen
{
private:
    static void _PrintUserRecordLine(clsBankClient::stTrnsferLogRecord TransferLogRecord)
    {

        cout << setw(25) << left << "" << "| " << setw(20) << left << clsDate::GetSystemDateTimeString();
        cout << "| " << setw(8) << left << TransferLogRecord.SourceAccountNumber;
        cout << "| " << setw(8) << left << TransferLogRecord.DestinationAccountNumber;

        cout << "| " << setw(8) << left << TransferLogRecord.Amount;
        cout << "| " << setw(8) << left << TransferLogRecord.srcBalanceAfter;
        cout << "| " << setw(8) << left << TransferLogRecord.destBalanceAfter;
        cout << "| " << setw(8) << left << TransferLogRecord.UserName;

    }


public:

    static void ShowTransferLogScreen()
    {


        vector <clsBankClient::stTrnsferLogRecord> vTransferLogRecord = clsBankClient::GetTransferLogList();

        string Title = "\t  Transfer log List Screen";
        string SubTitle = "\t    (" + to_string(vTransferLogRecord.size()) + ") User(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(25) << left << "" << "| " << left << setw(20) << "Date/time";
        cout << "| " << left << setw(8) << "s.acct";
        cout << "| " << left << setw(8) << "d.acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vTransferLogRecord.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (clsBankClient::stTrnsferLogRecord Record : vTransferLogRecord)
            {

                _PrintUserRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }

};

