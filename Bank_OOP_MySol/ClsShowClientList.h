#pragma once
#include<iostream>
#include <iomanip>
#include "ClsBankClient.h"
#include"ClsHeaderScreen.h"
//#include"CrntUser.h"

class ClsShowClientList : protected ClsHeaderScreen
{
protected:

	static void _PrintClientRecordLine(ClsBankClient Client)
	{
		cout << "| " << left << setw(15) << Client.GetAccountNumber();
		cout << "| " << left << setw(20) << Client.FullName();
		cout << "| " << left << setw(20) << Client.Email;
		cout << "| " << left << setw(12) << Client.Phone;
		cout << "| " << left << setw(10) << Client.Pincode;
		cout << "| " << left << setw(20) << Client.Balance;

	}
	static void _TheHead()
	{
		cout << "\n\n\t--------------------------------------------";
		cout <<"-----------------------------------------------------\n";
		cout << "\t| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(0) << "Balance\n";
		cout << "\t--------------------------------------------------------";
		cout <<"-----------------------------------------\n\n";

	}

public :
	static void PrintClientsData()
		{
		if (!CheckAcessToGo(ClsUsers::enPermission::pShowList))
		{
			return;
		}
		 
			vector <ClsBankClient> Vclients = ClsBankClient::GetClientsList();
			
			// Define Titel and sub titel
			string _Titel = "Client List ", _SubTitel;
		    _SubTitel = "[ " + to_string(Vclients.size()) + " ] of client(s)";
		
			_ShowHeaderScreen(_Titel, _SubTitel);
			_TheHead();
			
		
			if (Vclients.size() == 0)
				cout << "Sorry , Client List is Empty.";
			else
			{
				for (ClsBankClient Client : Vclients)
				{
				
						cout << "\t";
						_PrintClientRecordLine(Client);
						cout << "\n";
					

				}
			}
			cout << "\n\n\t----------------------------------------------------"
			"---------------------------------------------\n\n";
		
		
		}

};

