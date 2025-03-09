#pragma once
#include <iostream>
#include "ClsHeaderScreen.h"
#include "ClsInputValidate.h"
#include "ClsBankClient.h"


class ClsFindClient : private ClsHeaderScreen
{
private :
	static void _Print(ClsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.GetAccountNumber();
		cout << "\nPassword    : " << Client.GetPincode();
		cout << "\nBalance     : " << Client.GetBalance();
		cout << "\n___________________\n";

	}


public:
	static void FindClient()
	{
		if (!CheckAcessToGo(ClsUsers::enPermission::pFind))
		{
			return;
		} 
		// Header
		_ShowHeaderScreen("Find client screen");

		//Get AaccountNumber
		string _AccountNumber = "";
		cout << "Please enter client account number : ";
		_AccountNumber = ClsInputValidate::ReadString();

		//Get the client
		ClsBankClient Client = ClsBankClient::Find(_AccountNumber);

		_Print(Client);


	}
};

