#pragma once

#include <iostream>
#include "ClsHeaderScreen.h"
#include "ClsUsers.h"
#include <iomanip>
#include "Global.h"
#include "ClsMainScreen.h"

class ClsLoginScreen :protected ClsHeaderScreen
{

private:
     
    static  bool _Login()
    {
       
        bool LoginFaild = false;
         short TryTimes =0;

        string Username, Password;
        do
        {
            
            if (LoginFaild)
            {
                cout << "\nInvlaid Username/Password!\n";
                TryTimes++;
                cout << "You have [" << (3 - TryTimes) << "] of trails .\n";
            }

            if (TryTimes == 3)
            {
                cout << "\n\nthe system is locked , you tried three times uncorrectly .";
                return false;
            }


            cout << "\nEnter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = ClsUsers::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);

        CurrentUser.SaveLogUserinReg();
        ClsMainScreen::PrintMainMenu();
  
        return true;
    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _ShowHeaderScreen("Login Screen");
        return   (_Login()) ;
       

    }

};

