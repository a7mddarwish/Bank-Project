
#pragma once
#include <iostream>
#include "ClsHeaderScreen.h"
#include "ClsBankClient.h"
#include <iomanip>
#include "ClsUtil.h"

    class clsTotalBalancesScreen : protected ClsHeaderScreen
    {

    private:

        static void PrintClientRecordBalanceLine(ClsBankClient Client)
        {
            cout << setw(25) << left << "" << "| " << setw(15) << left << Client.GetAccountNumber();
            cout << "| " << setw(40) << left << Client.FullName();
            cout << "| " << setw(12) << left << Client.Balance;
        }

    public:

        static void ShowTotalBalances()
        {

            vector <ClsBankClient> vClients = ClsBankClient::GetClientsList();

            string Title = "\t  Balances List Screen";
            string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

            _ShowHeaderScreen(Title, SubTitle);

            cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
            cout << "__________________________\n" << endl;

            cout << setw(25) << left << "" << "| " << left << setw(15) << "Accout Number";
            cout << "| " << left << setw(40) << "Client Name";
            cout << "| " << left << setw(12) << "Balance";
            cout << setw(25) << left << "" << "\t\t_______________________________________________________";
            cout << "__________________________\n" << endl;

            double TotalBalances = ClsBankClient::GetTotalBalances();

            if (vClients.size() == 0)
                cout << "\t\t\t\tNo Clients Available In the System!";
            else

                for (ClsBankClient Client : vClients)
                {
                    PrintClientRecordBalanceLine(Client);
                    cout << endl;
                }

            cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
            cout << "__________________________\n" << endl;

            cout << setw(8) << left << "" << "\t\t\t\t\t\t\t     Total Balances = " << TotalBalances << endl;
            cout << setw(8) << left << "" << "\t\t\t\t  ( " << ClsUtil::NumberToText(TotalBalances) << ")";
        }

  


};

