#pragma once
#include<iostream>
#include"ClsHeaderScreen.h"
#include "ClsInputValidate.h"
#include "ClsBankClient.h"
class ClsWithdrawn : private ClsHeaderScreen
{
private:
	static void _Print(ClsBankClient Client, string State)
	{
		cout << "\nClient Card " << State << " Update :";
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
	static double _GetAmount()
	{
		cout << "Please , Enter the balance what do you want to withdraw : ";
		double balance = ClsInputValidate::ReadRecord <double > ();
		return balance;
	}

public :

	static void Withdrawn()
	{

		_ShowHeaderScreen("Withdrawn screen");

		string _AccountNumber = "";
		cout << "Please enter client account number : ";
		_AccountNumber = ClsInputValidate::ReadString();

		while (!ClsBankClient::IsCLientExist(_AccountNumber))
		{
			cout << "Clinet with Account number [" << _AccountNumber << "] isn't exist , please enter a correct account number : ";
			_AccountNumber = ClsInputValidate::ReadString();
		}

		ClsBankClient Client = ClsBankClient::Find(_AccountNumber);
		_Print(Client, "befor");

		double Balance = _GetAmount();

		if (Balance > Client.Balance)
		{
			cout << "Cannot withdraw balance dosent enough ";
			cout << "\nyour balance is :  " << Client.Balance;
			cout << "\nAmount whitdrawn is :  " << Balance;

		}

		else
		{
			char Choice = 'n';
			cout << "Are you sure to withdraw that amount ? [y/n]";
			cin >> Choice;
			if (toupper(Choice) == 'Y')
			{


				if (Client.WhitDraw(Balance))
					cout << "New Balance is : " << Client.Balance << endl;
				else
					cout << "prosess ended sucsessfully \n";

				_PauseScreen("Trasaction");
			}
		}
	}
};

