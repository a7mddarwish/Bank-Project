#pragma once
#include<iostream>
#include"ClsBankClient.h"
#include"ClsHeaderScreen.h"
#include"ClsInputValidate.h"
class ClsTransfer : protected ClsHeaderScreen
{

private :
	static void _PrintUserCard(ClsBankClient Client)
	{
		cout << "\t______________________\n";
		cout << "\t     User Card : \n";
		cout << "\t______________________\n";

		cout << "\n\tClient Name  : " <<  Client.FullName();
		cout << "\n\tAcc. Number :" << Client.GetAccountNumber();
		cout << "\n\tBalance : " << Client.Balance;
		cout << "\n\t______________________\n\n";

	}

	static float _GetBalance(ClsBankClient FromClient)
	{
		float Balance = 00;

		cout << "\nEnter trnsfered amount : ";
		Balance = ClsInputValidate::ReadRecord <float> ();

		if  (Balance > FromClient.Balance)
		{
			cout << "Amount excedes the avilable balance , please enter amount less than the first amount : ";
			Balance = ClsInputValidate::ReadRecord <float> ();
		}

		return Balance;
	}

	

	


public:

	static void  TransferMoney()
	{
		_ShowHeaderScreen("Transfer screen");
		string AccNom1, AccNom2;

		cout << "\n\nEnter account number of account that you want to transfeer from : ";
		AccNom1 = ClsInputValidate::ReadString();


		while (!ClsBankClient::IsCLientExist(AccNom1))
		{
			cout << "This Client is not here .\n please enter another account number : ";
			AccNom1 = ClsInputValidate::ReadString();
		}

		ClsBankClient FromClient = ClsBankClient::Find(AccNom1);
		_PrintUserCard(FromClient);


		cout << "\nEnter account number of account that you want to transfeer To : ";
		cin >> AccNom2;


		while (!ClsBankClient::IsCLientExist(AccNom2))
		{
			cout << "This Client is not here , please enter another account number : ";
			cin >> AccNom2;
		}

		ClsBankClient ToClient = ClsBankClient::Find(AccNom2);
		_PrintUserCard(ToClient);
		
		float Balance = _GetBalance(FromClient);
		
		char Answer = 'n';
		cout << "are you want to perform this operation [y/n] : ";
		cin >> Answer;

		if (toupper(Answer) == 'N')
		{
			cout << "Ok , process faild.  ";
			return;
		}

		if (FromClient.Transfeer(Balance, ToClient))

		{
			cout << "\tTransfer  done sucsesfully :-)\n";
			_PrintUserCard(FromClient);
			_PrintUserCard(ToClient);
		}

		else
		{
			cout << "Process faild.  ";

		}

		




	}

};

