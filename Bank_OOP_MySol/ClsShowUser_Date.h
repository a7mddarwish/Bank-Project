#pragma once
#include<iostream>
#include "ClsDate.h"
#include "Global.h"
class ClsShowUser_Date
{
private :
	static string _GetSystemDate()
	{
		ClsDate Date = ClsDate::GetSystemDate();

		string StDate = " ";
		StDate+= to_string(Date.GetDay() )+ "/";
		StDate +=to_string(Date.GetMonth()) + "/";
		StDate +=to_string(Date.GetYear());

		return StDate;
	}
public:
	static void ShowCrntDate_User()
	{
		cout << "\t\t\t User : " << CurrentUser.Username;
		cout << "\t\t\t Date : " << _GetSystemDate() << endl;
		
		

	}
};

