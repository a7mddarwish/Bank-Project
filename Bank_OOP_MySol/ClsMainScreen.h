#pragma once
#include<iostream>
#include"ClsHeaderScreen.h"
#include"ClsShowClientList.h"
#include"ClsAddNewClient.h"
#include "ClsDeleteClient.h"
#include "ClsUpdateClientScreen.h"
#include"ClsFindClient.h"
#include"ClsTransActionMenu.h"
#include"ClsUsersScreen.h"
#include "ClsShowRegisterscr.h"


class ClsMainScreen : protected ClsHeaderScreen
{
	enum EnMainMenuCh {
		enshowclients = 1, enAdd = 2, enDelete = 3, enUpdate = 4, enFind = 5
		, enTransActions = 6, enManage = 7, enRegsterscr =8,enLogout = 9
	};
	static void _ShowAddScreen()
	{
		//cout << "\t\t\tAdd screen will be here...\n";
		ClsAddNewClient::ShowAddNewClient();
	}
	static void _ShowUpdateScreen()
	{
		//cout << "\t\t\tUpdate screen will be here...\n";
		ClsUpdateClientScreen::UpdateClient();
	}
	static void _ShowDeleteScreen()
	{
		//cout << "\t\t\tDelete screen will be here...\n";
		ClsDeleteClient::DeleteCliete();

	}
	static void _ShowClientsScreen()
	{
		//cout << "\t\t\tClients screen will be here...\n";
		ClsShowClientList::PrintClientsData();

	}
	static void _ShowFindClientScreen()
	{
		//cout << "\t\t\tFind Client screen will be here...\n";
		ClsFindClient::FindClient();
	}
	static void _ShowTransActionsScreen()
	{
		//cout << "\t\t\tTransActions screen will be here...\n";
		ClsTransActionMenu::PrintTransActionMenu();
	}
	static void _ShowManageUsersScreen()
	{
		//cout << "\t\t\tManage Users screen will be here...\n";
	
		ClsUsersScreen::PrintMangeUserMenu();
	}

	static void _ShowRegisterScreen()
	{
		//cout << "\t\t\tShow Regster login  screen will be here...\n";

		ClsShowRegisterscr::ShowRegLogScreen();
	}
	

	static void _Logout()
	{
	CurrentUser = ClsUsers::Find("","");
	}

	static void _GoBackToMainMenu()
	{
		cout << "\nPress any key to go back to main menu...";
		system("pause>0");
		PrintMainMenu();

	}
	static void _PerformMainMenu(EnMainMenuCh choice)
	{
		switch (choice)
		{
		case EnMainMenuCh::enshowclients:
		{
			_ShowClientsScreen();
			_GoBackToMainMenu();
			break;
		}
		case EnMainMenuCh::enAdd:
		{
			_ShowAddScreen();
			_GoBackToMainMenu();
			break;
		}
		case EnMainMenuCh::enDelete:
		{
			_ShowDeleteScreen();
			_GoBackToMainMenu();
			break;
		}
		case EnMainMenuCh::enUpdate:
		{
			_ShowUpdateScreen();
			_GoBackToMainMenu();
			break;
		}
		case EnMainMenuCh::enFind:
		{
			_ShowFindClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case EnMainMenuCh::enTransActions:
		{
			_ShowTransActionsScreen();
			PrintMainMenu();

		
			break;
		}
		case EnMainMenuCh::enManage:
		{
			_ShowManageUsersScreen();
			PrintMainMenu();

			break;
		}
		case EnMainMenuCh::enRegsterscr:
		{
			_ShowRegisterScreen();
			_GoBackToMainMenu();

			break;

		}

		case EnMainMenuCh::enLogout:
		{
			system("cls");
			_Logout();
			break;
		}


		}
	}

public :
	static void PrintMainMenu()
	{
		system("cls");
		_ShowHeaderScreen("Main Menu");
		cout << "\t\t\t===============================================================\n";
		cout << "\t\t\t\t\t\tMain menu\n";
		cout << "\t\t\t===============================================================\n";

		cout << "\t\t\t\t\t[1]   Show Client List.\n";
		cout << "\t\t\t\t\t[2]   Add New Client.\n";
		cout << "\t\t\t\t\t[3]   Delete Client.\n";
		cout << "\t\t\t\t\t[4]   Update client.\n";
		cout << "\t\t\t\t\t[5]   Find Client.\n";
		cout << "\t\t\t\t\t[6]   Transactions.\n";
		cout << "\t\t\t\t\t[7]   Manage Users. \n";
		cout << "\t\t\t\t\t[8]   Register Login screen. \n";
		cout << "\t\t\t\t\t[9]   Logout.\n";
		cout << "\t\t\t===============================================================\n";

		cout << "Please Enter your choice : ";
		short Choice = ClsInputValidate::ReadNumberBetween(1, 9, "Please enter number between 1 to 9");
		_PerformMainMenu((EnMainMenuCh) Choice);
	}



};

