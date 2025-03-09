#pragma once
#include<iostream>
#include "ClsHeaderScreen.h"
#include "ClsInputValidate.h"
#include "ClsBankClient.h"


class ClsUpdateClientScreen : protected  ClsHeaderScreen
{
private :
	static void _ReadClientInfo(ClsBankClient& Client)
	{
		cout << "\nEnter First name : ";
		Client.FirstName = ClsInputValidate::ReadRecord<string>();

		cout << "Enter Last name : ";
		Client.LastName = ClsInputValidate::ReadRecord<string>();

		cout << "Enter Email : ";
		Client.Email = ClsInputValidate::ReadRecord<string>();

		cout << "Enter Phone : ";
		Client.Phone = ClsInputValidate::ReadRecord<string>();

		cout << "Enter new password : ";
		Client.Pincode = ClsInputValidate::ReadRecord<string>();

		cout << "Enter new balance  : ";
		Client.Balance = ClsInputValidate::ReadRecord<double> ();

	}
	static void _Print(ClsBankClient Client , string State)
	{
		cout << "\nClient Card "<<State <<" Update :";
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
	static void UpdateClient()
	{  
		if (!CheckAcessToGo(ClsUsers::enPermission::pUpdate))
		{
			return;
		}
		_ShowHeaderScreen("Update client screen");

		string _AccountNumber = "";
		cout << "Please enter client account number : ";
		_AccountNumber = ClsInputValidate::ReadString();

		while (!ClsBankClient::IsCLientExist(_AccountNumber))
		{
			printf("Clinet with Account number [%s] isn't exist , please enter a correct account number : "
				, _AccountNumber);
			_AccountNumber = ClsInputValidate::ReadString();


		}
		ClsBankClient Client = ClsBankClient::Find(_AccountNumber);
		_Print(Client, "befor");
		char Answer = 'n';

		cout << "Do you want to update this client data ? [y/n] : ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{

			system("cls");
			cout << "\t\t\tUpdate Client Information : \n";
			_ReadClientInfo(Client);

			ClsBankClient::enAcsessToSave SaveAcsess;
			SaveAcsess = Client.Save();

			switch (SaveAcsess)
			{
			case ClsBankClient::SaveSucsseded:
				_Print(Client, "after");

				cout << "Cilete up to date sucssefuly :-) \n";
				break;
			case ClsBankClient::SaveFailedClientEmpty:
				cout << "Client data doese not updated becuase the client is empy . \n";
				break;

			}
		}
		else
		{
			cout << "Then old data still here :-). \n";
		}


	}
};

