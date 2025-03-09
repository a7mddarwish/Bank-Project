#pragma once
#include <iostream>
#include<vector>
#include "ClsUsers.h"
#include "ClsHeaderScreen.h"
class ClsUpdateUser	: protected ClsHeaderScreen

{
private :
	// Update 
	static int _GetPermission()
	{
		char Answer;
		int Per = 0;

		cout << "Do you want to give him all access ? [Y/N] : ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
			return -1;


		cout << "Do you want to give him access to :  [Answer with Y or N ]\n\n";

		cout << "Show Clients list : ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
			Per += ClsUsers::enPermission::pShowList;

		cout << "Add New Client : ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
			Per += ClsUsers::enPermission::pAddNew;

		cout << "Delete Client : ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
			Per += ClsUsers::enPermission::pDelete;

		cout << "Update client : ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
			Per += ClsUsers::enPermission::pUpdate;

		cout << "Find Client : ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
			Per += ClsUsers::enPermission::pFind;


		cout << "Transactions : ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
			Per += ClsUsers::enPermission::pTransAction;

		cout << "Manage Users : ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
			Per += ClsUsers::enPermission::pMangeUsers;
		
		cout << " Register screen : ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
			Per += ClsUsers::enPermission::pRegisterScr;




		return Per;

	}
	 static void _Update(ClsUsers & User)
	{
		User.Mode = ClsUsers::enMode::Updated;

		cout << "\nEnter Fisrt Name : ";
		User.FirstName = ClsInputValidate::ReadString();

		cout << "\nEnter Last Name : ";
		User.LastName = ClsInputValidate::ReadString();

		cout << "\nEnter Email : ";
		User.Email = ClsInputValidate::ReadString();

		cout << "\nEnter Phone : ";
		User.Phone = ClsInputValidate::ReadString();

		cout << "\nEnter Pincode : ";
		User.PinCode = ClsInputValidate::ReadString();

		char Answer = 'n';
		cout << "\nDo you want to give this user all permission ? [y/n] : ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
			User.Permission = -1;
		else
		{
			User.Permission = _GetPermission();
		}
		
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

	static void UpdateUserData()
	{
		_ShowHeaderScreen("Update User screen");
		cout << "Enter username : ";
		string UserName = ClsInputValidate::ReadString();

		while (!ClsUsers::IsUserExist(UserName))
		{
			cout << "This user is not here , please enter another user name : ";
			UserName = ClsInputValidate::ReadString();
		}
		ClsUsers User = ClsUsers::Find(UserName);
		_PrintUserCard(User);

		char Answer = 'n';

		cout << "Do you want to Update this User data ? [y/n] : ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			
			_Update(User);
			User.Save();
			cout << "Data from user updated sucsessfully :-) \n";
		}
		else
			cout << "Ok , Old data still here \n";

		system("cls");
		_PrintUserCard(User);


	}
};

