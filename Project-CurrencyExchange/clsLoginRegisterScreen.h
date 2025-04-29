#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>

class clsLoginRegisterScreen : protected clsScreen
{
private:
    static void _PrintUserRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord)
    {

        cout << setw(25) << left << "" << "| " << setw(20) << left << clsDate::GetSystemDateTimeString();
        cout << "| " << setw(12) << left << LoginRegisterRecord.UserName;
        cout << "| " << setw(12) << left << LoginRegisterRecord.Password;
        cout << "| " << setw(12) << left << LoginRegisterRecord.Permissions;

    }

public:

    static void ShowULoginRegistersersList()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pLisLogintUser))
        {
            return;// this will exit the function and it will not continue
        }

        vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();

        string Title = "\t  Login Register List Screen";
        string SubTitle = "\t    (" + to_string(vLoginRegisterRecord.size()) + ") User(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(25) << left << "" << "| " << left << setw(20) << "Date/time";
        cout << "| " << left << setw(12) << "Full Name";
        cout << "| " << left << setw(12) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vLoginRegisterRecord.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (clsUser::stLoginRegisterRecord Record : vLoginRegisterRecord)
            {

                _PrintUserRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }

};





