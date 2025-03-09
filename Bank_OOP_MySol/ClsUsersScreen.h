#pragma once
#include <iostream>
#include "ClsHeaderScreen.h"
#include "ClsInputValidate.h"
#include "ClsListUsersScreen.h"
#include"ClsAddNewUser.h"
#include"ClsDeleteUser.h"
#include"ClsUpdateUser.h"
#include "ClsFindUser.h"

class ClsUsersScreen : protected ClsHeaderScreen
{
	enum EnChoiceMngscrn
	{
		enListUsers = 1,
		enAddNewUser = 2,
		enDeleteUser = 3,
		enUpdateUser = 4,
		enFindUser = 5,
		enMainMenu = 6

	};

	static void _GoBackToUsersMenu()
	{
		_PauseScreen("Users");
		PrintMangeUserMenu();
	}

	//Create stubs
	static void _ListUsersScreen()
	{
		cout << "List Users screen will be here...\n";
		ClsListUsersScreen::ShowUsersList();
	}
    static void _Addnewuser()
	{
		//cout << "Add new User screen will be here...\n";
	     ClsAddNewUser::AddNewUser();

	}
	static void _DeleteUser()
	{
		//cout << "Delete User screen will be here...\n";
		ClsDeleteUser::DeleteUser();

	}
    static void _UpdateUser()
	{
	//	cout << "Update User information screen will be here...\n";
		ClsUpdateUser::UpdateUserData();


	}
	
	static void _FindUser()
	{
		//cout << "Find User screen will be here...\n";
	ClsFindUser::FindUser();

	}


	static void _PerformusersScreen(EnChoiceMngscrn Choice)
	{
		system("cls");

		switch (Choice)
		{
		case EnChoiceMngscrn::enListUsers:
		{
			_ListUsersScreen();
			_GoBackToUsersMenu();
			break;
		}
		case EnChoiceMngscrn::enAddNewUser:
		{
			_Addnewuser();
			_GoBackToUsersMenu();
			break;

		}

		case EnChoiceMngscrn::enDeleteUser:
		{
			_DeleteUser();
			_GoBackToUsersMenu();
			break;

		}
		case EnChoiceMngscrn::enUpdateUser:
		{
			_UpdateUser();
			_GoBackToUsersMenu();
			break;


		}
		case EnChoiceMngscrn::enFindUser:
		{
			_FindUser();
			_GoBackToUsersMenu();
			break;


		}
		case EnChoiceMngscrn::enMainMenu:
		{

		}


		}
	}

public :
	static void PrintMangeUserMenu()
	{
		if (!CheckAcessToGo(ClsUsers::enPermission::pMangeUsers))
		{
			cout << "Press any key to go to main menu... \n";
			system("pause>0");
			return;
		}
		
		system("cls");
		_ShowHeaderScreen("Mange Users screen");

		cout << "\t\t\t==================================";
		cout << "==================================\n";
		cout << "\t\t\t\t\t\t Mange users screen\n";
		cout << "\t\t\t==================================";
		cout << "==================================\n";

		cout << "\t\t\t\t [1] List users. \n";
		cout << "\t\t\t\t [2] Add user. \n";
		cout << "\t\t\t\t [3] Delete user.  \n";
		cout << "\t\t\t\t [4] Update user.  \n";
		cout << "\t\t\t\t [5] Find user.  \n";
		cout << "\t\t\t\t [6] Main menu. \n";
		cout << "\t\t\t==================================";
		cout << "==================================\n";


		cout << "Enter your choice : ";
		short Choice = ClsInputValidate::ReadNumberBetween(1,6);

		_PerformusersScreen((EnChoiceMngscrn)Choice);
	}
	
};

