
#pragma once
#include <iostream>
#include "ClsHeaderScreen.h"
#include "ClsInputValidate.h"
#include "ClsBankClient.h"

class ClsDeleteClient : private ClsHeaderScreen
{
private :
	static string _GetAccountNumber()
	{
		string _AccountNumber;
		cout << "Enter Account Number : ";
		_AccountNumber = ClsInputValidate::ReadString();


		while (!ClsBankClient::IsCLientExist(_AccountNumber))
		{
			cout << "Client dosent exist please enter another account number : ";
			_AccountNumber = ClsInputValidate::ReadString();
		}
		return _AccountNumber;
    }  
	static void Print(ClsBankClient Client)
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

public :

	static void DeleteCliete()
	{
		if (!CheckAcessToGo(ClsUsers::enPermission::pDelete))
		{
			return;
		}
		
		 _ShowHeaderScreen("Delete clinet Screen");
		string _AccountNumber = _GetAccountNumber();

		ClsBankClient Client = ClsBankClient::Find(_AccountNumber);
		Print(Client);

		char Answer = 'n';
		cout << "\nDo you want to delete this account ? [y/n] : ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Client.DeleteClient();
			system("cls");
			cout << "\nClient deleted sucsesfully. \n";
			Print(Client);
		}
		else
			cout << "\nOk , client dosent deleted. \n";

	}
};

