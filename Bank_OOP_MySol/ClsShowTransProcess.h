#pragma once
#include<iostream>
#include"ClsHeaderScreen.h"
#include "ClsBankClient.h"
class ClsShowTransProcess : protected ClsHeaderScreen
{
private :

	static void _PrintProccesData(ClsBankClient::stTransfeerElements St)
	{
		cout << "\t| " << left << setw(23) << St.DateTime;
		cout << "| " << left << setw(8) << St.SaccountNom;
		cout << "| " << left << setw(8) << St.DaccountNom;
		cout << "| " << left << setw(12) << St.Amount;
		cout << "| " << left << setw(12) << St.NewSBalance;
		cout << "| " << left << setw(12) << St.NewDBalance;
		cout << "| " << left << setw(8) << St.Username;

	}
	static void _PrintHeader()
	{
		cout << "\n\n\t--------------------------------------------------------";
		cout << "-----------------------------------------------------\n";
		cout << "\t| " << left << setw(23) <<"Data / time ";
		cout << "| " << left << setw(8) << "S.Acc.";
		cout << "| " << left << setw(8) << "D.Acc.";
		cout << "| " << left << setw(12) <<"Trs.Amount";
		cout << "| " << left << setw(12) << "S.Balance";
		cout << "| " << left << setw(12) << "D.Balance";
		cout << "| " << left << setw(8) << "Username";
		cout << "\n\t-------------------------------------------------";
		cout << "------------------------------------------------------------\n";
	}

public :

	static void ShewTransferProcess()
	{
		vector < ClsBankClient::stTransfeerElements> VProcess = ClsBankClient::_LoadProcessFromFile();
		string subTitle = "( "+ to_string(VProcess.size()) + " ) Record(s) .";

		_ShowHeaderScreen("Transfer Process" , subTitle);

		_PrintHeader();

		for (ClsBankClient::stTransfeerElements Process : VProcess)
		{
			_PrintProccesData(Process);
			cout << endl;
		}

		cout << "\n\n\t-------------------------------------------------";
		cout << "------------------------------------------------------------\n";
	}
};

