#pragma once
#include <iostream>
#include "ClsInputValidate.h"
#include "ClsBankClient.h"

using namespace std;

class ClsAddNewClient : protected ClsHeaderScreen
{
	static void _ReadClientInfo(ClsBankClient& Client)
	{
		cout << "\nEnter First name : ";
		Client.FirstName = ClsInputValidate::ReadString();

		cout << "Enter Last name : ";
		Client.LastName = ClsInputValidate::ReadString();

		cout << "Enter Email : ";
		Client.Email = ClsInputValidate::ReadString();

		cout << "Enter Phone : ";
		Client.Phone = ClsInputValidate::ReadString();

		cout << "Enter new password : ";
		Client.Pincode = ClsInputValidate::ReadRecord<string>();

		cout << "Enter new balance  : ";
		Client.Balance = ClsInputValidate::ReadRecord<double> ();





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

public:

	static void ShowAddNewClient()
	{
	  if (!CheckAcessToGo(ClsUsers::enPermission::pAddNew))
		{
			return;
		}
		
		_ShowHeaderScreen("Add New Client");
		cout << "Please enter account number : ";
		string AccountNumber = ClsInputValidate::ReadString();

		while (ClsBankClient::IsCLientExist(AccountNumber))
		{
			cout << "this account number " << AccountNumber <<
				" is already exist , please enter anther account Number : ";

			AccountNumber = ClsInputValidate::ReadString();

		}
		ClsBankClient NewClient = ClsBankClient::AddClient(AccountNumber);

		_ReadClientInfo(NewClient);

		ClsBankClient::enAcsessToSave SaveState;

		SaveState = NewClient.Save();

		switch (SaveState)
		{
		case ClsBankClient::enAcsessToSave::SaveSucsseded:
		{
			cout << "Client Add sucssfully :-)\n";
			break;
		}
		case ClsBankClient::enAcsessToSave::SaveFailedClientEmpty:
		{
			cout << "Client dosent add because is empty \n";
			break;

		}
		case ClsBankClient::enAcsessToSave::SaveFailedClientExist:
		{
			cout << "Client dosent add because is Exist \n";
			break;


		}

		}


	}

};

