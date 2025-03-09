
#pragma once
#include<iostream>
#include "ClsHeaderScreen.h"
#include "ClsInputValidate.h"
#include "ClsBankClient.h"
#include"ClsDeposit.h"
#include"ClsWithdrawn.h"
#include "ClsTransfer.h"
#include "ClsShowTransProcess.h"
#include "clsTotalBalancesScreen.h"

class ClsTransActionMenu : protected ClsHeaderScreen
{
private :
	enum EnTransOption
	{
		enDeposti = 1, enWithdraw = 2, enTotalbalances = 3,
		enTransfer =4, enTransProc =5, Gotomaimenu = 6
	};

	static void _Deposit()
	{
		//cout << "Deposit screen will be here...\n";
		ClsDeposit::Depoiste();
	}
	static void _Withdraw()
	{
	//	cout << "Withdraw screen will be here...\n";
		ClsWithdrawn::Withdrawn();
	}
	static void _ToatlBalances()
	{
		//cout << "Toatl balances screen will be here...\n";
		clsTotalBalancesScreen::ShowTotalBalances();
	}
	static void _mainmenu()
	{
		cout << "main menu screen will be here...\n";
	}
	static void _Transfer()
	{
		//cout << "Transfer screen will be here...";
		ClsTransfer::TransferMoney();

	}
	static void _TransferProc()
	{
		//cout << "Transfer process will be here ...";
		ClsShowTransProcess::ShewTransferProcess();
	}



	static void _GoBackToTransActionMenu()
	{
		
		cout << "\nPress any key to go back to main menu...";
		system("pause>0");
		PrintTransActionMenu();

	}

	static void _PerformTransAction(EnTransOption Choice)
	{
		system("cls");
		switch (Choice)
		{
		case EnTransOption::enDeposti:
		{
			system("cls");
			_Deposit();
			_GoBackToTransActionMenu();
			break;
		}

		case EnTransOption::enWithdraw:
		{
			system("cls");
			_Withdraw();
			_GoBackToTransActionMenu();
			break;

		}
		case EnTransOption::enTotalbalances:
		{
			system("cls");
			_ToatlBalances();
			_GoBackToTransActionMenu();
			break;

		}
		case EnTransOption::enTransfer:
		{
			_Transfer();
			_GoBackToTransActionMenu();

			break;

		}
			case EnTransOption::enTransProc:
		{
			_TransferProc();
			_GoBackToTransActionMenu();

			break;

		}
		

		case EnTransOption::Gotomaimenu:
		{
		}


		}
	}
	
public :

	static void PrintTransActionMenu()
	{
		if (!CheckAcessToGo(ClsUsers::enPermission::pTransAction))
		{
			 cout << "Press any key to go to main menu... \n";
			 system("pause>0");
			return;
		}
		_ShowHeaderScreen("Transaction screen");

		cout << "\t\t\t===============================================================\n";
		cout << "\t\t\t\t\t\Transaction menu\n";
		cout << "\t\t\t===============================================================\n";

		cout << "\t\t\t\t\t[1]   Deposit.\n";
		cout << "\t\t\t\t\t[2]   Withdraw.\n";
		cout << "\t\t\t\t\t[3]   Total balances.\n";
		cout << "\t\t\t\t\t[4]   Transfer.\n";
		cout << "\t\t\t\t\t[5]   Transfer Log.\n";
		cout << "\t\t\t\t\t[6]   Main menu.\n\n";
		cout << "\t\t\t===============================================================\n";



		cout << "Please enter your choice : ";
		short Choice = ClsInputValidate::ReadNumberBetween<short>(1, 6, "Please enter number betweem 1 to 6");
		_PerformTransAction((EnTransOption)Choice);
	}

};

