#pragma once
#include <iostream>
#include<vector>
#include"ClsUsers.h"
#include "ClsHeaderScreen.h"

class ClsDeleteUser : protected ClsHeaderScreen
{
	static void _GetMptyUser(ClsUsers& User)
	{
		User = ClsUsers::GetEmptyObj();
	}
	static void _PrintUserCard(ClsUsers User)
	{
		
		cout << "\n\t\t------------------------\n";
		cout << "\t\t\tUser Card \n";
		cout << "\t\t------------------------\n";
		cout << "\t\tFirst name : " << User.FirstName;
		cout << "\n\t\tLast name  : " << User.LastName;
		cout << "\n\t\tFull Name  : " << User.FullName();
		cout << "\n\t\tEmail      : " << User.Email;
		cout << "\n\t\tPhone      : " << User.Phone;
		cout << "\n\t\tPin code   : " << User.PinCode;
		cout << "\n\t\tPermission : " << User.Permission;
		cout << "\n\t\t------------------------\n";

	}

public :
	static void DeleteUser()
	{
		_ShowHeaderScreen("Delete User screen");
		cout << "Enter username : ";
		string UserName = ClsInputValidate::ReadString();

		while (!ClsUsers::IsUserExist(UserName))
		{
			cout << "This user is not here , please enter another user name : ";
			UserName = ClsInputValidate::ReadString();
		}
		ClsUsers User = ClsUsers:: Find(UserName);
		
		_PrintUserCard(User);

		char Answer = 'n';

		cout << "Do you want to delete this User ? [y/n] : ";
		cin >> Answer;

		system("cls");


		if (toupper(Answer) == 'Y')
		{
         
			switch  (User.Delete())

			{
			case  ClsUsers::enDeleteCase::enDeletedDone:
			{
				cout << "\nUser deleted sucssefully :-)\n";
				_PrintUserCard(User);

			}

			case ClsUsers::enDeleteCase::enDeletefaild:
			{
				cout << "\nOk , user doese not deleted :-) \n";
				_PrintUserCard(User);

			}

			case ClsUsers::enDeleteCase::enfaildAdmin:
			{
				cout << "\nYou  can not Delete Admin !! \n";
				
			}

			}
		}
		


		
	}

};

