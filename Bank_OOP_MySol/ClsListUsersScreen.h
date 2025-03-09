#pragma once
#include <iostream>
#include<vector>
#include<iomanip>
#include"ClsUsers.h"
#include"ClsHeaderScreen.h"
class ClsListUsersScreen : protected  ClsHeaderScreen
{

	static void _PrintUserInfo(ClsUsers User)
	{
	 cout << "\t | " << left << setw(9)<< User.Username;
		cout << " | " << left << setw(20) <<User.FullName();
		cout << " | " << left << setw(12) << User.Phone;
		cout << " | " << left << setw(27) << User.Email;
		cout << " | " << left << setw(10) << User.PinCode;
		cout << " | " << left << setw(10) << User.Permission;

	}
public :
	static void ShowUsersList()
	{
	
		vector <ClsUsers> Users = ClsUsers::_LoadUsersFromFile();
		string SubTitel = "[" + to_string(Users.size()) + "] User(s) ";

		_ShowHeaderScreen("Users Screen", SubTitel);

		cout << setw(8) << left << " " << "=====================================================";
		cout << "==================================================== \n";
		cout << "\t | "  << left << setw(9) << "UserName";
		cout << " | "  << left<< setw(20) << "Full Name";
		cout << " | "  << left<< setw(12) << "Phone";
		cout << " | "  << left<< setw(27) << "Email";
		cout << " | "  << left<< setw(10) << "Password";
		cout << " | "  << left<< setw(10) << "Permission\n";

		cout << setw(8) << left << " " << "=====================================================";
		cout << "==================================================== \n";

		for (ClsUsers& U : Users )
		{
			_PrintUserInfo(U);
			cout << endl;
		}
		cout << setw(8) << left << " " << "=====================================================";
		cout << "==================================================== \n";

		
	}

};

