#pragma once
#include <iostream>
#include<vector>
#include"ClsUsers.h"
#include "ClsHeaderScreen.h"

class ClsAddNewUser : protected ClsHeaderScreen
{
	static int _GetPermission()
	{
		char Answer;
		int Per = 0;

		cout << "Do you want to give him access to :  [Answer with y or n ]\n\n";

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
	 static void _Update(ClsUsers& User)
	{
		// User.Mode = ClsUsers::enMode::Updated;

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

public :

	static void AddNewUser()
	{
		_ShowHeaderScreen("Add New User");
		string UserName;

		cout << "Please Enter New username : ";
		UserName = ClsInputValidate::ReadString();
		while (ClsUsers::IsUserExist(UserName))
		{
			cout << "User Exist olready , please enter another user name : ";
			UserName = ClsInputValidate::ReadString();

		}

		ClsUsers NewUser = ClsUsers:: GetNewOpj(UserName);
		_Update(NewUser);

		ClsUsers::EnSaveResults SaveResult = NewUser.Save();
		switch (SaveResult)
		{
		case ClsUsers::EnSaveResults::enSaveSuccsefully:
		{
			cout << "\t\tUser Added sucsessfully \n";
			_PrintUserCard(NewUser);
			break;
		}
		case ClsUsers::EnSaveResults::enSavefaildUserexist:
		{
			cout << "\t\tfaild prosess , User is exsited \n";
			break;
		}

		case ClsUsers::EnSaveResults::enSaveFailed:
		{
			cout << "\t\tfaild prosess , User is Empty \n";
			break;
		}

		}
 
	}
};

