#pragma once
#include<iostream>
#include<iomanip>
#include"ClsHeaderScreen.h"
#include "ClsUsers.h"
#include"ClsString.h"

class ClsShowRegisterscr : protected ClsHeaderScreen
{
private :

	static void _PrintUserData(ClsUsers::StRegisterLogin UserSt )
	{
		
		cout << "\t| " << left << setw(35) <<UserSt.DateandTime;
		cout << "\t| " << left << setw(20) <<UserSt.Username;
		cout << "\t| " << left << setw(20) <<UserSt.Passwotd;
		cout << "\t| " << left << setw(20) <<UserSt.Permission;
	}

	static void _PrintHeader()
	{
		cout << "\n\n\t-------------------------------------------------";
		cout << "-----------------------------------------------------\n";

		cout << "\t| " << left << setw(35) << "Date / Time ";
		cout << "\t| " << left << setw(20) << "Username ";
		cout << "\t| " << left << setw(20) << "Password ";
		cout << "\t| " << left << setw(20) << "Permission \n";
		cout << "-------------------------------------------------";
		cout << "-----------------------------------------------------\n";
	}
public :
	static void ShowRegLogScreen()
	{
		if (!CheckAcessToGo(ClsUsers::enPermission::pRegisterScr))
		{
			return;
		}
		vector <ClsUsers::StRegisterLogin> UsersData = ClsUsers::ShowRegUsers();

		string Titel = "Login register list screen .";
		string Subtitle = "(" + to_string(UsersData.size()) + ") Record(s) .";
		_ShowHeaderScreen(Titel, Subtitle);
		
		_PrintHeader();

		for (ClsUsers::StRegisterLogin UserSt : UsersData)
		{
			_PrintUserData(UserSt);
			cout << endl;
			
		}
		cout << "\n\n\t-------------------------------------------------";
		cout << "-----------------------------------------------------\n";
	}

};

