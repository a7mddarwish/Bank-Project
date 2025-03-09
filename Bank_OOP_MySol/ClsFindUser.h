#pragma once
#include <iostream>
#include<vector>
#include "ClsUsers.h"
#include "ClsHeaderScreen.h"
class ClsFindUser : protected ClsHeaderScreen
{
private :
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
	static void FindUser()
	{
		_ShowHeaderScreen("Find User screen");
		cout << "Enter username : ";
		string UserName = ClsInputValidate::ReadString();

		while (!ClsUsers::IsUserExist(UserName))
		{
			cout << "This user is not here , please enter another user name : ";
			UserName = ClsInputValidate::ReadString();
		}
		ClsUsers User = ClsUsers::Find(UserName);

		if (User.IsEmpty())
		{
			cout << "User not found :-( \n";
		}
		else
		{
			cout << "User found :-) \n";

		_PrintUserCard(User);

		}

	}
};

