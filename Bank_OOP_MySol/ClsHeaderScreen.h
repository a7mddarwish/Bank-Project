#pragma once
#include<iostream>
#include"Global.h"
#include"ClsShowUser_Date.h"
using namespace std;

class ClsHeaderScreen : protected ClsShowUser_Date
{
public:
	 static void _ShowHeaderScreen(string Titel , string SubTitel ="")
	{
		 system("cls");
		cout << "\t\t\t" << "------------------------------------------------------------------\n";
		cout << "\t\t\t\t\t\t" << Titel << "\n";
		if (SubTitel != "")
		{
			cout << "\t\t\t\t\t\t" << SubTitel << "\n";

		}
		cout << "\t\t\t" << "------------------------------------------------------------------\n";

		ShowCrntDate_User();

	}
	 static void _PauseScreen(string ScreenName)
	 {
		 cout << "Please press any key to go to "<< ScreenName<<" menu...";
		 system("pause>0");
     
		 
	 }

	 static bool CheckAcessToGo(ClsUsers::enPermission Permission)
	 {
	  if (!CurrentUser.Acsess(Permission))
	  {
	 	 _ShowHeaderScreen("Acess Denied , Contact your Admin");
	 	 return false;
	  }
	  else
	  {
	 
	 	 return true;
	  }
	 } 
	
};

